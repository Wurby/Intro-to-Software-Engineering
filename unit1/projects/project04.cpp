/***********************************************************************
* Program:
*    Project 04, Monthly Budget          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    A simple budgeting app that checks if you are on track depending on
*    your input in given areas.
*    Estimated:  4.0 hrs   
*    Actual:     2 hrs
*      Figuring out proper usage of data types.
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
double getOtherExpenses() {
   double otherExpenses;
   cout << "\tYour actual other expenses: ";
   cin >> otherExpenses;
   return otherExpenses;
}

/**********************************************************************
 * calculate taxes
 ***********************************************************************/
double  calculateTaxes(double income) {
   double yearlyIncome = income * 12;
   double yearlyTax;
   double monthlyTax;

   if (yearlyIncome < 15100)
		yearlyTax = yearlyIncome * 0.10;
	else if (yearlyIncome < 61300)
		yearlyTax = 1510 + 0.15 *(yearlyIncome - 15100);
	else if (yearlyIncome < 123700)
		yearlyTax = 8440 + 0.25 *(yearlyIncome - 61300);
	else if (yearlyIncome < 188450)
		yearlyTax = 24040 + 0.28 *(yearlyIncome - 123700);
	else if (yearlyIncome < 336550)
		yearlyTax = 42170 + 0.33 *(yearlyIncome - 188450);
	 else 
		yearlyTax = 91043 + 0.35 *(yearlyIncome - 336550);

   monthlyTax = yearlyTax / 12;
   return monthlyTax;
}

/**********************************************************************
 * Calculates tithing based on income
 ***********************************************************************/
double calculateTithes(double income) {
   income = income / 10;
   return income;
}

/**********************************************************************
 * displays data on console
 ***********************************************************************/
int displayBudget(double otherExpenses, double actualTithes, double actualTaxes, double calculatedTithes, double calculatedTax, double actualExpenses, double budgetedExpenses, double income) {
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   double budgetedSum = income - calculatedTithes - calculatedTax - budgetedExpenses;
   double actualSum = income - otherExpenses - actualTithes - actualTaxes - actualExpenses;
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
        << actualTaxes
        << endl;
   cout << "\tTithing         "
        << "$"
        << setw(11)
        << calculatedTithes
        << "    $"
        << setw(11)
        << actualTithes
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
   double cinIncome, budgetedExpenses,  actualExpenses, calculatedTax, tax, tithesDonated, calculatedTithes, otherExpenses;
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
