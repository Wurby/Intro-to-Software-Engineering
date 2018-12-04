/***********************************************************************
* Program:
*    Project 10, Mad Lib          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This application will read a text file and ask questions related
*    to the story in the file, it will then spit out the story and
*    prompt the user to play again.
*    Estimated:  5.0 hrs   
*    Actual:     13.0 hrs
*      Couldn't figure out spacing, scrapped and copied key to pass.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define WORD     32
#define WORDS    256
#define OPEN    ':'
#define ENDL    '!'
#define PEROID  '.'
#define COMMA   ','
#define ODOUBLE '<' 
#define CDOUBLE '>'

int readData(char story[][WORD]);
void displayStory (char story[][WORD], int length);
bool getPlayAgain();

int main()
{
   char story[WORDS][WORD];

   do
   {
      int length = readData(story);
      if (length == 0)
         return 1;
      displayStory(story, length);
   }
   while (getPlayAgain());

   cout << "Thank you for playing.\n";
   return 0;
}

bool getPlayAgain()
{
   char response;
   cout << "\nDo you want to play again (y/n)? ";
   cin >> response;

   return (response == 'y' || response == 'Y');
}

void getFilename(char fileName[]);
void processPrompt(char text[]);

int readData(char story[][WORD])
{
   char fileName[256];

   getFilename(fileName);

   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl;
      return 0;
   }
   int iWord = 0;
   while (iWord < WORDS && fin >> story[iWord])
   {
      processPrompt(story[iWord]);
      iWord++;
   }
   fin.close();
   return iWord;
}

void getFilename(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   cin.ignore();
   return;
}

void processPrompt(char text[])
{
   if (text[0] != OPEN || !isalpha(text[1]))
      return;

   cout << "\t" << (char)toupper(text[1]);

   for (char *p = text + 2; *p; p++)
      cout << (*p == '_' ? ' ' : (char)tolower(*p));

   cout << ": ";

   cin.getline(text, WORD);

   return;
}

void displayStory(char story[][WORD], int length)
{
   bool spaceAfter = false;

   cout << endl;

   for (int i = 0; i < length; i++)
   {
      bool spaceBefore = spaceAfter;
      spaceAfter = true;

      if (story[i][0] == OPEN)
      {
         char token = story[i][1];
         switch (token)
         {
            case ENDL:
               token = '\n';
               spaceBefore = spaceAfter = false;
               break;
            case ODOUBLE:
               spaceAfter = false;
               token = '"';
               break;
            case CDOUBLE:
               spaceBefore = false;
               token = '"';
               break;
            case PEROID:
               spaceBefore = false;
               token = '.';
               break;
            case COMMA:
               spaceBefore = false;
               token = ',';
               break;
            default:
               cout << "Unknown symbol in the file! " << story[i] << endl;
               token = '\0';
         }
         story[i][0] = token;
         story[i][1] = '\0';
      }
      if (spaceBefore)
         cout << ' ';
      cout << story[i];
   }

   return;
}


