// EAS-AreaofRectangle.cpp : Defines the entry point for the console application.

//By:Erik Sistos
//Date: 20202006
//Description: Find the area of a rectangle given

#include "stdafx.h"
#include <iostream>

int main()
{
	//Variables
	int intLength = 5;
	int intWidth = 6;
	int intArea = 0;

	//Input
	std::cout << "Please enter the length of the rectangle as a whole number: ";
	std::cin >> intLength;
	std::cout << "Please enter the width of the rectangle as a whole number: ";
	std::cin >> intWidth;

	// Processing
	intArea = intLength * intWidth;

	//Output
	//std::cout << "The area of the rectangle is 0.000";
	std::cout << "The area of the rectangle is: " << intArea;
	//std::cout << "The area of the rectangle is 0.000";

    return 0;
}

