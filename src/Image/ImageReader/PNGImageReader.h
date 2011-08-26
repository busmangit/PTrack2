/*
 * PNGImageReader.h
 *
 *  Created on: 12-06-2011
 *      Author: juanin
 */
#include "ImageReader.h"

#ifndef PNGIMAGEREADER
#define PNGIMAGEREADER

class PNGImageReader : public ImageReader {
public:
	PNGImageReader();
	virtual ~PNGImageReader();

	MyImage *decodeImage(string file);
};


#endif
