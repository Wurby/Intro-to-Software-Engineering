/***********************************************************************
* Program:
*    Assignment 12, Input          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, cs124
* Author:
*    Joshua Pearson
* Summary: 
*    Gets input from user and displays their income.
*
*    Estimated:  0.50 hrs   
*    Actual:     0.25 hrs
*      Annoying having to figure out the cpp syntax. Different from JS
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main asks for user income, then gives message with user input.
 * 
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "Your income is: $"
        << setw(9)
        << income
        << endl;
   return 0;
}
