/***********************************************************************
* Program:
*    Assignment 21, Dubugging          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    This is a stub program that calculates vehicle cost
*   
*
*    Estimated:  0.5 hrs   
*    Actual:     0.75 hrs
*      It wasn't difficult
************************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
 * Displays the costs.
 ***********************************************************************/
double display(double costPeriodic, double costUsage)
{
   cout << "Success\n";
   return 0;
}
/**********************************************************************
 * Prompts Mileage
 ***********************************************************************/
double promptMileage()
{
   double cost;
   return cost;
}
/**********************************************************************
 * Prompts gas
 ***********************************************************************/
double promptGas()
{
   double cost;
   return cost;
}
/**********************************************************************
 * prompts repairs
 ***********************************************************************/
double promptRepairs()
{
   double cost;
   return cost;
}
/**********************************************************************
 * prompts tires
 ***********************************************************************/
double promptTires()
{
   double cost;
   return cost;
}
/**********************************************************************
 * promptes devaluation
 ***********************************************************************/
double promptDevalue()
{
   double cost;
   return cost;
}
/**********************************************************************
 * prompts insurance
 ***********************************************************************/
double promptInsurance()
{
   double cost;
   return cost;
}
/**********************************************************************
 * prompts parking
 ***********************************************************************/
double promptParking()
{
   double cost;
   return cost;
}
/**********************************************************************
 * calculates periodic costs
 ***********************************************************************/
double getPeriodicCost()
{
   double devaule = promptDevalue();
   double insurance = promptInsurance();
   double parking = promptParking();
   double costPeriodic;
   return costPeriodic;
}
/**********************************************************************
 * calculates usage cost
 ***********************************************************************/
double getUsageCost()
{
   double mileage = promptMileage();
   double gas = promptGas();
   double repairs = promptRepairs();
   double tires = promptTires();
   double usageCost = mileage + gas + repairs + tires;
   return usageCost;
}
/**********************************************************************
 * calls all functions
 ***********************************************************************/
int main()
{
   double costPeriodic = getPeriodicCost();
   double costUsage = getUsageCost();
   display(costPeriodic, costUsage);

   return 0;
}