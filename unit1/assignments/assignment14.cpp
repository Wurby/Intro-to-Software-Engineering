/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.5 hrs   
*    Actual:     0.10 hrs
*      Hardest part was moving functions above main()
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int questionPeter() {
    cout << "Lord, how oft shall my brother sin against me, and I forgive him?\n"
         << "Till seven times?\n";
    return 0;
}

int responseLord() {
    return 7 * 70;
}

int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}


