/***********************************************************************
* Program:
*    Assignment 32, Strings          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Counts the number of letters provided in a given string
*    
*    Estimated:  1.0 hrs   
*    Actual:     0.75 hrs
*      Learning how to use cin.getline();
************************************************************************/

#include <iostream>
using namespace std;


// prompts user for a character.
char getChar()
{
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;
   return letter;
}

// calculates number of letters in a string.
int countLetters(char text[], char letter)
{
   int numberOfLetters = 0;

   for (int i = 0; text[i]; i++)
   {
      if (text[i] == letter)
         numberOfLetters++;
   }

   return numberOfLetters;
}

// calls other functions.
int main()
{
   char letter;
   int instancesOfLetter;
   char text[256];
   letter = getChar();
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);
   instancesOfLetter = countLetters(text, letter);
   cout << "Number of '"
        << letter
        << "'s: "
        << instancesOfLetter
        << endl;
   return 0;
}
