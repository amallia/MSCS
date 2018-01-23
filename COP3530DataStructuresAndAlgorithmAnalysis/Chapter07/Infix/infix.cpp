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

#include "stack.h"

using namespace std;

/*****************************************************************************
 * STACK::compareNoCase -helper method to compare strings with case insensitivity
 *
 * Precondition: two properly initialized strings
 *
 * Postcondition: no change to strings, returns true if equal false otherwise.
 *
 ****************************************************************************/
bool compareNoCase(string a, string b)
{
	if (a.length() != b.length()) return false;
	for (int i=0; i < a.length(); i++)
	{
		if (tolower(a[i]) != tolower(b[i])) return false;
	}

	return true;	// only way to get here is if they are equal
}

int main()
{
	STACK *stack = new STACK();
	string operand;
	const string operators = "+-*/";
	bool exit=false;

	string value;

	// loop prompting for input
	while (!exit)					// not needed due to return but marked as warning by KLANG compiler?
	{
		cout << "Enter postfix equation to convert or \"exit\" to end";
		bool firstOp = false;			// first operator flag for special case of single variable input
		while (cin.peek() != '\n' )//&& cin.peek() != '\r')
		{
			char c;
			while (cin.peek() == ' ') cin.get(c);
			c = cin.peek();
			if (operators.find(c) == string::npos)	/// operand
			{
				cin >> operand;
				if (compareNoCase("exit", operand))
					{
					if (stack->is_empty()) return 0;
					cout << "Error: exit must be first element on line" << endl;
					while (c != '\n') cin.get(c);			// ignore rest of line
					}
				else
					stack->push(operand);
			}
			else								// operator
			{
				cin >> c;
				string operand1, operand2;
				if (stack->is_empty())
				{
					cout << "too many operators and not enough operands" << endl;
				}
				else
				{
					operand2 = stack->pop_str();
					if (stack->is_empty())
					{
						cout << "too many operators and not enough operands" << endl;
					}
					else
					{		// since we are not evaluating, just create a string with current operator and push onto stack
						operand1 = stack->pop_str();

						stack->push("(" + operand1 + " " + c + " " + operand2 + ")");
						
						firstOp = true;;
					}
				}
			}
			while (cin.peek() == ' ') cin.get(c);			// strip spaces until next value
		}

		cin.ignore(1, '\n');

		if (stack->is_empty()) cout << "no operators or operands entered" << endl;
		else
		{
			value = stack->pop_str();
			if (!firstOp) value = "(" + value + ")";		// special case of one operand
			if (!stack->is_empty()) cout << "too many operands and not enough operators" << endl;
			else
			{
				cout << value << endl;
			}
		}
		while (!stack->is_empty()) stack->pop_str();		// cleanup for next expression
		char c = 'x';
		while (tolower(c) != 'y')
		{
			cout << endl << "Another expression (y/n): ";
			cin >> c;
			if (tolower(c) == 'n') return 0;
			if (tolower(c) != 'y') cout << "y or n only" << endl;
			cin.ignore(1, '\n');
		}
	}
}



