/********************************************************************************************

Name: Christopher Foley             Z#: Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Assess skills overriding insertion operator, linked lists

Description: The WORD class creates a structure in which each character is stored in an
			 individual element.  This emulates the structure of many text editing programs.

*********************************************************************************************/

#include <iostream>
#include <cstring>
#include <string>

#include "word.h"

using namespace std;

/* constructors and destructor first */

/*****************************************************************************
 * WORD::WORD - Default constructor
 *
 * Precondition: none
 *
 *
 * Postcondition: a WORD structure is initialized containing no character data
 *
 *
 *****************************************************************************/
WORD::WORD()					// default constructor
{
	string str = "";
	char *temp = (char *)str.c_str();
	front = NULL;
	back = NULL;
	WORD_init_c_string(temp);	// use helper function

}

/*****************************************************************************
 * WORD::WORD(WORD &) - copy constructor
 *
 * Precondition: A properly initialized WORD object is to be copied
 *
 *
 * Postcondition: A WORD structure is initialized with duplicate data of the other
 *
 *
 *****************************************************************************/
WORD::WORD(WORD &wordObj)	// copy construcor
{
	front = NULL;
	back = NULL;
	char *str = wordObj.to_cstring();
	WORD_init_c_string(str);	// use helper function

	delete str;

}

/*****************************************************************************
 * WORD::WORD(char *) - construct from a C-style string
 *
 * Precondition: a C-Style string (null terminated) is passed as a parameter
 *
 *
 * Postcondition: A WORD structure containing the input C-String as character
 *                objects is created
 *
 *
 *****************************************************************************/
WORD::WORD(char *str) 	// construct from C-Style string
{
	front = NULL;
	back = NULL;
	WORD_init_c_string(str);	// use helper function
}

/*****************************************************************************
 * WORD::WORD(string &) - construct WORD from string data type
 *
 * Precondition: string object is passed.
 *
 *
 * Postcondition: a WORD object containing the string data as character objects
 *                is initialized
 *
 *
 *****************************************************************************/
WORD::WORD(string & str)	// construct from string
{
	front = NULL;
	back = NULL;
	char *temp = (char *)str.c_str();
	WORD_init_c_string(temp);		// use helper function
}

/*****************************************************************************
 * WORD::~WORD() - destructor
 *
 * Precondition: properly initialized WORD structure exists
 *
 *
 * Postcondition: character objects are deleted and the structure released.
 *                Data is NOT overwritten with any values.
 *
 *
 *****************************************************************************/
WORD::~WORD() {
								// since this is a destructor use front and
	while (front != NULL)		// don't update front/back
	{
		character *ptr = front->next;
		delete front;
		front = ptr;
	}
}

/*****************************************************************************
 * WORD::WORD_init_c_string(char *) - private helper function that does actual
 *                initialization of WORD structure, using a C style string as
 *                input (provided by constructors).
 *
 * Precondition:	constructor generated C style string
 *
 *
 * Postcondition:	fields of WORD are initialized
 *
 *
 *****************************************************************************/
void WORD::WORD_init_c_string(char *ptr)
{
	character *cptr;
	front = NULL;
	back = NULL;
	while (*ptr != '\0')
	{
		cptr = new character();
		cptr->symbol = *ptr;
		cptr->next = NULL;
		if (front != NULL)		// not first character
		{
			back->next = cptr;
		}
		else
		{
			front = cptr;
		};
		back = cptr;
		ptr++;
	};
}


/*****************************************************************************
 * WORD::Length - number of characters in WORD object
 *
 * Precondition: properly initialized WORD object
 *
 *
 * Postcondition: number of character objects are returned, no change to WORD
 *
 *
 *****************************************************************************/
int WORD::Length()
{
	character *ptr = front;	// list header
	int i = 0;

	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}

	return i;
}

/*****************************************************************************
 * WORD::IsEqual(WORD) - compare character values to determine if objects are
 *                       equal.
 *
 * Precondition:  two properly initialized WORD objects (this and input)
 *
 *
 * Postcondition: return value indicates if character objects in WORD object
 *                contain equal characters. No changes to objects
 *
 *
 *****************************************************************************/
bool WORD::IsEqual(WORD b)
{
	if (Length() != b.Length()) return false; // different length cant be equal

	character *aptr = front, *bptr = b.front;

	while (aptr != NULL)
	{
		if (aptr->symbol != bptr->symbol) return false;
		aptr = aptr->next;
		bptr = bptr->next;
	}
	return true;
}

