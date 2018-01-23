/********************************************************************************************

Name: Christopher Foley             Z#:Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  

Description: Test program for Date class begins  by testing display function then 
				Valid date
				Valid date - leap year
				Day error 
				year error
				bad year, month, day

				Tests accessors
				Tests mutators

				tests pre/post increment

*********************************************************************************************/
#include <iostream>
#include "date.h"
int main()
{
	Date myDate;
	myDate.display();
	Date yourDate(12, 31, 1957);
	Date test1Date(15, 1, 1962); // error on month
	Date test2Date(2, 29, 1956); // ok should say leap year
	Date test3Date(2, 30, 1956); // day error
	Date test4Date(12, 31, 0000); // year error
	Date test5Date(80, 40, 0000); // bad year, month, day

	yourDate.display();
	cout << yourDate.getMonth() << endl;
	cout << yourDate.getDay() << endl;
	cout << yourDate.getYear() << endl;

	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);

	cout << "myDate: " << myDate << " test2Date = " << test2Date << " yourDate = " << yourDate << endl;

	cout << "myDate: " << myDate << endl;
	cout << "myDate++: " << myDate++ << endl;
	cout << "myDate: " << myDate << endl;
	cout << "++myDate: " << ++myDate << endl;
	cout << "myDate: " << myDate << endl;

	cout << "test2Date before loop: " << test2Date << endl;
	while (test2Date.getYear() < 1963)
	{
		test2Date++;		// add one day
		++test2Date;		// add one day
	}
	cout << "test2Date after loop (year < 1963): " << test2Date << endl;

	return 0;
}


