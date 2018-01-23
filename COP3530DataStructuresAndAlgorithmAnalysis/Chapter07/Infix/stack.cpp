/********************************************************************************************

Name: Christopher Foley			Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  Program 5 - Unit 7 Stacks

Description: Create a program "infix.cpp" to translate a postfix expression to an infix expression.
	Operands and operators are separated by at least one space.  The only operators to be used are
	the binary operators +, -, * and /.  User terminates the program by entering entering exit for the
	postfix expression or N when asked.

*********************************************************************************************/
#include <iostream>
#include <string>
#include <cassert>				// use assert for testing purposes
#include <limits>

#include "stack.h"
using namespace std;

/*****************************************************************************
 * STACK::STACK -
 *
 * Precondition: default constructor
 *
 * Postcondition: stack properly initialized
 *
 ****************************************************************************/

STACK::STACK()
{
	top = NULL;
}

/*****************************************************************************
 * STACK::~STACK - destructor
 *
 * Precondition: stack properly initialized
 *
 * Postcondition:	stack elements removed from stack and deleted.
 *
 ****************************************************************************/
STACK::~STACK()
{
	while (top != NULL)
		if (top->type == STACK_STRING)
			pop_str();
		else if (top->type == STACK_DOUBLE)
			pop_double();
}

/*****************************************************************************
 * STACK::is_empty - determines of stack has elements remaining
 *
 * Precondition: stack properly initialized
 *
 * Postcondition:	stack unchanged, return value of true indicates stack empty
 *
 ****************************************************************************/
bool STACK::is_empty()
{
	return (top == NULL);
}

/*****************************************************************************
 * STACK::push_str - push string element on to stack
 *
 * Precondition: stack properly initialized
 *
 * Postcondition: string value stored in stack element and pushed to top.
 *
 ****************************************************************************/
void STACK::push(string value)
{
	string *s = new string(value);
	entry *e = new entry();
	e->next = top;
	e->type = STACK_STRING;
	e->item.str_item = s;
	top = e;
}

/*****************************************************************************
 * STACK::pop_str - pop the top element of the stack and return string
 *
 * Precondition: top element of stack contains a string pointer.
 *
 * Postcondition:	top element removed from list and deallocated. if top is not
 * 	a string element error message displayed and null string returned.
 *
 ****************************************************************************/
string STACK::pop_str()
{
	string value = "";
	entry *e = top;
	if (e == NULL)
		{
		cout << "error too many operators and not enough operands " << endl;
		}
	else if (e->type == STACK_STRING)
	{
		value = *(e->item.str_item);
		delete e->item.str_item;
		top = e->next;
		delete e;
	}
	else
	{
		cout << "stack error incorrect element type" << endl;
	}
	return value;
}

/*****************************************************************************
 * STACK::push_double - push a double on to the stack
 *
 * Precondition: stack properly initialized
 *
 * Postcondition: value passed as parameter is recorded in stack structure
 *                stack element pushed to top of stack
 *
 ****************************************************************************/
void STACK::push(double value)
{
	entry *e = new entry();
	e->next = top;
	e->type = STACK_DOUBLE;
	e->item.d_item = value;
	top = e;
}

/*****************************************************************************
 * STACK::pop_double - remove element from the stack containing a double
 *
 * Precondition: top element is removed from stack and contents returned
 * 				 as a double
 *
 * Postcondition:	element formerly at top of stack is deallocated. If not a
 * numeric data type error message and no change.
 *
 ****************************************************************************/
double STACK::pop_double()
{
	double value;
	entry *e = top;
	if (e == NULL)
		{
		cout << "error too many operators and not enough operands " << endl;
		value = -1;
		}
	else if (e->type == STACK_STRING)
	{
		value = -1;
	}
	else
	{
		value = e->item.d_item;
		top = e->next;
		delete e;
	}
	return value;
}
