// EAS-prg9-Numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200327
// Description: This program prompts the user for an integer and then outputs the individual
//digits and the sum of the digits

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//Variables
	int intNumber = 3456;
	int intSum = 0;
	int intPower = 0;

	cout << "Please enter an integer: ";
	cin >> intNumber;

	//Convert negative numbers to positives
	intNumber = abs(intNumber);
	int intDigit = intNumber;

	//Calculates the sum of the individual digits
	do
	{
		intSum += intNumber % 10;
		intNumber /= 10;
	} while (intNumber > 0);

	//Determines where the first digit is in the number
	while (intDigit / (pow(10,intPower)) >= 10)
	{
		intPower++;
	}

	cout << "The individual digits are ";

	//Outputting each individual digit that user entered
	while (intDigit >= 0 && intPower >=0)
	{
		int intTenToPower = (pow(10, intPower));
		//cerr << "$" << intTenToPower << endl;
		intNumber = (intDigit / intTenToPower);
		intDigit %= intTenToPower;
		cout << intNumber << " ";
		intPower = intPower - 1;
	}
	cout << endl;
	cout << "The sum of the individual digits is: " << intSum;
	return 0;
}

