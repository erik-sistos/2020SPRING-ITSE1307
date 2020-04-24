// EAS-prg11-FitnessCenterCost.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200422
// Description: This program calculates the cost of a fitness center by passing through reference parameters.

#include <iostream>
#include <iomanip>

using namespace std;

void fitnessCenterInfo();

void membershipCostInfo(bool& boolSeniorCitizen, bool& boolTwelvePlusMonths,
                        bool& boolFivePlusSessions, int& intMembershipMonths, int& intTrainingSessions);

void membershipMonthlyAndTrainingCost(float& fltMonthlyCost, float& fltTrainingCost);

float fltMembershipCost(int intNumberOfMembership, float fltMonthlyCost, bool boolTwelvePlusMonths,
    bool boolIsSeniorCitizen, bool boolMoreThanFiveSessions, float fltTrainningSessionCost, int intTrainningSessions);

int main()
{
    //Variable
    bool boolIsSenior = false;
    bool boolTwelveMonths = false;
    bool boolFiveSessions = false;
    float fltMembershipPrice = 0.0f;
    float fltTrainingSessionPrice = 0.0f;
    int intNumberOfMembershipMonths = 0;
    int intNumberOfTrainingSessions= 0;
    float fltMembershipTotalPrice = 0.0f;

    fitnessCenterInfo();

    membershipMonthlyAndTrainingCost(fltMembershipPrice, fltTrainingSessionPrice);

    membershipCostInfo(boolIsSenior, boolTwelveMonths, boolFiveSessions, 
        intNumberOfMembershipMonths, intNumberOfTrainingSessions);

    fltMembershipTotalPrice = fltMembershipCost(intNumberOfMembershipMonths, fltMembershipPrice, boolTwelveMonths,
        boolIsSenior, boolFiveSessions, fltTrainingSessionPrice, intNumberOfTrainingSessions);

    cout << setprecision(2) << fixed;
    cout << "The price for your new membership is $" << fltMembershipTotalPrice << endl;
    return 0;
}

//Outputs the general information of the fitness center
void fitnessCenterInfo()
{
    cout << "Welcome to the fitness center." << endl;
    cout << "(A) Senior citizens discount is 30%." << endl;
    cout << "(B) If you buy 12 months or more today a 15% discount will be applied." << endl;
    cout << "(C) If you purchase more than 5 personal training sessions a 20% discount will be applied." << endl;
}

//Gathers information to determine the discounts that should be applied
void membershipCostInfo(bool& boolSeniorCitizen, bool& boolTwelvePlusMonths,
                        bool& boolFivePlusSessions, int& intMembershipMonths, int& intTrainingSessions)
{
    char charSeniorCitizen = 'n';

    do
    {
        cout << "Are you a senior citizen (y or n): ";
        cin >> charSeniorCitizen;
        charSeniorCitizen = tolower(charSeniorCitizen);

        switch (charSeniorCitizen)
        {
        case 'y':
            boolSeniorCitizen = true;
            break;
        case 'n':
            boolSeniorCitizen = false;
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }
    } while ((charSeniorCitizen != 'n' && charSeniorCitizen !='y'));
    
    cout << "How many months would you like to purchase the membership?: ";
    cin >> intMembershipMonths;
    
    if (intMembershipMonths >= 12)
    {
        boolTwelvePlusMonths = true;
    }
    else
    {
        boolTwelvePlusMonths = false;
    }

    cout << "How many training sessions would you like to buy?: ";
    cin >> intTrainingSessions;

    if (intTrainingSessions > 5)
    {
        boolFivePlusSessions = true;
    }
    else
    {
        boolFivePlusSessions = false;
    }
}

//Gathers the information to determine the monthly and training cost individually
void membershipMonthlyAndTrainingCost(float& fltMonthlyCost, float& fltTrainingCost)
{
    cout << "Enter the price for an individual month: $";
    cin >> fltMonthlyCost;
    cout << "Enter the price for an individual traning session: $";
    cin >> fltTrainingCost;

}

float fltMembershipCost(int intNumberOfMembership, float fltMonthlyCost, bool boolTwelvePlusMonths,
    bool boolIsSeniorCitizen, bool boolMoreThanFiveSessions, float fltTrainingSessionCost, int intTrainingSessions)
{
    float fltSeniorDiscount = 0.30f;
    float fltTwelvePlusDiscount = 0.15f;
    float fltTrainingSessionDiscount = 0.20f;
    float fltTotalCost = 0.0f;

    fltTotalCost = fltMonthlyCost * intNumberOfMembership;
    if (boolIsSeniorCitizen)
    {
        fltTotalCost = fltTotalCost - (fltMonthlyCost * fltSeniorDiscount * intNumberOfMembership);
    }

    if (boolTwelvePlusMonths)
    {
        fltTotalCost = fltTotalCost - (fltMonthlyCost * fltTwelvePlusDiscount * intNumberOfMembership);
    }

    fltTotalCost = fltTotalCost + (fltTrainingSessionCost * intTrainingSessions);

    if (boolMoreThanFiveSessions)
    {
        fltTotalCost = fltTotalCost - (fltTrainingSessionCost * fltTrainingSessionDiscount * intTrainingSessions);
    }
    return fltTotalCost;
}