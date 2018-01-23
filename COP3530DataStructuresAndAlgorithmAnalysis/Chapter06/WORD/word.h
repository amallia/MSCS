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


using namespace std;

#ifndef character_H_
#define character_H_

class character
{
	public:
		char symbol;
		character *next;
};

#endif	/* character_H_ */

#ifndef WORD_H_
#define WORD_H_

class WORD {
public:
	WORD();
	WORD(string &);
	WORD(char *);
	WORD(WORD &);	// copy constructor
	virtual ~WORD();

	// implement IsEmpty as inline -- 'cause I've never done it like this

	bool IsEmpty() { return front == NULL;} ;		//is list empty

	int Length();		// length of current word
	bool IsEqual(const WORD );	// returns true if b equals current word


	friend ostream & operator<<(ostream &, const WORD &);  // stream WORD

	WORD &operator=(const WORD &);

	WORD &operator=(const string &);		// string assignment

	WORD &operator=(const char *);				// c style string

	WORD operator+(const WORD &);	// concatenate

    string to_string();				// return string from wordObj
    char * to_cstring();			// return C style string


private:
	void WORD_init_c_string(char *);			// constructor helper function
	void WORD_assign_to_me(WORD &);				// assignment operator helper

	character *front, *back;
};

#endif /* WORD_H_ */
