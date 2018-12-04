/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 10, Hello World)
*    Brother {Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;


int calculateOffset(int month, int year)
{
   int numDays, offset;
   
   if (year != 1753)
   {
      for (int i = 1753; i < year; i++)
      {
         if (i % 4 == 0)
            numDays++;
         if (i % 100 == 0)
            numDays--;
         if (i % 400 == 0)
            numDays++;

         numDays += 365;
      }
   }

   if (month == 2)
      numDays += 31;
   if (month == 3)
      numDays += 59;
   if (month == 4)
      numDays += 90;
   if (month == 5)
      numDays += 120;
   if (month == 6)
      numDays += 151;
   if (month == 7)
      numDays += 181;
   if (month == 8)
      numDays += 212;
   if (month == 9)
      numDays += 243;
   if (month == 10)
      numDays += 273;
   if (month == 11)
      numDays += 304;
   if (month == 12)
      numDays += 335;
   

   return numDays % 7;

}
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int month, year;
   cout << "enter month: ";
   cin >> month;
   cout << "enter year: ";
   cin >> year;
   cout << "Offset: "
        << calculateOffset(month, year)
        << endl;
   return 0;
}
