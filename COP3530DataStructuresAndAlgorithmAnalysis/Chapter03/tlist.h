/********************************************************************************************
TLIST.h

Name: Christopher Foley             Z#: 15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Assess C++ skills using C++ strings and dynamic arrays

Description: TLIST provides mechanisms to store search, remove and add strings.
			 strings are stored in an array in lexicographic order.

Operations:
			constructor: reads strings from "myData.txt and inserts into list
			destructor:  frees memory allocated for TLIST array.
			Is_Full: 	 returns true if array is full, otherwise false
			Is_Empty:	 returns true if array is empty, otherwise false
			Search:		 locates a specific element
			Insert:		 inserts string into array
			Remove:		 removes string from array
			Display:	 displays array in single line format
			List:		 displays array one element per line (internal only)



*********************************************************************************************/
#include <string>
using namespace std;


#ifndef TLIST_H_
#define TLIST_H_

static const int TLIST_CAP = 12;	// define default capacity
class TLIST
{

public:

	/*****************************************************************************
	 * TLIST - construct a TLIST element
	 *
	 * Precondition: strings to be input are in a text file named "myData.txt"
	 * 				 located in the current directory.
	 *
	 * Postcondition: a TLIST element is created with a DB array in lexicographic order
	 *
	 */
	TLIST();

	/*****************************************************************************
	 * ~TLIST - 	TLIST elements are deallocated and returned to memory
	 *
	 * Precondition:
	 *
	 * Postcondition:	DB and string objects are deleted and memory freed
	 *
	 */
	~TLIST();

	/*****************************************************************************
	 * Is_Empty - Check if TLIST is empty
	 *
	 * Precondition:	none
	 *
	 * Postcondition:	returns true if TLIST is empty, otherwise false.
	 *
	 */
	bool Is_Empty();


	/*****************************************************************************
	 * Is_Full - Check if TLIST is full
	 *
	 * Precondition:	None.
	 *
	 * Postcondition:	Returns true if number of elements in TLIST equals
	 * 					capacity, otherwise false.
	 *
	 */
	bool Is_Full();

	/*****************************************************************************
	 * Search -	Locate an element in the TLIST
	 *
	 * Precondition:	None
	 *
	 * Postcondition:	Returns true if the item indicated by target is present in
	 * 					the list, false otherwise.
	 *
	 *
	 */
	int Search(const string &target);

	/*****************************************************************************
	 * Insert - 	Insert an element into the TLIST
	 *
	 * Precondition:	none
	 *
	 * Postcondition:	If the list is not full, the string pointed to by the
	 * 					input parameter is inserted into the TLIST array in
	 * 					ascending lexicographic order.
	 *
	 */
	void Insert(const string & key);
    TLIST & operator+(string &key);
	/*****************************************************************************
	 * Remove() - Remove an element from TLIST
	 *
	 * Precondition: 	None
	 *
	 * Postcondition:	If the string pointed to by the input parameter is present
	 * 					in the list it will be removed and list elements shifted.
	 * 					Otherwise nothing will happen.
	 *
	 */
	void Remove(const string & key);


	/*****************************************************************************
	 * Display -	Single line formatted display of TLIST
	 *
	 * Precondition:
	 *
	 * Postcondition:	Creates a single line output of the TLIST array enclosed in
	 * 					brackets  "[ ]".
	 *
	 */
	void Display();

private:
	/*****************************************************************************
	 * List	-	Private function to list the elements of the TLIST
	 *
	 * Precondition: none
	 *
	 * Postcondition:	List the elements in the TLIST array, one element per line.
	 *
	 */
	void List();



	string *DB;
	int		count;
	int		capacity;

};
#endif /* TLIST_H_ */

