/***********************************************************************
* Program:
*    Assignment 43, Command Line          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This will take in command line argumetns and convert them to
*    feet if they are numbers.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.2 hrs
*      most difficult bit was the atof() thing and proper use
************************************************************************/
#include <cstdlib> 
#include <iostream>
#include <string>
using namespace std;

float convertFeetToMeters(float feet);

/**********************************************************************
 * main
 * This will take in parameters from the comandline, and convert them
 * to feet if numbers by iterating through them.
 ***********************************************************************/
int main(int argc, char *argv[])
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(1);
	
	for (int i = 1; i < argc; i++)
	{
		float feet = atof(argv[i]);
		float meters = convertFeetToMeters(feet);
		
		cout << feet << " feet is " << meters << " meters" << endl;
	}
}

/**********************************************************************
 * Convert feet to meters
 * converts feet provided to meters.
 ***********************************************************************/
float convertFeetToMeters(float feet)
{
	return feet * 0.3048;
}