/********************************************************************************************

Name: Christopher Foley             Z#:Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Assess C++ language skills
			 Assignment will:
			 	 1 - prompt the user for input
			 	 2 - write output
			 	 3 - check input string for palindrome
			 	 4 - reverse string using recursion
			 	 5 - reverse string using iteration

Description: Program contains three primary functions:
			bool palindrome(string) which returns true if the input string
									is a palindrome, false otherwise
			string reverse_r(string) - reverse string recursively
			string reverse_l(string) - reverse string iteratively

*********************************************************************************************/

#include <iostream>
#include <string>
#include <cassert>				// use assert for testing purposes
using namespace std;


/*************************************************************************************
Name:  palindrome

Precondition: valid string object passed to function

Postcondition: No changes to objects

Description:  Recursively checks if the string passed to the function
			  is a palindrome.  Returns true if palindrome, false otherwise.

*************************************************************************************/
bool palindrome(const string &palin)
{
	if (palin.length() <= 1) return true;
	else if (palin[0] != palin[palin.length()-1]) return false;
	return palindrome(palin.substr(1,palin.length()-2));
}

/*************************************************************************************
Name:  printReverse

Precondition: valid string object passed to function

Postcondition: No changes to objects

Description:  Function returns new string created recursively containing a reverse of
              the original string.

*************************************************************************************/
string printReverse(const string &source)
{
	if (source.length() <= 1) return source;		// base case
	else
		return source[source.length()-1] + printReverse(source.substr(0, source.length()-1));
	return "";
}

/*************************************************************************************
Name:  printIterReverse

Precondition: valid string object passed to function

Postcondition: No changes to objects

Description:  Function returns new string created iteratively containing a reverse of
              the original string.

*************************************************************************************/
string printIterReverse(const string &source)
{
	string target = "";
	for (int i = source.length()-1; i >= 0; i--)
		{
		target += source[i];
				}
	return target;
}

/**********************************************************************************
 * Name: clearbuffer
 *
 * Precondition: cin properly initialized
 *
 * Postcondition: cin empty
 *
 * Description: removes spaces and new line from cin until done
 ********************************************************************************/

void clearbuffer()
{
	char c;
	while (cin.peek() == ' ') cin.get(c);
	cin.ignore(1, '\n');
}
/*************************************************************************************
Name:  main

Precondition: The state of the object (private data) has not been initialized

Postcondition: The state has been initialized to the default date 01-Jan-0001

Description:  input for palindrome <ctrl>-z for end;

*************************************************************************************/


int main()
{
	// run a set of standard tests before asking for input
	// use assert to cause exception if they do not produce expected result

	assert(palindrome(""));			// true
	assert(palindrome("a"));
	assert(palindrome("aa"));
	assert(palindrome("aaa"));
	assert(palindrome("aaaa"));
	assert(palindrome("aaaaa"));
	assert(palindrome("abcba"));
	assert(palindrome("able was I ere I saw elba"));
	assert(palindrome("able was I saw elba"));
	assert(!palindrome("this is not a palindrome"));
	assert(!palindrome("bcdba"));

	bool exit=false;

	// loop prompting for input: select palindrome, replace all or exit
	while (!exit)
	{
		int option;

		cout << "Program options:" << endl;
		cout << "\t1 - check a palidrome" << endl;
		cout << "\t2 - reverse a string" << endl;
		cout << "\t9 - exit" << endl;
		cout << "Select one:";
		cin >> option;
		clearbuffer();
		if (option == 1)			// 3 options use if instead of case - efficient
		{
			string sarah;
			cout <<  "Enter string to test:";

			getline(cin, sarah);
			cout << "\"" << sarah << "\" is ";
			if (!palindrome(sarah))
				cout << "not ";
			cout << "a palindrome.\n" << endl;
		}
		else if (option == 2)
		{
			string input;

			int start=0;

			cout << "Initial string:";
			getline(cin, input);
			cout << "Target string (reversed recrusively):";
			cout << printReverse(input) << endl;
			cout << "Target string (reversed iteratively):";
			cout << printIterReverse(input)<< endl;

			// use assert to verify that correct values were reversed (use palindrome
			// to compare original string concatenated with its reverse should NEVER trigger

			assert(palindrome(input+printReverse(input)));
			assert(palindrome(input+printIterReverse(input)));		// should never trigger


		}
		else if (option==9) exit = true;
		else
		{
			cout << "Unknown option: " << option << endl;
		}

	}

	return 0;
}


