#include "swimmingPool.h"

swimmingPool::swimmingPool()
{
	setLength(10);
	setWidth(8);
	setDepth(6);
	setFillRate(0);
	setDrainageRate(0);
	setInitialVolume(0);
	fltCubicFeet = 7.48052;
}

swimmingPool::swimmingPool(int intpLength, int intpWidth, int intpDepth, 
	float fltInitialpWaterVolume, float fltpFillRate, float fltpDrainageRate)
{
	setLength(intpLength);
	setWidth(intpWidth);
	setDepth(intpDepth);
	setFillRate(fltpFillRate);
	setDrainageRate(fltpDrainageRate);
	setInitialVolume(fltInitialpWaterVolume);
	fltCubicFeet = 7.48052;
}

swimmingPool::~swimmingPool()
{
	setLength(0);
	setWidth(0);
	setDepth(0);
	setFillRate(0);
	setDrainageRate(0);
	setInitialVolume(0);
}

//This retrieves the length
int swimmingPool::getLength()
{
	return this->intLength;
}

//This sets the length of the swimming pool
int swimmingPool::setLength(int intpLength)
{
	if (intpLength <= 0)
	{
		intpLength = 12;
		std::cerr << "swimmingPool::setLength - Invalid too small." << std::endl;
	}
	this->intLength = intpLength;
	return this -> getLength();
}

//This retrieves the width of the pool
int swimmingPool::getWidth()
{
	return this->intWidth;
}

//This sets the width of the pool
int swimmingPool::setWidth(int intpWidth)
{
	if (intpWidth <= 0)
	{
		intpWidth = 8;
		std::cerr << "swimmingPool::setWidth - Invalid too small." << std::endl;
	}
	this->intWidth = intpWidth;
	return this->getWidth();
}

//This gets the depth of the pool
int swimmingPool::getDepth()
{
	return this->intDepth;
}

//This sets the depth of the pool
int swimmingPool::setDepth(int intpDepth)
{
	if (intpDepth <= 0)
	{
		intpDepth = 6;
		std::cerr << "swimmingPool::setLength - Invalid too small." << std::endl;
	}
	this->intDepth = intpDepth;
	return this->getDepth();
}

//This retrieves the fill rate for the pool
float swimmingPool::getFillRate()
{
	return this->fltFillRate;
}

//This sets the fill rate for the pool
float swimmingPool::setFillRate(float fltpFillRate)
{
	if (fltpFillRate < 0)
	{
		fltpFillRate = 0;
		std::cerr << "swimmingPool::setFillRate - Invalid." << std::endl;
	}
	this->fltFillRate = fltpFillRate;
	return this->getFillRate();
}

//This gets the drainage rate for the pool
float swimmingPool::getDrainageRate()
{
	return this->fltDrainageRate;
}

//This sets the drainage rate for the pool
float swimmingPool::setDrainageRate(float fltpDrainageRate)
{
	if (fltpDrainageRate < 0)
	{
		fltpDrainageRate = 0;
		std::cerr << "swimmingPool::setDrainageRate - Invalid." << std::endl;
	}
	this->fltDrainageRate = fltpDrainageRate;
	return this->getDrainageRate();
}

//This gets the volume of the pool
float swimmingPool::getVolume()
{
	return (this->getLength() * this->getWidth() * this->getDepth());
}

//This gets the amount of water the pool can hold
float swimmingPool::getWaterVolume()
{
	return ((this->getVolume() * fltCubicFeet) - getInitialVolume());
}


//This sets the amount of water already in the pool
float swimmingPool::setInitialVolume(float fltInitialpWaterVolume)
{
	if (fltInitialpWaterVolume < 0)
	{
		fltInitialpWaterVolume = 0;
		std::cerr << "swimmingPool::setInitialVolume - Invalid." << std::endl;
	}
	this -> fltInitialWaterVolume = fltInitialpWaterVolume;
	return this->getInitialVolume();
}

//This retrieves the amount of water already in the pool
float swimmingPool::getInitialVolume()
{
	return this->fltInitialWaterVolume;
}

//This retrieves the fill time of the pool
int swimmingPool::getFillTime()
{
	return (this->getWaterVolume() / (this->getFillRate() - this -> getDrainageRate()));
}

//This retrieves the drainage time for the pool
int swimmingPool::getDrainageTime()
{
	return ((this->getInitialVolume() / (this->getDrainageRate() - this -> getFillRate())));
}

//This puts everything into a string and outputs it
std::string swimmingPool::toString()
{
	std::string strReturnValue = "";
	strReturnValue += "Length: " + std::to_string(this->getLength()) + ", ";
	strReturnValue += "Width: " + std::to_string(this->getWidth()) + ", ";
	strReturnValue += "Depth: " + std::to_string(this->getDepth()) + ", ";
	strReturnValue += "Pool volume: " + std::to_string(this->getVolume()) + ", ";
	strReturnValue += "Gallons of water pool can hold: " + std::to_string(this->getWaterVolume()) + ", ";
	strReturnValue += "Gallons of water in pool already: " + std::to_string(this->getInitialVolume()) + ", ";
	if (getFillRate() > 0)
	{
		strReturnValue += "Fill rate: " + std::to_string(this->getFillRate()) + ", ";
		strReturnValue += "Amount of time to fill up: " + std::to_string(this->getFillTime()) + ", ";
	}
	else if (getDrainageRate() > 0)
	{
		strReturnValue += "Drainage rate: " + std::to_string(this->getDrainageRate()) + ", ";
		strReturnValue += "Amount of time to empty: " + std::to_string(this->getDrainageTime()) + ", ";
	}
	return strReturnValue;

}
