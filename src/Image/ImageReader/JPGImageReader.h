/*
 * JPGImageReader.h
 *
 *  Created on: 12-06-2011
 *      Author: juanin
 */
#include "ImageReader.h"

#ifndef JPGIMAGEREADER
#define JPGIMAGEREADER

class JPGImageReader : public ImageReader {
public:
	static MyImage decodeImageGray(string file);
};

#endif
