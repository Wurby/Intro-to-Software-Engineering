/***********************************************************************
* Program:
*    Project 02, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    your name
* Summary: 
*    A simple budgeting app that checks if you are on track depending on
*    your input in given areas.
*    Estimated:  2.0 hrs   
*    Actual:     1.75 hrs
*      Remebering how data flows.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * gets income
 ***********************************************************************/
double getIncome() {
   double income;
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}
/**********************************************************************
 * gets budgeted expenses
 ***********************************************************************/
double getBudgetedExpenses() {
   double budgetedExpenses;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetedExpenses;
   return budgetedExpenses;
}
/**********************************************************************
 * gets actual expenses
 ***********************************************************************/
double getActualExpenses() {
   double actualExpenses;
   cout << "\tYour actual living expenses: ";
   cin >> actualExpenses;
   return actualExpenses;
}
/**********************************************************************
 * gets taxes withheld
 ***********************************************************************/
double getTaxesWithheld() {
   double taxesActual;
   cout << "\tYour actual taxes withheld: ";
   cin >> taxesActual;
   return taxesActual;
}
/**********************************************************************
 * gets tithing donated
 ***********************************************************************/
double getTithingDonated() {
   double tithesDonated;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithesDonated;
   return tithesDonated;
}
/**********************************************************************
 * Gets other Expenses
 ***********************************************************************/
float getOtherExpenses() {
   float otherExpenses;
   cout << "\tYour actual other expenses: ";
   cin >> otherExpenses;
   return otherExpenses;
}
/**********************************************************************
 * calculate taxes placeholder
 ***********************************************************************/
float  calculateTaxes(float income) {
   return 0;
}
/**********************************************************************
 * Calculates tithing based on income
 ***********************************************************************/
float calculateTithes(float income) {
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   income = income/10;
   return income;
}
/**********************************************************************
 * displays data on console
 ***********************************************************************/
int displayBudget(float otherExpenses, float tithes, float taxes, float calculatedTithes, float calculatedTax, float actualExpenses, float budgetedExpenses, float income) {
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   float budgetedSum = income - calculatedTithes - calculatedTax - budgetedExpenses;
   float actualSum = income - otherExpenses - tithes - taxes - actualExpenses;
   cout << endl;
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem             "
        << "     Budget    "
        << "      Actual\n";
   cout << "\t==============="
        << " ==============="
        << " ===============\n";
   cout << "\tIncome          "
        << "$"
        << setw(11)
        << income
        << "    $"
        << setw(11)
        << income
        << endl;
   cout << "\tTaxes           "
        << "$"
        << setw(11)
        << calculatedTax
        << "    $"
        << setw(11)
        << taxes
        << endl;
   cout << "\tTithing         "
        << "$"
        << setw(11)
        << calculatedTithes
        << "    $"
        << setw(11)
        << tithes
        << endl;
   cout << "\tLiving          "
        << "$"
        << setw(11)
        << budgetedExpenses
        << "    $"
        << setw(11)
        << actualExpenses
        << endl;
   cout << "\tOther           "
        << "$"
        << setw(11)
        << budgetedSum
        << "    $"
        << setw(11)
        << otherExpenses
        << endl;
   cout << "\t==============="
        << " ==============="
        << " ===============\n";
   cout << "\tDifference      "
        << "$"
        << setw(11)
        << 0.00
        << "    $"
        << setw(11)
        << actualSum
        << endl;

}


/**********************************************************************
 * Triggers all other functions.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   float cinIncome, budgetedExpenses,  actualExpenses, calculatedTax, tax, tithesDonated, calculatedTithes, otherExpenses;
   cinIncome = getIncome();
   budgetedExpenses = getBudgetedExpenses();
   actualExpenses = getActualExpenses();
   calculatedTax = calculateTaxes(cinIncome);
   calculatedTithes = calculateTithes(cinIncome);
   tax = getTaxesWithheld();
   tithesDonated = getTithingDonated();
   otherExpenses = getOtherExpenses();

   displayBudget(otherExpenses, tithesDonated, tax, calculatedTithes, calculatedTax, actualExpenses, budgetedExpenses, cinIncome);
   
      return 0;
}
