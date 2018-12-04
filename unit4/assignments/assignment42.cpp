/***********************************************************************
* Program:
*    Assignment 42, String Class          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This code generates the dem bones song.
*    
*
*    Estimated:  0.5 hrs   
*    Actual:     0.25 hrs
*      Learning string syntax.
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * GENERATE SONG                                                                
 * This generates the song based on the sting parameter and number
 * provided by the caller.                                                 
 ********************************************************************/
string generateSong(string list[], int num)
{
	string output;
	for (int i = 0; i < num - 1; i++)
	{
		output += list[i] + " bone connected to the " +  list[i + 1] + " bone\n";
	}

	return output;
}

/**********************************************************************         
* MAIN                                                                         
* Main is the backbone of the dem bones song generator.                                                     
***********************************************************************/
int main()
{
	string list[9] =
	{
		"toe",
		"foot",
		"leg",
		"knee",
		"hip",
		"back",
		"neck",
		"jaw",
		"head"
	};

	// generate the song                                                         
	string song = generateSong(list, 9);

	// display the results                                                       
	cout << song;

	return 0;
}