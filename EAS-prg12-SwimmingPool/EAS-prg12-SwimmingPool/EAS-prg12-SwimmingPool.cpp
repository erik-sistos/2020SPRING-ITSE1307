// EAS-prg12-SwimmingPool.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200424
// Description: This program creates a class for a swimming pool

#include <iostream>
#include <string>
#include "swimmingPool.h"

int main()
{
    int intLength = 0;
    int intWidth = 0;
    int intDepth = 0;
    float fltInitialVolume = 0;
    float fltFillRate = 0;
    float fltDrainageRate = 0;
    std::cout << "Enter the length, width, and depth of the pool in feet: ";
    std::cin >> intLength >> intWidth >> intDepth;
    std::cout << "Enter the amount of water already in the pool in gallons: ";
    std::cin >> fltInitialVolume;
    std::cout << "Enter the fill rate of the pool in gallons per minute: ";
    std::cin >> fltFillRate;
    std::cout << "Enter the drainage rate of the pool in gallons per minute: ";
    std::cin >> fltDrainageRate;

    swimmingPool objSwimmingPoolOne = swimmingPool(intLength, intWidth, intDepth, fltInitialVolume, fltFillRate,
        fltDrainageRate);
    std::cout << "Based on the information you provided: " << objSwimmingPoolOne.toString();

    if (objSwimmingPoolOne.getFillRate() > 0)
    {
        std::cout << std::endl << "It will take "
            << objSwimmingPoolOne.getFillTime() << " minutes to fill" << std::endl;
    }
    else if (objSwimmingPoolOne.getDrainageRate() > 0)
    {
        std::cout << std::endl << "It will take "
            << objSwimmingPoolOne.getDrainageTime() << " minutes to empty" << std::endl;
    }
    return 0;
}
