// EAS-prg10-Vowels.cpp : This file contains the 'main' function. Program execution begins and ends there.

// By: Erik Sistos
// Date: 20200417
// Description: This program prompts the user for a sequence of characters and outputs the 
// number of vowels by checking through the isVowel function

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char charLetter);

int main()
{
	//Variables
	string strSequence = "abeidoou";
	char charCharacter = 'e';
	int intVowels = 0;

	cout << "Please enter a sequence of characters: ";
	getline(cin, strSequence);

	//Goes through string sequence to determine the number of vowels
	for (int intSequencePos = 0; intSequencePos < strSequence.length(); intSequencePos++)
	{
		charCharacter = strSequence[intSequencePos];
		if (isVowel(charCharacter))
		{
			intVowels++;
		}
		//cerr << charCharacter << endl;
	}
	cout << "The number of vowels are: " << intVowels;
	return 0;
}
//Checks to see if the characters in sequence are vowels
bool isVowel(char charLetter)
{
	bool isVowel = false;
	
		switch (charLetter)
		{
		case 'a': case 'A': 
		case 'e': case 'E': 
		case 'i': case 'I': 
		case 'o': case 'O': 
		case 'u': case 'U':
			isVowel = true;
			break;
		default:
			isVowel = false;
			break;
		}
		return isVowel;
}



	