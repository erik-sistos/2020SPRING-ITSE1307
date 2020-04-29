#pragma once
#include <iostream>
#include <string>
class swimmingPool
{
public: 
	swimmingPool();
	swimmingPool(int intpLength, int intpWidth, int intpDepth, 
				float fltInitialpWaterVolume, float fltpFillRate, float fltpDrainageRate);
	~swimmingPool();
	int getLength();
	int setLength(int intpLength);
	int getWidth();
	int setWidth(int intpWidth);
	int getDepth();
	int setDepth(int intpDepth);
	float getFillRate();
	float setFillRate(float fltpFillRate);
	float getDrainageRate();
	float setDrainageRate(float fltpDrainageRate);
	float getVolume();
	float getWaterVolume();
	float setInitialVolume(float fltInitialpWaterVolume);
	float getInitialVolume();
	int getFillTime();
	int getDrainageTime();
	std::string toString();
private:
	int intLength;
	int intWidth;
	int intDepth;
	int intFillTime;
	int intEmptyTime;
	float fltFillRate;
	float fltDrainageRate;
	float fltCubicFeet;
	float fltInitialWaterVolume;
};

