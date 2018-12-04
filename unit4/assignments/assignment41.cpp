/***********************************************************************
* Program:
*    Assignment 41, allocating memory          (e.g. Assignment 10, Hello World)
*    Brother Honeycutt, CS124
* Author:
*    Joshua Pearson
* Summary: 
*    asks for a number of characters, then allocates memory and 
*    prints the number of characters.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Managing errors.
************************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
 * Main Function
 * asks for number of characters, asserts the number can be used
 * to allocate memory, then asks for text, then displays text.
 ***********************************************************************/
int main()
{  
int size; 
cout << "Number of characters: ";
cin >> size; 
if (size < 1)
{
   cout << "Allocation failure!\n";
   return 1;
}
char * text = new(nothrow) char [size + 1]; 

cout << "Enter Text: ";
cin.ignore();
cin.getline(text, size + 1); 
cout << "Text: " << text << endl;

return 0;
}