#pragma once
#include <random>
#include <time.h>
#include <iostream>
#include <string>

class Room
{
public:
	Room();
	~Room();
private:
	int intNumberOfCoins;
	bool hasTrap;
	bool hasItem;
	int intNorthIndex;
	int intEastIndex;
	int intSouthIndex;
	int intWestIndex;
	//void init();
public:
	bool setTrap(int intHasTrap);
	bool getItem();
	bool setItem(int haspItem);
	int getCoins();
	int setCoins(int intpCoins);
	int getNorth();
	int getEast();
	int getSouth();
	int getWest();
	int setNorth(int intpIndex);
	int setEast(int intpIndex);
	int setSouth(int intpIndex);
	int setWest(int intpIndex);
	bool checkForTrap(int& intpPlayerLives);
	bool checkForTrap(int& intpPlayerLives, bool doesSearch);
	bool checkForItem();
	std::string toString();
};