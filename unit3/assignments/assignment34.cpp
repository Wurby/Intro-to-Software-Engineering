/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Counts the number of letters provided in a given string, using pointers
*    
*    Estimated:  1.0 hrs   
*    Actual:     0.75 hrs
*      Learning pointer logic.
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
int countLetters(char * ptext, char letter)
{
   int numberOfLetters = 0;
   for (char * i = ptext; *i; i++)
   {
      if (*i == letter)
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
   char * ptext = text;
   letter = getChar();
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(ptext, 256);
   instancesOfLetter = countLetters(ptext, letter);
   cout << "Number of '"
        << letter
        << "'s: "
        << instancesOfLetter
        << endl;
   return 0;
}
