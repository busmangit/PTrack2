/*
 * MyPeak.h
 *
 *  Created on: 12/09/2011
 *      Author: juanin
 */

#ifndef MYPEAK
#define MYPEAK

class MyPeak {
public:
	int x; double px; double dpx;
	int y; double py; double dpy;
	double intensity;
	double img_intensity;
	double vor_area;
	bool solid;

	MyPeak();
	MyPeak(int x, int y);
	MyPeak(int x, int y, double intensity);

	static bool compareMe(MyPeak first, MyPeak second){
		return first.intensity < second.intensity;
	}

	static bool compareMeImg(MyPeak first, MyPeak second){
		return first.img_intensity < second.img_intensity;
	}
};

#endif /* MYPEAK */