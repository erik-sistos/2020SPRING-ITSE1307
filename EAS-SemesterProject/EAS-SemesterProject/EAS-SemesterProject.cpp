// EAS-SemesterProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: ITSE 1307
// Date: 20200206
// Description: This the main for a text based adventure dungeon crawler

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <random>
#include <vector>
#include "Room.h"



int determineHighScore(int& intCurrentHighScore, int intPotentialHighScore) {
	if (intPotentialHighScore >= intCurrentHighScore) {
		intCurrentHighScore = intPotentialHighScore;
	}
	return intCurrentHighScore;
}


int calculateHighScore(int intNumberOfItems, int NumberOfCoins, int intNumberOfLives) {
	float fltLives = 1.00f;
	switch (intNumberOfLives)
	{
	case 1:
		fltLives = 1.00f;
		break;
	case 2:
		fltLives = 1.25f;
		break;
	case 3:
		fltLives = 1.50f;
		break;
	}
	int intHighScore = ((intNumberOfItems * 100) + (NumberOfCoins * 20)) * fltLives;
	return intHighScore;
}

void displaySplashScreen() {
	// Splash Screen
	std::cout << "\n";
	std::cout <<  "                  /\\" << std::endl;
	std::cout << "	          ||" << std::endl;
	std::cout <<  "    ____ (((+))) _||_" << std::endl;
	std::cout << "   /.--.\\  .-.  /.||.\\ "<< std::endl;
	std::cout << "  /.,   \\\\(0.0)// || \\\\" << std::endl;
	std::cout << " /;`\";/\\ \\\\|m|//  ||  ;\\ " << std::endl;
	std::cout << " |:   \\ \\__`:`____||__:|" << std::endl;
	std::cout << " |:    \\__ \\T/ (@~)(~@)|" << std::endl;
	std::cout << " |:    _/|     |\\_\\/  :|" << std::endl;
	std::cout << " |:   /  |     |  \\   :|" << std::endl;
	std::cout << " |'  /   |     |   \\  '|" << std::endl;
	std::cout << "  \\_/    |     |    \\_/" << std::endl;
	std::cout << "	 |     |" << std::endl;
	std::cout << "	 |_____|" << std::endl;
	std::cout << "	 |_____|" << std::endl;

	std::cout << "\nDungeon Hunter";
}

void displayMainMenu() {
	// Main Menu
	std::cout << "\nMain Menu" << std::endl;
	std::cout << "s) Start Game" << std::endl;

	std::cout << "q) Quit Game" << std::endl;
	std::cout << "What would you like to do: ";
}

