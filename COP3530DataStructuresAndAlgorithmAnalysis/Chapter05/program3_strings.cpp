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
			 	 3 - manipulate strings using the string class

Description: Program contains two primary functions:
			bool palindrome(string) which returns true if the input string
									is a palindrome, false otherwise
			string replace_all(string, string, string) which replaces all occurances of
									a given substring within a string with a third string

*********************************************************************************************/

#include <iostream>
#include <string>
#include <cassert>				// use assert for testing purposes
using namespace std;

/*************************************************************************************
Name:  palindrome_l

Precondition: valid string object passed to function

Postcondition: No changes to objects

Description:  Function returns true if palindrome, false otherwise. Palindrome_l
			  uses a loop to check.

*************************************************************************************/
bool palindrome_l(const string &palin)
{

	int left=0, right=palin.length()-1;
	while (left <= right)
	{
		if (palin[left]!=palin[right]) break;
		left++;
		right--;
	}

	return (left > right);  // if left > right we have a palindrome
}
/*************************************************************************************
Name:  palindrome_r

Precondition: valid string object passed to function

Postcondition: No changes to objects

Description:  Function returns true if palindrome, false otherwise. Palindrome_r
			  checks for a plaindrome using recursion.

*************************************************************************************/
bool palindrome_r(const string &palin)
{
	if (palin.length() <= 1) return true;
	else if (palin[0] != palin[palin.length()-1]) return false;
	return palindrome_r(palin.substr(1,palin.length()-2));
}




/*************************************************************************************
Name:  palindrome

Precondition: A string object is passed to this method

Postcondition: No changes made to any of the strings

Description:  This function determines if the input string is a palindrome,
			  if the input string is a palindrome return true otherwise return false

			  NOTE: Uses palindrome_r or palindrome_l which test for palindromes
			  	    recursively (_r) or in a loop (_l). Comment out method not
			  	    used and uncomment the desired method for testing purposees.

*************************************************************************************/
bool palindrome(const string &input)
{
//	return palindrome_l(input);			// loop
	return palindrome_r(input);			// recursive
}

/*************************************************************************************
Name:  replace_all

Precondition: Three strings are input.

Postcondition: No changes, new string returned

Description:   All occurrances of the character sequence identified by the
			   second string, found within the first string are replaced by the
			   third string.  The original input strings are unchanged and a new
			   string is returned.

*************************************************************************************/
string replace_all(const string &original, const string &search, const string &replace)
{
	int start;
	string target = original;
	start = target.find(search, 0);	// look for first substring
	while (start != string::npos)
	{
		target.replace(start, search.length(), replace);
		start = target.find(search, start+replace.length());

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
	//char c;
	//while (cin.peek() == ' ') cin.get(c);
	cin.ignore(10000, '\n');
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
	assert(replace_all("aabbccdd", "c", "abc").compare("aabbabcabcdd") == 0);
	assert(replace_all("aabbccdd", "cd", "seedyc").compare("aabbcseedycd") == 0);

	bool exit=false;

	// loop prompting for input: select palindrome, replace all or exit
	while (!exit)
	{
		int option;

		cout << "Program options:" << endl;
		cout << "\t1 - check a palidrome" << endl;
		cout << "\t2 - replace all in a string" << endl;
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
			string target;
			string replace;
			int start=0;

			cout << "Initial string:";
			cin >> input;
			cout << "Target string (to be replaced):";
			cin >> target;
			cout << "Replacement string:";
			cin >> replace;

			cout << "Replace all occurrances of \"" << target << "\" in \""
				 << input << "\" will yield ";
			cout << "\"" << replace_all(input, target, replace) << "\"" << endl;

		}
		else if (option==9) exit = true;
		else
		{
			cout << "Unknown option: " << option << endl;
		}

	}

	return 0;
}


