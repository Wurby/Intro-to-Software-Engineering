/***********************************************************************
* Program:
*    Assignment 11, Output
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    Outputs a simple monthy budget.
*
*    Estimated:  1 hrs   
*    Actual:     1.25 hrs
*      Making sure everything aligns correctly and learning cpp syntax.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main will display monthly budget to console.
 ***********************************************************************/
int main()
{
   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "\tItem       "
        << "    Projected\n";
   cout << "\t============="
        << "  ==========\n";
   cout << "\tIncome       "
        << "  $"
        << setw(9)
        << 1000.00
        << endl;
   cout << "\tTaxes        "
        << "  $"
        << setw(9)
        << 100.00
        << endl;
   cout << "\tTithing      "
        << "  $"
        << setw(9)
        << 100.00
        << endl;
   cout << "\tLiving       "
        << "  $"
        << setw(9)
        << 650.00
        << endl;
   cout << "\tOther        "
        << "  $"
        << setw(9)
        << 90.00
        << endl;
    cout << "\t============="
         << "  ==========\n";
    cout << "\tDelta        "
         << "  $"
         << setw(9)
         << 60.00
         << endl;
   return 0;
}