void winLoseScreen(bool& boolpWinCodition, int& intNumberOfLives, int intNumberOfItems, int intNumberOfCoins, int intHighScore)
{
	bool boolWinCondition = boolpWinCodition;
	if (boolWinCondition == true && intNumberOfLives > 0)
	{
		
		std::cout << "            _( }" << std::endl;
		std::cout << "   -=  _  <<  \\" << std::endl;
		std::cout << "      `.\\__/`/\\\\" << std::endl;
		std::cout << " -=     '--'\\\\  `" << std::endl;
		std::cout << "      -=    //" << std::endl;
		std::cout << "            \\)" << std::endl;

		std::cout << "\nCongratulations, you won!";
		std::cout << "\nYour Score: " << calculateHighScore(intNumberOfItems, intNumberOfCoins, intNumberOfLives);
		std::cout << "\nHigh Score: " << determineHighScore(intHighScore, calculateHighScore(intNumberOfItems, intNumberOfCoins, intNumberOfLives)) << std::endl;
	}
	else
	{
		std::cout << "\n @@@@@                                        @@@@@" << std::endl;
		std::cout << "@@@@@@@                                      @@@@@@@" << std::endl;
		std::cout << "@@@@@@@           @@@@@@@@@@@@@@@            @@@@@@@" << std::endl;
		std::cout << " @@@@@@@@       @@@@@@@@@@@@@@@@@@@        @@@@@@@@" << std::endl;
		std::cout << "     @@@@@     @@@@@@@@@@@@@@@@@@@@@     @@@@@" << std::endl;
		std::cout << "       @@@@@  @@@@@@@@@@@@@@@@@@@@@@@  @@@@@" << std::endl;
		std::cout << "         @@  @@@@@@@@@@@@@@@@@@@@@@@@@  @@" << std::endl;
		std::cout << "            @@@@@@@    @@@@@@    @@@@@@" << std::endl;
		std::cout << "            @@@@@@      @@@@      @@@@@" << std::endl;
		std::cout << "            @@@@@@      @@@@      @@@@@" << std::endl;
		std::cout << "             @@@@@@    @@@@@@    @@@@@" << std::endl;
		std::cout << "              @@@@@@@@@@@  @@@@@@@@@@" << std::endl;
		std::cout << "               @@@@@@@@@@  @@@@@@@@@" << std::endl;
		std::cout << "            @@  @@@@@@@@@@@@@@@@@@@@  @@" << std::endl;
		std::cout << "            @@@@ @@@@@ @ @ @ @ @@@@ @@@@" << std::endl;
		std::cout << "           @@@@@  @@@@ @ @ @ @ @@@   @@@@@" << std::endl;
		std::cout << "         @@@@@     @@@@@@@@@@@@@@      @@@@@" << std::endl;
		std::cout << "       @@@@         @@@@@@@@@@@@          @@@@" << std::endl;
		std::cout << "    @@@@@             @@@@@@@@              @@@@@" << std::endl;
		std::cout << "   @@@@@@@                                 @@@@@@@" << std::endl;
		std::cout << "    @@@@@                                   @@@@@" << std::endl;
		std::cout << std::setfill(' ')<< std::setw(42) << "You lost! Better luck next time." << std::endl;
	}
}



