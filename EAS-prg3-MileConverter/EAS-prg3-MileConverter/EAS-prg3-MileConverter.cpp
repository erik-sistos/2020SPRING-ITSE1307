// EAS-prg3-MileConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.

//By: Erik Sistos
//Date: 20200211
//Description: This program converts miles to kilometers

#include <iostream>
#include <iomanip>

const float FLT_KILOMETERS = 1.60934f;
int main()
{
    std::cout << std::fixed << std::setprecision(2);

    //Variables
    float fltMiles = 0.0f;
    float fltTotalKilometers = 0.0f;

    //Intro
    std::cout << "Mile Converter";

    //Input
    std::cout << "\nEnter the number of miles you ran that will be converted to kilometers: ";
    std::cin >> fltMiles;

    //Process
    fltTotalKilometers = fltMiles * FLT_KILOMETERS;

    //Output
    std::cout << std::setw(7) << fltMiles << " miles is" << std::endl;
    std::cout << std::setw(7) << fltTotalKilometers << " kilometers" << std::endl;
    return 0;
}
