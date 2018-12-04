/***********************************************************************
* Program:
*    Assignment 33, Pointers          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Something something something pointers
*    This application will get balances for sue and sam and then
*    calculate who is paying for the date.
*    Estimated:  0.5 hrs   
*    Actual:     1.0 hrs
*      Syntax for pointers.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Asks for sam's balance
void getSamBalances(double *pSamBalance)
{
   cout << "What is Sam's balance? ";
   cin >> *pSamBalance;
}

// Asks for sue's balance
void getSueBalances(double *pSueBalance)
{
   cout << "What is Sue's balance? ";
   cin >> *pSueBalance;
}

// Gets date values and reduces balance.
void calculateDateCosts(double *pSamBalance, double *pSueBalance)
{
   double tempBalance = 0;
   double combinedBalance = 0;
   cout << "Cost of the date:\n"
        << "\tDinner:    ";
   cin >> tempBalance;
   combinedBalance += tempBalance;
   cout << "\tMovie:     ";
   cin >> tempBalance;
   combinedBalance += tempBalance;
   cout << "\tIce cream: ";
   cin >> tempBalance;
   combinedBalance += tempBalance;

   if (*pSamBalance > *pSueBalance)
   {
      *pSamBalance -= combinedBalance;
   }
   else
   {
      *pSueBalance -= combinedBalance;
   }
}

// Calls the other functions
int main()
{
   std::cout << std::fixed;
   std::cout << std::setprecision(2);
   double samBalance, sueBalance;
   double * pSamBalance;
   double * pSueBalance; 
   pSamBalance = &samBalance;
   pSueBalance = &sueBalance;
   getSamBalances(pSamBalance);
   getSueBalances(pSueBalance);
   calculateDateCosts(pSamBalance, pSueBalance);
   cout << "Sam's balance: $"
        << *pSamBalance
        << endl
        << "Sue's balance: $"
        << *pSueBalance
        << endl;


   return 0;
}
