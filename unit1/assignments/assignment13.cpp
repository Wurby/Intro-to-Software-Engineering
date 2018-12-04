/***********************************************************************
* Program:
*    Assignment 13, Expressions          
*    Brother Honeycutt, CS124
* Author:
*    Joshua
* Summary: 
*    Calculates Fahreheit to Celsius.
*    
*
*    Estimated:  0.5 hrs   
*    Actual:     1 hrs
*      Learning how casting works and remembering the little things.
************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/**********************************************************************
 * Takes user input and spits out calculation.
 ***********************************************************************/
int main()
{
	cout.setf(ios::fixed);
	cout.precision(0);
	double fahrenheit;
	double celsius;
	cout << "Please enter Fahrenheit degrees: ";
	cin  >> fahrenheit;
	celsius = (float)5/(float)9*((float)fahrenheit - (float)32);
	cout << "Celsius: " << celsius;
	cout << endl;
   return 0;
}
