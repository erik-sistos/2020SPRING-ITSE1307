// EAS-prg6-BoxOfCookies.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200225
// Description: This program asks the user for the number of cookies and outputs
// how many boxes and containers they'll need.

#include <iostream>
using namespace std;

int main()
{
    int intCookiesInBox = 24;
    int intBoxesInContainer = 75;
    int intNumberOfCookies = 5000;

    //TODO: Add user input logic
    cout << "Enter the number of cookies to ship: ";
    cin >> intNumberOfCookies;
    int intNumberOfBoxes = intNumberOfCookies / intCookiesInBox;
    int intRemainingUnboxedCookies = intNumberOfCookies % intCookiesInBox;

    //TODO: Figure out number of containers
    int intNumberOfContainers = intNumberOfBoxes / intBoxesInContainer;
    int intRemainingBoxesInContainer = intNumberOfBoxes % intBoxesInContainer;

    cout << "Number of Cookies : " << intNumberOfCookies << endl;
    cout << "Number of Boxes of Cookies (" << intCookiesInBox << "): " << intNumberOfBoxes << endl;
    cout << "Number of containers: " << intNumberOfContainers << endl;

    //TODO: Output for containers and other information
    if (intRemainingUnboxedCookies > 0)
    {
        cout << "Number of Unboxed Cookies: " << intRemainingUnboxedCookies << endl;
    }
    if (intRemainingBoxesInContainer > 0)
    {
        cout << "Number of leftover boxes: " << intRemainingBoxesInContainer << endl;
    }

    return 0;
}

