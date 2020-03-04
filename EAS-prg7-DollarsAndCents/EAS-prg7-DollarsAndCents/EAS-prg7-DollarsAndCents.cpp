// EAS-prg7-DollarsAndCents.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200225
// Description: This program outputs the total amount of money in dollar bills and cents

#include <iostream>

int main()
{
    float fltMoney = 250.39f;

    std::cout << "Please enter a dollar amount with cents: ";
    std::cin >> fltMoney;

    int intDollars = (int)(fltMoney / 1.0f);
    int intCents = (int)((fltMoney - (float)intDollars) * 100.0f);

    int intRemainingDollars = intDollars;

    int intHundred = (intRemainingDollars / 100);
    intRemainingDollars %= 100;
    //std::cerr << "R$: " << intRemainingDollars << std::endl;
    int intfifty = (intRemainingDollars / 50);
    intRemainingDollars %= 50;
    //std::cerr << "R$: " << intRemainingDollars << std::endl;
    int intTwenty = (intRemainingDollars / 20);
    intRemainingDollars %= 20;
    //std::cerr << "R$: " << intRemainingDollars << std::endl;
    int intTens = (intRemainingDollars / 10);
    intRemainingDollars %= 10;
    //std::cerr << "R$: " << intRemainingDollars << std::endl;
    int intFives = (intRemainingDollars / 5);
    intRemainingDollars %= 5;
    int intOnes = (intRemainingDollars / 1);
    intRemainingDollars %= 1;

    int intRemainingCents = intCents;

    int intQuarters = (intRemainingCents / 25);
    intRemainingCents %= 25;
    int intDimes = (intRemainingCents / 10);
    intRemainingCents %= 10;
    int intNickels = (intRemainingCents / 5);
    intRemainingCents %= 5;
    int intPennies = intRemainingCents;

    std::cout << "$ " << intDollars << std::endl;
    std::cout << ". " << intCents << std::endl;
    std::cout << "100: " << intHundred << std::endl;
    std::cout << "50: " << intfifty << std::endl;
    std::cout << "20: " << intTwenty << std::endl;
    std::cout << "10: " << intTens << std::endl;
    std::cout << "5: " << intFives << std::endl;
    std::cout << "1: " << intOnes << std::endl;
    std::cout << ".25: " << intQuarters << std::endl;
    std::cout << ".10: " << intDimes << std::endl;
    std::cout << ".05: " << intNickels << std::endl;
    std::cout << ".01: " << intPennies << std::endl;

    return 0;
}

