/***********************************************************************
* Program:
*    Assignment 31, Array Design          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Averages grades that are taken in an array and caring for fringe
*    issues, like no assignment or none total.
*    Estimated:  0.5 hrs   
*    Actual:     0.75 hrs
*      Learned that int that are init a value are given "garbage value"
************************************************************************/

#include <iostream>
using namespace std;

// Gets grades
void getGrades(int grades[])
{
   for (int i = 0; i < 10; i++)
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
   int sumOfGrades = 0, calculatedAverage = 0, numberOfGrades = 0;
   for (int index = 0; index < 10; index++)
   {
      if (grades[index] > 0)
      {
         sumOfGrades += grades[index];
         numberOfGrades++;
      }
      
   }
   if (numberOfGrades == 0)
      return 0;
   else 
   {
      calculatedAverage = sumOfGrades / numberOfGrades;
      return calculatedAverage;
   }
}


// calls functions and displays the result.
int main()
{
   int grades[10], averagedGrades;
   getGrades(grades);

   averagedGrades = averageGrades(grades);
  
   cout << "Average Grade: ";
   if (averagedGrades == 0) 
      cout << "---";
   else
      cout << averagedGrades;
   cout << "%"
        << endl;
   return 0;
}
