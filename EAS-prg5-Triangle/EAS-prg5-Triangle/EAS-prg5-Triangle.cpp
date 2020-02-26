// EAS-prg5-Triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200218
// Description: This program indicates whether a triangle is a right triangle based on the side lengths

#include <iostream>
#include <cmath>
int main()
{
    //Variables
    float fltLengthA = 0.0f;
    float fltLengthB = 0.0f;
    float fltLengthC = 0.0f;

    //Input
    std::cout << "Please enter a positive number of the two shortest sides of the triangle followed by a space: ";
    std::cin >> fltLengthA >> fltLengthB;
    std::cout << "Please enter a positive number of the longest side of the triangle: ";
    std::cin >> fltLengthC;

    //Checks to see if user input is a positive number greater than zero
    if ((fltLengthA <= 0) || (fltLengthB <= 0) || (fltLengthC <= 0))
    {
        std::cerr << "Invalid input. Program exiting.";
        return 1;
    }
    
    //Process
    fltLengthA = pow(fltLengthA, 2);
    fltLengthB = pow(fltLengthB, 2);
    fltLengthC = pow(fltLengthC, 2);

    //Compares the lenghts to make sure they're equal
    if (fltLengthC == (fltLengthA + fltLengthB))
    {
        std::cout << "That is a right triangle";
    } 
    else
    {
        std::cout << "That is not a right triangle";
    }

    return 0;
}

