/********************************************************************************************

Name: Christopher Foley             Z#: Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  Assess C++ skills using C++ strings and dynamic arrays

Description: dynamic_array_driver provides the main test driver.  It sets a static
			 datalist to emulate the input file and tests the individual elements.
			 Scope is used to "reset" TLIST at each test to provide known state
			 at beginning of test.

*********************************************************************************************/
#include <string>
#include <iostream>

#include "tlist.h"
using namespace std;
typedef struct {
	string data;
	int pos;
} mydatalist;

	mydatalist myDataTxt[]  = {
			{"defghiiijjjiiijj", 5},
			{"ab", 0},
			{"stringtrist", 9},
			{"abczzzabcabc", 2},
			{"cdeerxre", 3},
			{"abcdeabaeeeabrxre", 1},
			{"cveevcyxq", 4},
			{"pppppeeeeeppppp",8},
			{"kjhlfgdsaw", 7},
			{"fertyxcwt", 6},
	};



	void fill_TLIST(TLIST *aray)
	{
		string x = "zzzdummyname";
		while (!aray->Is_Full())
		{
			aray->Insert(x);
		}
		if (aray->Is_Full()) cout << "Insert beyond full failure";
	}

	void empty_TLIST(TLIST *aray)	// assumes myDatatxt
	{
		for (int i=0; i < sizeof(myDataTxt)/sizeof(mydatalist); i++)
			aray->Remove(myDataTxt[i].data);
	}
int main()
{

	// test default constructor & destructor (use in/out scope for destructor)
	{
		cout << endl << "Constructor/Destructor test" << endl;
		TLIST myarray;
	}

	// construct and test display
	{
		cout << endl << "constructor and display" << endl;
		TLIST myarray;
		myarray.Display();
	}
	// test search before others
	{
		cout << endl << "search test" << sizeof(myDataTxt)/sizeof(mydatalist) << endl;
		TLIST myarray;
		for (int i=0; i < sizeof(myDataTxt)/sizeof(mydatalist)-1; i++)
		{
			if (!myarray.Search(myDataTxt[i].data))
				cout << "Search test 1: " << i << " failed." << myDataTxt[i].data << " " << myDataTxt[i].pos << endl;
		}
	}
	// test insert (although it should work if search is ok
	{
		cout << endl << "Test insert" << endl;
		TLIST myarray;
		myarray.Insert("      "); // string with lowest printable characters.
		myarray.Insert("      ");
		// myarray should be full - insert one item it should be dropped
		myarray.Insert("COP3050");
		// search for "dropped item"
		if (myarray.Search("COP3050") )
			cout << "Insert test 1 failed" << endl;
		// now see that everything else has shifted.
		for (int i=0; i < sizeof(myDataTxt)/sizeof(mydatalist)-1; i++)
		{
			if (!myarray.Search(myDataTxt[i].data))
				cout << "Insert test 2: " << i << " failed." << myDataTxt[i].data << " " << myDataTxt[i].pos << endl;
		}
		myarray.Display();
	}

	// test Is_full.
	{
		cout << endl << "Is_full tests" << endl;
		TLIST myarray;
		if (myarray.Is_Full())
			cout << "ARRAY IS FULL" << endl;
		else
			cout << "ARRAY IS NOT FULL" << endl;

		fill_TLIST(&myarray);
		if (myarray.Is_Full())
			cout << "ARRAY IS FULL" << endl;
		else
			cout << "ARRAY IS NOT FULL" << endl;

		myarray.Display();
	}

	// test remove and is empty
	{
		cout << endl << "remove and Is_empty tests" << endl;
		TLIST myarray;
		myarray.Display();
		for (int i=0; i < sizeof(myDataTxt)/sizeof(mydatalist)-1; i++)
		{
			if (myarray.Is_Empty()) cout << "Is_empty (false) error" << endl;
			myarray.Remove(myDataTxt[i].data);
			if (myarray.Search(myDataTxt[i].data))
				cout << "Search test 3: " << i << " failed." << myDataTxt[i].data << " " << myDataTxt[i].pos << endl;
			myarray.Remove(myDataTxt[i].data);		// should do nothing
		}
		if (!myarray.Is_Empty()) cout << "Is_empty(true) error" << endl;
		myarray.Display();
	}




	// test is empty
	{
		cout << endl << "Is_empty tests" << endl;
		TLIST myarray;

		for (int i=0; i < sizeof(myDataTxt)/sizeof(mydatalist); i++)
		{
			myarray.Remove(myDataTxt[i].data);
			if (myarray.Search(myDataTxt[i].data))
				cout << "Is_empty remove: " << i << " failed." << myDataTxt[i].data << " " << endl;
		}
		if (myarray.Is_Empty())
			cout << "Array is empty test - pass" << endl;
		else
		{
			cout << "Array is empty test - fail" << endl;
			myarray.Display();
		}
	}

	// Insert tests from example dynamic_array.cpp
	{
		TLIST myArray;


		myArray.Display();

	     string x;
		if(myArray.Is_Empty())
			cout << "ARRAY IS EMPTY" << endl;
		else
			cout << "ARRAY IS NOT EMPTY" << endl;

		cout << endl;


		if(myArray.Is_Full())
			cout << "ARRAY IS FULL" << endl;
		else
			cout << "ARRAY IS NOT FULL" << endl;

		cout << endl;

		myArray.Search("stringtrist");

		cout << endl;

		myArray.Remove("defghiiijjjiiijj");
		cout << endl;
		myArray.Remove("ab");
		cout << endl;
		myArray.Remove("stringtrist");
		cout << endl;
		myArray.Remove("abczzzabcabc");
		cout << endl;
		myArray.Remove("cdeerxre");
		cout << endl;
		myArray.Remove("abcdeabaeeeabrxre");

		cout << endl;

		for(int i = 0; i < 6; i++)
		{
			myArray.Insert("abc");
			cout << endl;
		}

		if(myArray.Is_Full())
			cout << "ARRAY IS FULL" << endl;
		else
			cout << "ARRAY IS NOT FULL" << endl;

		cout << endl;

	}
		return 0;

}
