/***********************************************************************
* Program:
*    Assignment 30, Array Syntax          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Averages grades that are taken in an array.
*
*    Estimated:  0.5 hrs   
*    Actual:     2 hrs
*      Averaging the contents of the array.
************************************************************************/

#include <iostream>
using namespace std;

// Gets grades
void getGrades(int grades[])
{
   for (int i; i < 10; i++)
   {
      cout << "Grade "
           << i + 1
           << ": ";
      cin >> grades[i];
   }
   return;
}

// Averages grades and returns result
int averageGrades(int grades[])
{
   int sumOfGrades, calculatedAverage;
   for (int i; i < 10; i++)
   {
      sumOfGrades += grades[i];
   }
   calculatedAverage = sumOfGrades / 10;
   return calculatedAverage;
}


// calls functions and displays the result.
int main()
{
   int grades[10], averagedGrades;
   getGrades(grades);
   cout << "Average Grade: "
        << averageGrades(grades)
        << "%"
        << endl;
   return 0;
}
