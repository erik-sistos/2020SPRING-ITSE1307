// EAS-prg2-CurrencyConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By:Erik Sistos
//Date: 20200206
//Description: This is a simple currency converter that converts dollars to euros

#include <iostream>

int main()
{
    //1USD = 0.91Euro

    //Variables
    float floatUSD = 0.00f;
    float floatExchangeRate = 0.91f;
    float floatConversion = 0.00f;

    //Introduction
    std::cout << "Currency Exchange";

    //Input
    std::cout << "\nPlease enter a dollar amount from $1 to $1000 that you would like to convert to Euros: ";
    std::cin >> floatUSD;

    //Process
    floatConversion = floatUSD * floatExchangeRate;

    //Output
    std::cout << floatUSD << " USD converted to euros at rate " << floatExchangeRate << " is " << floatConversion << " euros";
 
    return 0;
}