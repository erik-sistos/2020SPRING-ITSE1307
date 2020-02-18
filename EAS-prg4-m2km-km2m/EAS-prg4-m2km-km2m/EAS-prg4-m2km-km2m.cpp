// EAS-prg4-m2km-km2m.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200217
// Description: This program converts from miles to kilometers and from kilometers to miles

#include <iostream>
#include <iomanip>
#include <cctype>

//Constants
const float FLT_MILES_TO_KILOMETERS = 0.621371f;
const float FLT_KILOMETERS_TO_MILES = 1.60934f;


int main()
{
    //Variables
    float fltMiles = 0.0f;
    float fltTotalMiles = 0.0f;
    float fltKilometers = 0.0f;
    float fltTotalKilometers = 0.0f;
    char chrChoice = ' ';

    std::cout << std::fixed << std::setprecision(2);

    //Intro
    std::cout << "Miles to kilometers and kilometers to miles.";

    std::cout << "\n\nA. Convert from miles to kilometers";
    std::cout << "\nB. Convert from kilometers to miles";
    std::cout << "\nPlease enter your choice to convert the distance traveled (A or B): ";
    std::cin >> chrChoice;
    chrChoice = tolower(chrChoice);

    //Miles to kilometers
    if (chrChoice == 'a')
    {
        std::cout << "\nEnter the number of miles you will like to convert: ";
        std::cin >> fltMiles;

        fltTotalKilometers = fltMiles * FLT_MILES_TO_KILOMETERS;

        std::cout << fltMiles << " miles is " << fltTotalKilometers << " kilometers.";
    }
    //Kilometers to miles
    else if (chrChoice == 'b')
    {
        std::cout << "\nEnter the number of kilometers you will like to convert: ";
        std::cin >> fltKilometers;

        fltTotalMiles = fltKilometers * FLT_KILOMETERS_TO_MILES;

        std::cout << fltKilometers << " kilometers is " << fltTotalMiles << " miles.";
    }
    else
    {
        std::cout << "\nThat is not a valid choice.";
    }

    return 0;
}

