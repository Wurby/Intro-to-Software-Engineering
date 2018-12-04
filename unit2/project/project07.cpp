/***********************************************************************
* Program:
*    Project 07, Calendar          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This will request a month and year, then display 
*    a calendar based on that input.
*    Estimated:  4.75 hrs   
*    Actual:     10.0 hrs
*      Had a lot of problems with offset being redefined to the year
*      never found out why. ended up redefining a variable to 0 and 
*      then it suddenly started working. No idea, nothing should
*      have affected numDays, maybe I don't understand scope. Sigh. 
************************************************************************/

#include <iostream>
using namespace std;

// Checks month and prints month and year
int displayMonth(int month, int year)
{
    if (month == 1)
   {
      cout << "January, "
           << year
           << endl;
   }
   else if (month == 2)
   {
      cout << "February, "
           << year
           << endl;
   }
   else if (month == 3)
   {
      cout << "March, "
           << year
           << endl;
   }
   else if (month == 4)
   {
      cout << "April, "
           << year
           << endl;
   }
   else if (month == 5)
   {
      cout << "May, "
           << year
           << endl;
   }
   else if (month == 6)
   {
      cout << "June, "
           << year
           << endl;
   }
   else if (month == 7)
   {
      cout << "July, "
           << year
           << endl;
   }
   else if (month == 8)
   {
      cout << "August, "
           << year
           << endl;
   }
   else if (month == 9)
   {
      cout << "September, "
           << year
           << endl;
   }
   else if (month == 10)
   {
      cout << "October, "
           << year
           << endl;
   }
   else if (month == 11)
   {
      cout << "November, "
           << year
           << endl;
   }
   else
   {
      cout << "December, "
           << year
           << endl;
   }
}

// This will display the table based on data provided.
int displayTable(int daysInMonth, int offset, int month, int year)
{
   int weekCounter;
   int initOffset = 0;
   weekCounter = offset + 1;
   cout << endl;
   displayMonth(month, year);
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
   else
   {
      weekCounter = 0;
      initOffset = 0;
   }
   for (int i = 1; i <= daysInMonth; i++)
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

// Requests month and checks if valid
int getMonth() 
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;
   while (month > 12 || month < 1)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

// Requests year and checks if valid
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;
   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
   }
   return year;
}

// calculates how many days in a month
int getMonthDays(int month, int year)
{
   int numDays;
   if (month == 1)
      numDays = 31;
      else if (month == 2)
      {
         numDays = 28;
         if (year % 4 == 0)
            ++numDays;
         if (year % 100 == 0)
            --numDays;
         if (year % 400 == 0)
            ++numDays;
      }
      else if (month == 3)
         numDays = 31;
      else if (month == 4)
         numDays = 30;
      else if (month == 5)
         numDays = 31;
      else if (month == 6)
         numDays = 30;
      else if (month == 7) 
         numDays = 31;
      else if (month == 8)
         numDays = 31;
      else if (month == 9)
         numDays = 30;
      else if (month == 10)
         numDays = 31;
      else if (month == 11)
         numDays = 30;
   else
   numDays = 31;

   return numDays;
}

// Calculate offset
int calculateOffset(int month, int year)
{
   int numDays = 0; 
   int offset;

   for (int i = 1753; i < year; i++)
   {
      if (i % 4 == 0)
         ++numDays;
      if (i % 100 == 0)
         --numDays;
      if (i % 400 == 0)
         ++numDays;

      numDays += 365;
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
      numDays += 334;

   offset = numDays % 7;
   return offset;

}

// Calls all functions and provides data to displayTable
int main()
{
   int year;
   int off;
   int daysInMonth;
   int month;
   month = getMonth();
   year = getYear();
   off = calculateOffset(month, year);
   daysInMonth = getMonthDays(month, year);
   displayTable(daysInMonth, off, month, year);
   return 0;
}
