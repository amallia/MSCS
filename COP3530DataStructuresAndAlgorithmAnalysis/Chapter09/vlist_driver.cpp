/********************************************************************************************
File: vlist_driver.cpp
Name: Christopher Foley              Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 07-Nov-2016           Due Time:
Total Points: 100
Assignment: Vectors, Iterators and Templates Chapter 9

Description: Created project RogerRoger to test Vector class.

**********************************************************************************************/
#include <iostream>
#include <string>
#include "VLIST.h"
using namespace std;
int main()
{
	//Testing default constructor
cout << "Test1:Testing the default constructor for string\n";
VLIST String_List;
//Testing functionality for string list
cout << "Test2: Testing Insert \n";
String_List.Insert("Hello");
String_List.Insert("Zebra");
String_List.Insert("Good_Bye");
String_List.Insert("Space");
String_List.Insert("No_One");
cout << "Test 2a: Print:" << endl;
String_List.Print();

cout << "Test 3: Testing copy constructor for string \n";
VLIST Copied_String = String_List;
Copied_String.Print();
cout << "Test 4: Testing Remove for string \n";
cout << "Testing Search and IsEmpty also\n";
cout << "search Good_bye, No_one, Zebra, Bruce"<< endl;
String_List.Search("Good_Bye");
String_List.Search("No_One");
String_List.Search("Zebra");
String_List.Search("Bruce");

cout << "Remove item then search" << endl;
String_List.Remove("Zebra");
String_List.Search("Zebra");

String_List.Remove("Good_Bye");
String_List.Search("Good_Bye");

String_List.Remove("Hello");
String_List.Search("Hello");

String_List.Remove("No_One");
String_List.Search("No_One");

String_List.Remove("Space");
String_List.Search("Space");

String_List.Search("Hello");
String_List.Remove("Hello");
{
	cout << "Create/Copy/Destroy Test" << endl;
	VLIST DestroyMe = Copied_String;
}
cout<<"When leave main destructor will be called twice"<<endl;
return 0;
}



