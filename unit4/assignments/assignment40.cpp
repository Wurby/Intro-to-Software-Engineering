/***********************************************************************
* Program:
*    Assignment 40, Multidemensional array          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Reads a file, displays it in tic tac toe grid, writes file again.
*
*    Estimated:  1.0 hrs   
*    Actual:     12 hrs
*      Writing the file, tbh. Not a fan of it.
************************************************************************/

#include <fstream>
#include <iostream>

using namespace std;

#define ROWS 3
#define COLS 3

void getFilename(char filename[]);
void loadFile(char filename[], char game[][COLS]);
void displayGame(char game[][COLS]);
void getSaveFilename(char filename[]);
void saveGame(char filename[], char game[][COLS]);

/**********************************************************************
 * main
 * calls all functions and passes data.
 ***********************************************************************/
int main() {
	char filename[256];
	char game[ROWS][COLS];
	
	getFilename(filename);
	loadFile(filename, game);
	displayGame(game);
	
	getSaveFilename(filename);
	saveGame(filename, game);
}

/**********************************************************************
 * display game
 * displays data from 2d array provided.
 ***********************************************************************/
void displayGame(char game[][COLS])
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			cout << " "
				 << (game[r][c] == '.' ? ' ' : game[r][c])
				 << " ";
			if (c < COLS - 1)
				cout << "|";
		}
		cout << endl;
		if (r < ROWS - 1)
			cout << "---+---+---" << endl;
	}
	
}

/**********************************************************************
 * load file
 * loads file into 2d array.
 ***********************************************************************/
void loadFile(char filename[], char game[][COLS])
{
	ifstream fin(filename);
	
	if (fin.fail()){
		return;
	}

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			fin >> game[r][c];
		}
	}
	fin.close();
}

/**********************************************************************
 * get filename
 * 
 ***********************************************************************/
void getFilename(char filename[])
{
	cout << "Enter source filename: ";
	cin >> filename; 
}

/**********************************************************************
 * save game
 * Saves 2d array into file.
 ***********************************************************************/
void saveGame(char filename[], char game[][COLS])
{
	ofstream fout(filename);
		
		if (fout.fail())
			return;
			
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				fout << game[r][c];
				if (c < COLS -1)
					fout << " ";
			}
			if (r < ROWS - 1)
				fout << endl;
		}
      cout << "File written\n";
		fout.close();
}

/**********************************************************************
 * get save filname
 * requests filename.
 ***********************************************************************/
void getSaveFilename(char filename[])
{
	cout << "Enter destination filename: ";
	cin >> filename;
}