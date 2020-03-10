// EAS-prg8-BMI.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200305
// Description: This program determines the body fat of males and females


#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    double dblBodyWeight = 0.0;
    double dblWristMeasurement = 0.0;
    double dblWaistMeasurement = 0.0;
    double dblHipMeasurement = 0.0;
    double dblForearmMeasurement = 0.0;

    double dblA1 = 0.0;
    double dblA2 = 0.0;
    double dblA3 = 0.0;
    double dblA4 = 0.0;
    double dblA5 = 0.0;
    double dblB = 0.0;
    double dblBodyFat = 0.0;
    double dblBodyFatPercentage = 0.0;

    char charGender = ' ';

    cout << "Please enter (f) for female or (m) for male (f or m): ";
    cin >> charGender;

    switch (charGender)
    {
    case 'f': case 'F':
        cout << "Please enter your weight: ";
        cin >> dblBodyWeight;
        cout << "Please enter your wrist measurement: ";
        cin >> dblWristMeasurement;
        cout << "Please enter your waist measurement (at navel): ";
        cin >> dblWaistMeasurement;
        cout << "Please enter your hip measurement (at fullest point): ";
        cin >> dblHipMeasurement;
        cout << "Please enter your forearm measurement (at fullest point): ";
        cin >> dblForearmMeasurement;

        dblA1 = (dblBodyWeight * 0.732) + 8.987;
        dblA2 = (dblWristMeasurement / 3.140);
        dblA3 = (dblWaistMeasurement * 0.157);
        dblA4 = (dblHipMeasurement * 0.249);
        dblA5 = (dblForearmMeasurement * 0.434);
        dblB = dblA1 + dblA2 - dblA3 - dblA4 + dblA5;
        dblBodyFat = dblBodyWeight - dblB;
        dblBodyFatPercentage = (dblBodyFat * 100) / dblBodyWeight;

        cout << "Your body fat is " << dblBodyFat << endl;
        cout << "Your body fat percentage is " << dblBodyFatPercentage << "%";
        break;

    case 'm': case 'M':
        cout << "Please enter your weight: ";
        cin >> dblBodyWeight;
        cout << "Please enter your wrist measurement: ";
        cin >> dblWristMeasurement;

        dblA1 = (dblBodyWeight * 1.082) + 94.42;
        dblA2 = dblWristMeasurement * 4.15;
        dblB = dblA1 - dblA2;
        dblBodyFat = dblBodyWeight - dblB;
        dblBodyFatPercentage = (dblBodyFat * 100) / dblBodyWeight;

        cout << "Your body fat is " << dblBodyFat << endl;
        cout << "Your body fat percentage is " << dblBodyFatPercentage << "%";
        break;
    default:
        cout << "Invalid input.";
        break;
    }
    return 0;
}

