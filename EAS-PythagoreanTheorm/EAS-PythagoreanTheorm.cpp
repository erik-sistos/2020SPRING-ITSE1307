// EAS-PythagoreanTheorm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>


int main()
{
	float fltLengthA = 0;
	float fltLengthB = 0;
	float fltLengthC = 0;

	std::cout << "Please enter the length of side A as a decimal: ";
	std::cin >> fltLengthA;

	std::cout << "Pleae enter the length of side B as decimal: ";
	std::cin >> fltLengthB;

	fltLengthC = sqrt((fltLengthA*fltLengthA) + (fltLengthB * fltLengthB));

	std::cout <<"Length C is: " << fltLengthC << std::endl;
    return 0;
}

