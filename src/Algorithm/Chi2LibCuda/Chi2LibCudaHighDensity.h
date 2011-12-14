/*
 * Chi2LibCudaHighDensity.h
 *
 *  Created on: 13/12/2011
 *      Author: juanin
 */
#include "Container/cuMyMatrix.h"
#include "Chi2LibcuHighDensity.h"
#include "../../Utils/MyLogger.h"
#include "../Chi2LibCuda/Chi2LibCuda.h"

#ifndef CHI2LIBCUDAHIGHDENSITY_H_
#define CHI2LIBCUDAHIGHDENSITY_H_

class Chi2LibCudaHighDensity {
public:

	/**
	 * Genera una imagen aumentada, invertida y normalizada.
	 */
	static void generateScaledImage(cuMyMatrix *diff, cuMyMatrix *out);

	/**
	 * Chequea si los Peaks encontrados se ubican en el interior de la imagen y los agrega al antiguo arreglo.
	 */
	static unsigned int checkInsidePeaks(cuMyPeakArray *old_peaks, cuMyPeakArray *new_peaks, cuMyMatrix *img, unsigned int os);
};

#endif /* CHI2LIBCUDAHIGHDENSITY_H_ */