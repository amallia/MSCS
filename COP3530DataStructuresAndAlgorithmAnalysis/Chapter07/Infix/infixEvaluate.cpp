/********************************************************************************************

Name:              Z#:                            
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  

Description: 

*********************************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>				// use assert for testing purposes
#include "stack.h"

using namespace std;

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
	string input;
	bool exit=false;
	double value = 0;

	// loop prompting for input
	while (!exit)					// not needed due to return but marked as warning by KLANG compiler?
	{
		cout << "Enter postfix equation to evaluate or \"exit\" to end";
		char c;
		if (cin.peek() == 'E' or  cin.peek() == 'e')
		{
			cin >> input;
			if (compareNoCase("exit", input)) return 0;
		}
		else
		{
			while (cin.peek() != '\n' )//&& cin.peek() != '\r')
			{
				while (cin.peek() == ' ') cin.get(c);
				char c = cin.peek();
				if (c >= '0' && c <= '9')			// number
				{
					cin >> value;					// operand
					stack->push(value);
				}
				else
				{
					cin >> c;					// operator
					double operand1, operand2;
					if (stack->is_empty())
					{
						cout << "too many operators and not enough operands" << endl;
					}
					else
					{
						operand2 = stack->pop_double();
						if (stack->is_empty())
						{
							cout << "too many operators and not enough operands" << endl;
						}
						else
						{
							operand1 = stack->pop_double();

							switch (c)
							{
							case '+':
								stack->push(operand1 + operand2);
								break;
							case '-':
								stack->push(operand1 - operand2);
								break;
							case '*':
								stack->push(operand1 * operand2);
								break;
							case '/':
								stack->push(operand1 / operand2);
								break;
							default:
								cout << "Unknown postfix operator \'" << c << "\'" << endl;
								while (cin.peek() != '\n' /* && cin.peek() != '\r' */) cin.get(c);
							}
						}
					}
				}
			}
		}
		cin.ignore(1, '\n');
		//cin.ignore(1, '\r');
		if (stack->is_empty()) cout << "no operators o";
		else
		{
			value = stack->pop_double();
			if (!stack->is_empty()) cout << "too many operands and not enough operators" << endl;
			else
			{
				cout << " = " << value << endl;
			}
		}
		while (!stack->is_empty()) stack->pop_double();		// cleanup for next expression
	}
}



