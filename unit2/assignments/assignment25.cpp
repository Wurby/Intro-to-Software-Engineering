/***********************************************************************
* Program:
*    Assignment 25, Loop Design          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This will request number of days and offset, then display 
*    a calendar based on that input.
*    Estimated:  0.75 hrs   
*    Actual:     1.0 hrs
*      Determining where to put the empty space.
************************************************************************/

#include <iostream>
using namespace std;
// This will display the table based on data provided.
int displayTable(int numDays, int offset)
{
   int weekCounter;
   int initOffset = 0;
   weekCounter = offset + 1;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
   if (offset != 6)
   {
      cout << "    ";
      while (initOffset < offset)
      {
         cout << "    ";
         initOffset++;
      }
   }
   if (offset == 6)
   {
      weekCounter = 0;
      initOffset = 0;
   }
   for (int i = 1; i <= numDays; i++)
   {
      if (weekCounter == 7)
         {
            cout << endl;
            weekCounter = 0;
         }
      cout << "  ";
      if (i < 10)
         cout << " ";
      cout << i;
      weekCounter++;
   }
   cout << endl;
   return 0;
}


// asks for days and offset then calls displayTable
int main()
{
   int numDays, offset;
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> offset;
   displayTable(numDays, offset);
   return 0;
}
