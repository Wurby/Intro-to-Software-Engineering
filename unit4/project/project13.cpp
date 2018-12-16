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
*    Actual:     9.5 hrs
*      reading and writing the file correctly.
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
void displayOptions();
int interact(int board[][COLS]);
void getSaveFile(string & filename);
int writeFile(string & filename, int board[][COLS]);
void editSelection(int board[][COLS]);
void getCoords(string & selectedCoord);
bool isValidSelection(string & selectedCoord, int board[][COLS]);
void showPossibleValues(int board[][COLS]);
void getPossibleValues(string & coords, int board[][COLS], int valid[]);



/***********************************************************************
* Main
* Starts the program ends it based on user interaction.
************************************************************************/
int main() 
{
   string filename;
   int board[ROWS][COLS];
   char option;

   getFile(filename);
   readFile(filename, board);
   display(board);
   displayOptions();
   do
   {
      option = interact(board);
   }
   while (toupper(option) != 'Q');
   getSaveFile(filename);
   writeFile(filename, board);

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
   // this isn't working... Not sure what's going on. Going to build
   // the rest of the application and come back to it if I have time.
   if (fin.fail())
      return -1;
   for (int rows = 0; rows < ROWS; rows++)
   {
      for (int cols = 0; cols < COLS; cols++)
      {
         fin >> board[rows][cols];
         cout << "test: " << board[rows][cols] << endl;
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
         if (col == 2 && row != 3, 6)
            cout << "|";
         else if (col == 5 && row != 3, 6)
            cout << "|";
         else if (col == 8 && row != 3, 6)
            cout << endl;
         else if (row == 3 && col == 8)
            cout << rowSeperator;
      }
   }
}

/***********************************************************************
* interact
* asks for selection and returns result.
************************************************************************/
int interact(int board[][COLS])
{
   cout << endl;
   char selection;
   cin >> selection;
   switch (toupper(selection))
   {
      case '?':
         displayOptions();
         break;
      case 'D':
         display(board);
         break;
      case 'S':
         showPossibleValues(board);
         break;
      case 'Q':
         return 'Q';
      default:
         cout << "ERROR: Invalid command\n";
   }
}


/***********************************************************************
* display Options
* displays the available options.
************************************************************************/
void displayOptions()
{
   cout << "Options:" << endl;
	cout << "   ?  Show these instructions" << endl;
	cout << "   D  Display the board" << endl;
	cout << "   E  Edit one square" << endl;
	cout << "   S  Show the possible values for a square" << endl;
	cout << "   Q  Save and Quit" << endl;
}

/***********************************************************************
* get save file
* asks for save file location.
************************************************************************/
void getSaveFile(string & filename)
{
   cout << "What file would you like to write your board to: ";
   cin >> filename;
   // cin.ignore(); May need this?
}

/***********************************************************************
* write file
* writes file to retrieved file location.
************************************************************************/
int writeFile(string & filename, int board[][COLS])
{
   ofstream fout(filename.c_str());

   if (fout.fail())
      return -1;
   
   // since reading is broken, file writing is likely also broken.
   for (int rows = 0; rows < ROWS; rows++)
   {
      for (int cols = 0; cols < COLS; cols++)
      {
         fout << board[rows][cols];
         cout << "test: " << board[rows][cols] << endl;
         if (cols < COLS -1)
            fout << " ";
      }
      if (rows < ROWS -1)
         fout << endl;
   }
   fout.close();
   return 0;
}

/***********************************************************************
* edit Selection
* gets coordinates for a seletion from user and checks if selection
* is valid before attempting to edit that location.
************************************************************************/
void editSelection(int board [][COLS])
{
   string coords;
   int possible[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int value = 0;
   getCoords(coords);
   coords[0] = toupper(coords[0]);
   switch (coords[0])
   {
      case 'A':
         coords[0] = 0;
         break;
      case 'B':
         coords[0] = 1;
         break;
      case 'C':
         coords[0] = 2;
         break;
      case 'D':
         coords[0] = 3;
         break;
      case 'E':
         coords[0] = 4;
         break;
      case 'F':
         coords[0] = 5;
         break;
      case 'G':
         coords[0] = 6;
         break;
      case 'H':
         coords[0] = 7;
         break;
      case 'I':
         coords[0] = 8;
         break;
   }

   if (isValidSelection(coords, board))
   {
      cout << "What is the value at'" << coords[0] << coords[1]
           << "': ";
      cin >> value;
      getPossibleValues(coords, board, possible);
      bool validValue = false;
      for (int index = 0; index < 9; index++)
      {
         if (value == possible[index])
         {
            board[coords[0]][coords[1]] = value;
            bool validValue = true;
         }
      }
      if (validValue)
         ;
      else
      {
         cout << "ERROR: Value '" << value << "' in square '"
              << coords[0] << coords[1] << "' is invalid\n";
      }
   }
}

/***********************************************************************
* get coordinates
* prompts for coordinates of a square
************************************************************************/
void getCoords(string & coords)
{
   cout << "What are the coordinates of the square: ";
   for (int i = 0; i < 2; i++)
      cin >> coords[i];
}

/***********************************************************************
* show possible values
* based on possible coordinates retrieved, shows possible values
************************************************************************/
void showPossibleValues(int board[][COLS])
{
   string coords;
   int possible[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
   int value = 0;
   getCoords(coords);
   coords[0] = toupper(coords[0]);

   cout << "The possible values for '" << coords[0] << coords[1]
        << "' are: ";

   for (int i = 0; i < 9; i++)
   {
      cout << possible[i]; 
      if (i != 9)
         cout << ", ";
   }
   cout << endl;
}

/***********************************************************************
* get possible values
* this removes invalid values.
************************************************************************/
void getPossibleValues(string & coords, int board[][COLS], int valid[])
{
   // define squares. 
   int square[9][9];
   for (int r = 0; r < 3; r++)
   {
      for (int c = 0; c < 3; c++)
         {
            int value = board[r][c];
            valid[value - 1] = 0;
         }
   }

   // check col
   for (int col = 0; col < COLS; col++)
	{
		int value = board[coords[1]][col];
		valid[value - 1] = 0;
	}
   // check row
   for (int row = 0; row < ROWS; row++)
		{
			int value = board[row][coords[0]];
			valid[value - 1] = 0;
		}
}