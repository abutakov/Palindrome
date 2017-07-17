/* This programm prompts the user for a word
* or a phrase which must contain three or more letters
* or numbers. Program will determine whether or not
* the word or phrase is a palindrome.
*
* Written by O.Butakov
*
* Date Written: September 10, 2015
*/

#include <iostream>
#include <cctype>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main()
{
	const int SIZE = 50;
	int i, length, length2 = 0;
	char line[SIZE], line2[SIZE], reverseLine2[SIZE];

	cout << "\t   Project 1: \"Palindrome\"";

	do
	{
		cout << "\n\nPlease give me a phrase or word (must contain 3 or more letters): ";
		cin.getline(line, SIZE);

		while (strlen(line) < 3)
		{
			cout << "\nYour word or phrase MUST contain 3 or more letters. Try again: ";
			cin.getline(line, SIZE);
		}

		int count = 0; // setting counter of the new character array 
		length = strlen(line);
		for (i = 0; i < length; i++) // making character array without whitespaces, commas, etc
		if (isdigit(line[i]) | isalpha(line[i]))
			line2[count++] = tolower(line[i]);

		line2[count] = '\0';

		for (i = 0; i < count; i++) // making reverse of our new character array
		{
			reverseLine2[i] = line2[(count - 1) - i];
		}

		bool notPalindrome = true; // setting flag 
		for (i = 0; i < count; i++)
		if (reverseLine2[i] != line2[i])
			notPalindrome = false;

		if (notPalindrome)
		{
			cout << endl;
			for (i = 0; i < length; i++)
				cout << line[i];
			cout << " is a palindrome.";
		}
		else
		{
			cout << endl;
			for (i = 0; i < length; i++)
				cout << line[i];
			cout << " is a not palindrome.";
		}

		cout << "\nGo again? (Y/N)? ";
	} while (toupper(_getch()) != 'N');
}