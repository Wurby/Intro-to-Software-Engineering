/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditions          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Takes a grade percentage and spits out a letter grade.
*
*    Estimated:  1.0 hrs   
*    Actual:     3.5 hrs
*      Return '*' really threw me off. Have no idea what it is for.
************************************************************************/

#include <iostream>
using namespace std;

// Computes grade sign.
void computeGradeSign(int gradePercentage)
{
   char sign;
   
   if (gradePercentage >= 97)
   {
      cout << endl;
   }
   else if (gradePercentage <= 60)
   {
      cout << endl;
   }
   else
   {
      switch (gradePercentage % 10)
      {
         case 9:
         case 8:
         case 7:
            sign = '+';
            cout << sign << endl;
            break;
         case 6:
         case 5:
         case 4:
         case 3: 
            cout << endl;
            break;
         default:
            sign = '-';
            cout << sign << endl;
            break;
      }
   }
   
}

// Computes letter grade
void computeLetterGrade(int gradePercentage)
{
   char letter;
   switch (gradePercentage / 10)
   {
      case 10:
      case 9:
         letter = 'A';
         break;
      case 8:
         letter = 'B';
         break;
      case 7:
         letter = 'C';
         break;
      case 6:
         letter = 'D';
         break;
      default:
         letter = 'F';
   }
   cout << gradePercentage << "% is "
        << letter;
}

// Calls respective functions and prints information
int main()
{
   int numGrade;

   cout << "Enter number grade: ";
   cin >> numGrade;
   computeLetterGrade(numGrade);
   computeGradeSign(numGrade);
   
   
   return 0;
}
