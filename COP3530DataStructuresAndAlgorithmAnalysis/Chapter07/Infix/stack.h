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
#include <string>

using namespace std;

#ifndef STACK_H_
#define STACK_H_

enum entry_type {STACK_STRING, STACK_DOUBLE, STACK_INT};
union data_overlay
{
	string * str_item;
	double d_item;
};

struct entry
{
	entry	* next;
	entry_type type;
	data_overlay	item;  /* make this a union so I can do more evaluations */
};

class STACK
{
public:
	STACK();
	~STACK();
	void push(string);
	string pop_str();

	void push(double);
	double pop_double();
	bool is_empty();
private:
	entry * top;
};





#endif /* STACK_H_ */
