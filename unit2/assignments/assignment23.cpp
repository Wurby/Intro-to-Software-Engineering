/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    the answer of multiples less than 100 is added together and
*    output based on the input provided by el program user
*
*    Estimated:  0.5 hrs   
*    Actual:     0.33 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prompts for multiple
 ************************************************************************/
int getMultiple()
{
   cout << "What multiples are we adding? ";
   int multiple;
   cin >> multiple;
   return multiple;
}
 
/**********************************************************************
 * Calculates the sum of the multiples
 ************************************************************************/
int calculateSum(int multiple)
{
   int answer = 0;

   for (int count = multiple; count < 100; count += multiple)
   {
      answer += count;
   }

   return answer;
}

/**********************************************************************
 * pukes out the calculation based on the multiple provided
 ************************************************************************/
void display(int multiple, int answer)
{
   cout << "The sum of multiples of "
        << multiple
        << " less than 100 are: "
        << answer
        << endl;
 
 
   return;
}

/**********************************************************************
 * Calls all functions.
 ************************************************************************/
int main()
{
   int multiple = getMultiple();
   int answer = calculateSum(multiple);
 
 
   display(multiple, answer);
 
 
   return 0;
}
