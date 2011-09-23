/*
 * PeaksStep.h
 *
 *  Created on: 12/09/2011
 *      Author: juanin
 */
#include "../AlgorithmStepHandler.h"
#include "../../Container/Array2D.h"
#include "../Objects_Chi2/MyPeak.h"
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>

#ifndef PEAKSSTEP
#define PEAKSSTEP

class PeaksStep: public AlgorithmStepHandler {
private:
	int _threshold;
	int _minsep;
	int _mindistance;
	Array2D<double> *chi_img;

	bool findLocalMinimum(unsigned int imgX, unsigned int imgY);
	vector<MyPeak> validatePeaks(vector<MyPeak> *peaks);
public:
	PeaksStep();
	void handleData(ParameterContainer *pc);

	void setThreshold(int threshold);
	void setMinSeparation(int minsep);
	void setMinDistance(int mindistance);
};

#endif /* PEAKSSTEP */
