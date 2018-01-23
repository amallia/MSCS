/********************************************************************************************
File: VLIST.cpp - VLIST class file
Name: Christopher Foley              Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 07-Nov-2016           Due Time: 
Total Points: 100
Assignment: Vectors, Iterators and Templates Chapter 9 

Description: Created project RogerRoger to test Vector class. 

**********************************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "VLIST.h"
using namespace std;
/**********************************************************************************************
  Function Name: VLIST
  Precondition: Constructor has not been invoked.
  Postcondition: count=0, vector size is 0.
  Description: Constructs an instance of a VLIST object.
***********************************************************************************************/
VLIST::VLIST()
{
	cout << "Default Constructor Invoked" << endl;
}
/***********************************************************************************************

  Function Name: VLIST
  Precondition: A VLIST object is being passed by reference.
  Postcondition: A hard copy of a VLIST object has been created.
  Description: Creates a hard copy of a VLIST object.

***********************************************************************************************/

VLIST::VLIST(const VLIST & Org)
{
	cout << "Copy Constructor Invoked" << endl;
	(*this).DB = Org.DB;
	Print();
}
/***********************************************************************************************
  Function Name: ~VLIST
  Precondition: Destructor has not been invoked.
  Postcondition: array DB deleted.
  Description: Deallocates memory of a VLIST object.
***********************************************************************************************/

VLIST::~VLIST()
{
	cout << "Destructor invoked" << endl;
	while (!Is_Empty())
	{
		DB.pop_back();

	}
}

/***********************************************************************************************
  Function Name: Is_Full
  Precondition: VLIST initialized
  Postcondition: VLIST unchanged.
  Description: Returns true if size of list equals capacity.
***********************************************************************************************/
bool VLIST::Is_Full()
{
	cout << "Is_full invoked" << endl;
	return DB.max_size() == DB.capacity();
}
/***********************************************************************************************
  Function Name: Is_Empty()
  Precondition: VLIST initialized.
  Postcondition: VLIST unchanged.
  Description: Returns true if number of elements in list is 0.
***********************************************************************************************/
bool VLIST::Is_Empty()
{
	cout << "Is_Empty invoked " << endl;
	return DB.empty();
}
/***********************************************************************************************
  Function Name: Search
  Precondition: VLIST has been initialized.
  Postcondition: VLIST is unchanged
  Description: Creates a DB string vector to search for a specific string.  Returns the string vector
               if found.
***********************************************************************************************/
vector<string>::iterator VLIST::Search(const string & key)
{	// use <algorithm> template find
	// never mind - since messages need to be output
	// since text is output the following line is not used (keep for reference)
	// return DB.find(DB.begin(), DB.end(), key);

	cout << "Search invoked" << endl;
	vector<string>::iterator it = DB.begin();
	while (it != DB.end() && (*it).compare(key) != 0) it++;

	if (it == DB.end())
	{
		cout << "Item not found: ";
	}
	else
	{
		cout << "Item found: ";
	}
	cout << key << endl;

	return it;
}
/***********************************************************************************************
  Function Name: Insert
  Precondition: Constructor has been invoked.
  Postcondition: string inserted into vector array array DB deleted.
  Description: Deallocates memory of a VLIST object.
***********************************************************************************************/
void VLIST::Insert(const string & key)
{
	int index = 0;
	cout << "Insert Invoked" << endl;

	Print();

	DB.push_back(key);			// put at end of vector list and use swap to position
	index = DB.size()-1; 		// make index zero relative
	while ((index > 0) && (DB[index-1].compare(DB[index]) > 0)) DB[index-1].swap(DB[index]);

	Print();
}
/***********************************************************************************************
  Function Name: Remove
  Precondition: Constructor has been invoked.
  Postcondition: single DB element deleted.
  Description: Deallocates element of a VLIST object.
***********************************************************************************************/
void VLIST::Remove(const string & key)
{ 							// not the most elegant procedure, but swap elements to put
							// desired element at end of vector list then use pop_back
	cout << "Remove invoked" << endl;
	Print();

	unsigned index=0;
	if (DB.empty()) return;	// trivial case
	while (index < DB.size()-1)
	{
		if (DB[index].compare(key) == 0)
		{
			DB[index].swap(DB[index+1]);
		}
		index++;
	}

	if (DB.back().compare(key) == 0) DB.pop_back();

	Print();
}
/***********************************************************************************************
  Function Name: Print
  Precondition: Constructor has been invoked.
  Postcondition: no changes.
  Description: Print the string contents of VLIST array one item per line by streaming to cout
***********************************************************************************************/
void VLIST::Print()
{
	vector<string>::iterator it = DB.begin();
	while (it != DB.end()) cout << *it++ << endl;
}
