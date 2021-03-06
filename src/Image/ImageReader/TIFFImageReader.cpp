/*
 * Image.h
 *
 *  Created on: 11-06-2011
 *      Author: juanin
 */
#include "TIFFImageReader.h"

/**
 *******************************
 * Constructores
 *******************************
 */
TIFFImageReader::TIFFImageReader() { }

TIFFImageReader::~TIFFImageReader() { }

/**
 *******************************
 * Metodos
 *******************************
 */
#ifdef CHI2CUDA
void *TIFFImageReader::populate(void *ptr){
	TiffPartition* part = (TiffPartition*) ptr;

	MyLogger::log()->debug("[TIFFImageReader][populate] Populating: X1=%i; X2=%i, Y1=%i, Y2=%i", part->x1, part->x2, part->y1 ,part->y2);
	Magick::ColorRGB my_color;
	for(int x = part->x1; x < part->x2; ++x)
		for(int y = part->y1; y < part->y2; ++y){
			my_color = part->mimg->pixelColor(x,y);
			part->img->at(x,y) = my_color.green();
		}
	MyLogger::log()->debug("[TIFFImageReader][populate] Populated");
	return 0;
}

void *TIFFImageReader::populateCu(void *ptr){
	TiffPartition* part = (TiffPartition*) ptr;

	MyLogger::log()->debug("[TIFFImageReader][populateCu] Populating: X1=%i; X2=%i, Y1=%i, Y2=%i", part->x1, part->x2, part->y1 ,part->y2);
	Magick::ColorRGB my_color;
	for(int x = part->x1; x < part->x2; ++x)
		for(int y = part->y1; y < part->y2; ++y){
			my_color = part->mimg->pixelColor(x,y);
			part->cuimg->atHost(x,y) = (float)my_color.green();
		}
	MyLogger::log()->debug("[TIFFImageReader][populateCu] Populated");
	return 0;
}

MyMatrix<double> TIFFImageReader::decodeRawGray(string file){
	MyLogger::log()->debug("[TIFFImageReader] Decoding TIFF Image: %s", file.c_str());
	Magick::Image my_image1, my_image2;
	my_image1.read(file);
	my_image2.read(file);

	unsigned int max_x = my_image1.rows();
	unsigned int max_y = my_image1.columns();
	MyMatrix<double> ret(max_x, max_y);

	// Parte 1
	TiffPartition p1; p1.img = &ret; p1.mimg = &my_image1;
	p1.x1 = 0;	p1.x2 = max_x/2;
	p1.y1 = 0;	p1.y2 = max_y;

	// Parte 2
	TiffPartition p2; p2.img = &ret; p2.mimg = &my_image2;
	p2.x1 = max_x/2;	p2.x2 = max_x;
	p2.y1 = 0;			p2.y2 = max_y;

	// Threads
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, populate, (void *)&p1);
	pthread_create(&thread2, NULL, populate, (void *)&p2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	MyLogger::log()->debug("[TIFFImageReader] TIFF Image Decoded");

	return ret;
}

cuMyMatrix TIFFImageReader::decodeCuRawGray(string file){
	MyLogger::log()->debug("[TIFFImageReader] Decoding TIFF Image: %s", file.c_str());
	Magick::Image my_image1, my_image2;
	my_image1.read(file);
	my_image2.read(file);

	unsigned int max_x = my_image1.rows();
	unsigned int max_y = my_image1.columns();
	cuMyMatrix ret(max_x, max_y);
	ret.copyToHost();

	// Parte 1
	TiffPartition p1; p1.cuimg = &ret; p1.mimg = &my_image1;
	p1.x1 = 0;	p1.x2 = max_x/2;
	p1.y1 = 0;	p1.y2 = max_y;

	// Parte 2
	TiffPartition p2; p2.cuimg = &ret; p2.mimg = &my_image2;
	p2.x1 = max_x/2;	p2.x2 = max_x;
	p2.y1 = 0;			p2.y2 = max_y;

	// Threads
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, populateCu, (void *)&p1);
	pthread_create(&thread2, NULL, populateCu, (void *)&p2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	ret.copyToDevice();
	ret.deallocateHost();

	MyLogger::log()->debug("[TIFFImageReader] TIFF Image Decoded");

	return ret;
}
#endif