int main()
{
	srand((unsigned int)time(NULL));
	// Variables
	std::vector<Room> vtrRoom(7);
	int intNumberOfCoins = 0;
	int intNumberOfItems = 0;
	int intStartingNumberOfLives = 3;
	int intCurrentRoomIndex = 0;
	int intNumberOfRooms = 7;
	int intNumberOfLives = intStartingNumberOfLives;
	int intHighScore = 500;
	char chrMenuChoice = ' ';
	char chrDirectionChoice = ' ';
	std::string strAcceptedChoiceInRoom = "wasd0ict";
	bool boolWinCondition = false;
	Room objTempRoom;
	displaySplashScreen();

	do {
		displayMainMenu();

		std::cin >> chrMenuChoice;

		switch (chrMenuChoice) {
		case 's':
			// Setup of game state for new game place Start the game
			intNumberOfCoins = 0;
			intNumberOfItems = 0;
			intNumberOfLives = intStartingNumberOfLives;
			boolWinCondition = false;
			vtrRoom.clear();

			objTempRoom = Room();
			objTempRoom.setNorth(1);
			objTempRoom.setEast(2);
			objTempRoom.setSouth(3);
			objTempRoom.setWest(4);
			objTempRoom.setItem(1);
			objTempRoom.setTrap(0);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setSouth(0);
			objTempRoom.setEast(5);
			objTempRoom.setItem(0);
			objTempRoom.setTrap(0);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setWest(0);
			objTempRoom.setSouth(6);
			objTempRoom.setItem(0);
			objTempRoom.setTrap(1);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setNorth(0);
			objTempRoom.setItem(0);
			objTempRoom.setTrap(0);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setEast(0);
			objTempRoom.setItem(0);
			objTempRoom.setTrap(1);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setSouth(2);
			objTempRoom.setWest(1);
			objTempRoom.setItem(1);
			objTempRoom.setTrap(1);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setNorth(2);
			objTempRoom.setItem(0);
			objTempRoom.setTrap(0);
			vtrRoom.push_back(objTempRoom);

			std::cout << "You awake in a room that looks like a mine shaft, no one has been here for awhile." << std::endl;

			// Main game room movement and search loop
			while (boolWinCondition != true && intNumberOfLives > 0) {
				std::cout << "Player Stats: Lives: " << intNumberOfLives << ", Items: " << intNumberOfItems << ", Coins: " << intNumberOfCoins << std::endl;
				std::cout << "You enter a room in the mine shaft ..." << std::endl;


				Room objRoom = vtrRoom.at(intCurrentRoomIndex);
				//std::cerr << objRoom.toString() << std::endl;

				//Loop for correct user input
				do {
					std::cout << "Which direction do you want to go (w [go North], a [go West], s [go South], d [go East])? " << std::endl;
					std::cout << "What would you like to do (c [Search for Coins], i [Search for items])? ";
					std::cin >> chrDirectionChoice;
				} while (strAcceptedChoiceInRoom.find(chrDirectionChoice) == std::string::npos);


				//Logic for handling user input choice
				switch (chrDirectionChoice) {
				case 'w': //Walk North
					std::cout << "You walk north..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getNorth() > -1) {
						intCurrentRoomIndex = objRoom.getNorth();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}
					break;
				case 'a': //Walk West
					std::cout << "You walk west..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getWest() > -1) {
						intCurrentRoomIndex = objRoom.getWest();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}
					break;
				case 's': //Walk South
					std::cout << "You walk south..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getSouth() > -1) {
						intCurrentRoomIndex = objRoom.getSouth();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}
					break;
				case 'd': //Walk East
					std::cout << "You walk east..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getEast() > -1) {
						intCurrentRoomIndex = objRoom.getEast();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}
					break;
				case 'i': //Search for items
					std::cout << "You search for items in the room..." << std::endl;
					if (objRoom.checkForItem()) {
						intNumberOfItems++;
						vtrRoom.at(intCurrentRoomIndex).setItem(false);
						std::cout << " you found a rare item." << std::endl;
						if (intNumberOfItems >= 2) {
							boolWinCondition = true;
						}
					}
					else {
						std::cout << " you end up empty handed." << std::endl;
					}
					break;
				case 'c': //Search for coins
					std::cout << "You search for coins in the room..." << std::endl;
					vtrRoom.at(intCurrentRoomIndex).setCoins(rand() % 10 + 1);
					if (objRoom.getCoins() > 0) {
						intNumberOfCoins += objRoom.getCoins();
						std::cout << " you found " << objRoom.getCoins() << " coin(s)." << std::endl;
					}
					else {
						std::cout << " you end up empty handed." << std::endl;
					}
					break;
				case 't': //Search for traps
					std::cout << "You search for traps in the room..." << std::endl;
					if (objRoom.checkForTrap(intNumberOfLives, true)) {
						// Logic moved into class
					}
					else {
						std::cout << " you end up empty handed." << std::endl;
					}
					vtrRoom.at(intCurrentRoomIndex).setTrap(false);
					break;
				case '0': //Developers exit menu trick.
					intNumberOfLives = 0;
					break;
				} // Switch for player choices in rooom
				std::cout << std::endl;
			} /// Game Loop
			winLoseScreen(boolWinCondition, intNumberOfLives,
				intNumberOfItems, intNumberOfCoins, intHighScore);

			break;
		case 'q':
			boolWinCondition = false;
			winLoseScreen(boolWinCondition, intNumberOfLives,
				intNumberOfItems, intNumberOfCoins, intHighScore);
			std::cout << "\nYour Score: " << calculateHighScore(intNumberOfItems, intNumberOfCoins, intNumberOfLives);
			std::cout << "\nHigh Score: " << determineHighScore(intHighScore, calculateHighScore(intNumberOfItems, intNumberOfCoins, intNumberOfLives));
			break;
		}
	} while (chrMenuChoice != 'q');

	std::cout << std::endl;

	return 0;
}