// overload some operators
/*****************************************************************************
 * WORD::operator=(const WORD &) - assignment operator with chaining
 *
 * Precondition:  properly initialized WORD object
 *
 *
 * Postcondition: current object is assigned the input value.
 *
 * 			Uses helper function
 *
 *
 *****************************************************************************/
WORD & WORD::operator=(const WORD &wordObj)
{
	WORD_assign_to_me((WORD &)wordObj);
	return *this;
}

/*****************************************************************************
 * WORD::operator=(const string &) - assign string object
 *
 * Precondition:  properly initialized WORD object, properly initialized string object
 *
 *
 * Postcondition: string object is assigned to word object.
 *
 *
 *****************************************************************************/
WORD & WORD::operator=(const string &str)
{
	string inStr = "" + str;			// use dummy value since str is const
	WORD *tmp = new WORD(inStr);
	WORD_assign_to_me(*tmp);

	return *this;
}

/*****************************************************************************
 * WORD::operator=(const char *) - assign c style string.
 *
 * Precondition:  properly initialized WORD object
 *
 *
 * Postcondition:
 *
 *
 *****************************************************************************/
WORD & WORD::operator=(const char *str)		// C style string
{
	WORD * tmp = new WORD((char *)str);		// convert right hand side to WORD object
	WORD_assign_to_me(*tmp);					// do the assignment
	return *this;
}



/*****************************************************************************
 * WORD::WORD_assign_to_me(WORD &) - private helper function to perform assignment
 *
 * Precondition:   properly initialized WORD object
 *
 *
 * Postcondition:
 *
 *
 *****************************************************************************/
void WORD::WORD_assign_to_me(WORD &wordObj)
{
	if (&wordObj != this)
	{
		// clean up this object
		character *ptr = front;
		while (ptr != NULL)
		{
			front = ptr->next;
			delete ptr;
			ptr = front;
		}
		back = front = NULL;
		// copy the list
		ptr = wordObj.front;		// source
		while (ptr != NULL)
		{
			character *temp = new character;	// destination
			temp->symbol = ptr->symbol;
			temp->next = NULL;

			if (front == NULL)
			{
				front = back = temp;
			}
			else
			{
				back->next = temp;
			}
			back = temp;
			ptr = ptr->next;
		}
	}
}



/*****************************************************************************
 * WORD::operator+(const WORD &) = concatenate word objects
 *
 * Precondition:  properly initialized WORD objects
 *
 *
 * Postcondition: new object containing concatenation of objects is returned
 *
 *
 *****************************************************************************/
WORD WORD::operator+(const WORD &bword)	// concatenate
{
	WORD *rvalue;
	string estring, fstring, gstring;
	estring = to_string();
	fstring = ((WORD &)bword).to_string();

	gstring = estring + fstring;			// let the overloaded operator in string do the work

	rvalue = new WORD(gstring);
	return *rvalue;

}

/*****************************************************************************
 * WORD::operator<<(ostream &, const WORD &) - insertion operator with chaining
 *
 * Precondition:   properly initialized WORD object
 *
 *
 * Postcondition: character objects placed into stream and stream pointer returned
 *
 *
 *****************************************************************************/
ostream & operator<<(ostream &out, const WORD &wordObj)    // stream WORD
{
	string tmp = ((WORD &)wordObj).to_string();
	out << tmp;
	return out;
}

/*****************************************************************************
 * WORD::to_cstring() - convert WORD to C - Style string
 *
 * Precondition:   properly initialized WORD object
 *
 *
 * Postcondition: C - style string returned (null terminated array of char)
 *
 *
 *****************************************************************************/
char * WORD::to_cstring()					// return C style string
{
	char *rval = new char[Length() + 1];			// allocate new array
	char *tmp = rval;									// temporary holding
	character *ptr = front;
	*tmp = '\0';
	while (ptr != NULL)
	{
		*tmp = ptr->symbol;
		tmp++;
		ptr = ptr->next;
		*tmp = '\0';
	}

	return rval;
}

/*****************************************************************************
 * WORD::to_string() - string object returned
 *
 * Precondition:   properly initialized WORD object
 *
 *
 * Postcondition: string returned
 *
 *
 *****************************************************************************/
string WORD::to_string()				// return string
{
	char *temp;
	temp = to_cstring();
	string str = string(temp);
	return str;
}
