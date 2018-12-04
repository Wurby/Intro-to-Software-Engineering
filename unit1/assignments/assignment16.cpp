/***********************************************************************
* Program:
*    Assignment 16, IF Statements          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Prompts user for income and returns their tax percentage.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.25 hrs
*      Data flow was difficult to follow at first.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* This calculates which tax bracket you're income warrants.
************************************************************************/
float computeTax(float income) {
   int incomePercentage;

   if (income >= 336550) 
      incomePercentage = 35;
      else if (income >= 188450)
      incomePercentage = 33;
      else if (income >= 123700)
      incomePercentage = 28;
      else if (income >= 61300)
      incomePercentage = 25;
      else if (income >= 15100)
      incomePercentage = 15;
      else
      incomePercentage = 10;
   return incomePercentage;
}

/**********************************************************************
 * Prompts user for income, hands data off to compute function
 * prints all details, and computations of tax info. 
 ***********************************************************************/
int main()
{
   float userIncome;
   double taxBracket;
   cout << "Income: ";
   cin >> userIncome;
   taxBracket = computeTax(userIncome);
   cout << "Your tax bracket is " << taxBracket << "%\n";
   return 0;
}
