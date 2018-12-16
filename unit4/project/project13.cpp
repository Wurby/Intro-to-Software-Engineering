/***********************************************************************
* Program:
*    Project 12, Sudoku Project
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary:
*    Creates a sodoku puzzle from a file. allows the user a list of 
*    interactions to solve the puzzle. User may save the board
*    edit data, or check possible values for a square.
*
*    Estimated:  6.0 hrs
*    Actual:     3.5 hrs
*      // UPDATE ME
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#define ROWS 9
#define COLS 9

void display(int board[][COLS]);
void getFile(string & filename);
int readFile(string & filename, int board[][COLS]);


/***********************************************************************
* Main
* Starts the program ends it based on user interaction.
************************************************************************/
int main() 
{
   string filename;
   int board[ROWS][COLS];
   getFile(filename);
   readFile(filename, board);
   display(board);
   return 0;
}

/***********************************************************************
* Get File Name
* Asks user for filename.
************************************************************************/
void getFile(string & filename) 
{
   cout << "Where is your board located? ";
   cin >> filename;
   // cin.ignore(); May need this. Will see later.
}

/***********************************************************************
* Read file
* Read the file and stores data into 2d array.
************************************************************************/
int readFile(string & filename, int board[][COLS])
{
   ifstream fin(filename.c_str());

   if (fin.fail())
      return -1;
   else
   {
      for (int rows = 0; rows < ROWS; rows++)
      {
         for (int cols = 0; cols < COLS; cols++)
         {
            fin >> board[rows][cols];
         }
      }
   }
   fin.close();
   return 0;
}

/***********************************************************************
* display
* displays board with loaded data from the parameter.
************************************************************************/
void display(int board[][COLS])
{
   const char rowSeperator[] =
   {"   -----+-----+-----\n"};

   cout << "   A B C D E F G H I\n";
   for (int row = 0; row < ROWS; row++)
   {
      for (int col = 0; col < COLS; col++)
      {
         cout << board[row][col];
         if (col == 2)
            cout << "|";
         else if (col == 5)
            cout << "|";
         else if (col == 8)
            cout << endl;
         else if (row == 2)
            cout << rowSeperator;
      }
   }
}