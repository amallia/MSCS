/********************************************************************************************

Name:              Z#:                            
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  

Description: 

*********************************************************************************************/


#include <string>
#include <iostream>
#include "TLIST.h"

using namespace std;

int main()
{
	TLIST myArray;

	myArray.Display();
	

	if(myArray.IsEmpty())
		cout << "ARRAY IS EMPTY" << endl;
	else
		cout << "ARRAY IS NOT EMPTY" << endl;

	cout << endl;


	if(myArray.IsFull())
		cout << "ARRAY IS FULL" << endl;
	else
		cout << "ARRAY IS NOT FULL" << endl;
	
	cout << endl;

	myArray.Search("stringtrist");

	cout << endl;
	
	myArray.Remove("defghiiijjjiiijj");
	cout << endl;
	myArray.Remove("ab");
	cout << endl;
	myArray.Remove("stringtrist");
	cout << endl;
	myArray.Remove("abczzzabcabc");
	cout << endl;
	myArray.Remove("cdeerxre");
	cout << endl;
	myArray.Remove("abcdeabaeeeabrxre");

	cout << endl;

	for(int i = 0; i < 6; i++)
	{
		myArray.Insert("abc");
		cout << endl;
	}
	
	if(myArray.IsFull())
		cout << "ARRAY IS FULL" << endl;
	else
		cout << "ARRAY IS NOT FULL" << endl;
	
	cout << endl;

	return 0;
}
