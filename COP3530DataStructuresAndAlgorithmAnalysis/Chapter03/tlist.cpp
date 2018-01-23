/********************************************************************************************

Name: Christopher Foley             Z#: Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Assess C++ skills using C++ strings and dynamic arrays

Description: TLIST provides mechanisms to store search, remove and add strings.
			 strings are stored in an array in lexicographic order.

*********************************************************************************************/


#include "tlist.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace  std;

/*****************************************************************************
 * TLIST::TLIST - construct a TLIST element
 *
 * Precondition: strings to be input are in a text file named "myData.txt"
 * 				 located in the current directory.
 *
 * Postcondition: a TLIST element is created with a DB array in lexicographic order
 *
 */
TLIST::TLIST() {
	cout << "Default Constructor Invoked" << endl;
	this->capacity = TLIST_CAP; //capacity;
	count = 0;
	DB = new string[capacity];
/* open data files and read from file.
 * this should be done as a separate function but the example in class
 * did it this way so that's what was done
 */
	string i;
	ifstream in;
	in.open("myData.txt");

	in >> i;		// prime pump  eof not set until first read after all data
					// read
	while(!in.eof())
	{
		Insert(i);
		in >> i;
	}
	in.close();

}


/*****************************************************************************
 * TLIST::~TLIST - 	TLIST elements are deallocated and returned to memory
 *
 * Precondition:
 *
 * Postcondition:	DB and string objects are deleted and memory freed
 *
 */
TLIST::~TLIST() {
	cout << "Destructor Invoked" << endl;
	delete [] DB;
}

/*****************************************************************************
 * TLIST::Is_Empty - Check if TLIST is empty
 *
 * Precondition:	none
 *
 * Postcondition:	returns true if TLIST is empty, otherwise false.
 *
 */
bool TLIST::Is_Empty() {
	cout << "Is_Empty Invoked" << endl;
	return count == 0;} ;         //return true if empty; otherwise false


/*****************************************************************************
 * TLIST::Is_Full - Check if TLIST is full
 *
 * Precondition:	None.
 *
 * Postcondition:	Returns true if number of elements in TLIST equals
 * 					capacity, otherwise false.
 *
 */
bool TLIST::Is_Full() {
	cout << "Is_Full Invoked" << endl;
	return count == capacity; };   //return true if full; otherwise false


/*****************************************************************************
 * TLIST::Search -	Locate an element in the TLIST
 *
 * Precondition:	None
 *
 * Postcondition:	Returns true if the item indicated by target is present
 * 					in the list, otherwise false.
 *
 *
 */
int TLIST::Search(const string &target) //returns the location of the string in the dynamic array
{
	cout << "Search Invoked" << endl;
	int index = count -1;		// start at end then work until found or index < 0
	while ((index >= 0) && (target.compare(DB[index]) != 0) )
		index--;
	cout << "Item";
	if (index >= 0)
		cout << " ";
	else
		cout << " Not " ;
	cout << "Found: " << target << endl;
	return index;
}


/*****************************************************************************
 * TLIST::Insert - 	Insert an element into the TLIST
 *
 * Precondition:	none
 *
 * Postcondition:	If the list is not full, the string pointed to by the
 * 					input parameter is inserted into the TLIST array in
 * 					ascending lexicographic order.
 *
 */
void TLIST::Insert(const string & key)  //add key to dynamic array if not full; otherwise //doubles the size of the array and adds key
{
	cout << "Insert Invoked" << endl;
    List();
	int index = count;
	if (!Is_Full())
	{
		string *temp;
		capacity *=2;
		temp = new string[capacity];
		for (int i = 0; i<count; i++)
			temp[i] = DB[i];
		delete [] DB;
		DB = temp;
	}

		while ((index > 0) && (key.compare(DB[index-1]) <=0))
		{
			DB[index] = DB[index-1];
			index--;
		}
		DB[index] = key;
		count++;

	List();
}

TLIST & TLIST::operator+(string &key)
{
	this->Insert(key);
	return this;
}
/*****************************************************************************
 * TLIST::Remove() - Remove an element from TLIST
 *
 * Precondition: 	None
 *
 * Postcondition:	If the string pointed to by the input parameter is present
 * 					in the list it will be removed and list elements shifted.
 * 					Otherwise nothing will happen.
 *
 */
void TLIST::Remove(const string & key) //removes key from dynamic array if it is there; //otherwise prints a message stating it was not in dynamic array
{
	cout << "Remove Invoked" << endl;
    List();
	int index = count-1;
	while ((index >= 0) && (key.compare(DB[index]) != 0)) index--;
	if (index >= 0)
	{
		while (index < count)
		{
			DB[index] = DB[index+1];
			index++;
		}
		count--;
		DB[count] = "";
	}
	List();
}



/*****************************************************************************
 * TLIST::Display -	Single line formatted display of TLIST
 *
 * Precondition:
 *
 * Postcondition:	Creates a single line output of the TLIST array enclosed in
 * 					brackets  "[ ]".
 *
 */
void TLIST::Display() //displays the contents of the dynamic array
{
	cout << "[";
	for (int i = 0; i< count; i++)
	{
		cout << DB[i];
		if (i < count-1) cout << ", ";
	}
	cout << "]" << endl;

}


/*****************************************************************************
 * TLIST::List	-	Private function to list the elements of the TLIST
 *
 * Precondition: none
 *
 * Postcondition:	List the elements in the TLIST array, one element per line.
 *
 */
void TLIST::List()		// list the contents of the array
{
	for (int i = 0; i < count; i++)
	{
		cout << DB[i] << endl;
	}
}

