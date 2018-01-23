/********************************************************************************************
TLIST.h

Name: Christopher Foley             Z#: 15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Assess C++ skills
			 Understand and implement classes in C++
			 Demonstrate operator overloading with chaining
			 Demonstrate use of PreProcessor Directives
			 Demonstrate use of this pointer

Description:
             Header file containing signatures for the following operations and helpers
Operations:
	Date()- default constructor  sets m=01, d=01, y=0001
	Date(unsigned , unsigned , unsigned ) - explicit value constructor
						to set date equal to today's
						date. Use 2 - digits for month (m) and day (d),
						and 4 - digits for year (y);
						this function should print a message if a leap year.
	~Date()				destructor

	void display();		output Date object to the screen
	int getMonth();		accessor to output the month
	int getDay();		accessor to output the day
	int getYear();		accessor to output the year
	void setMonth(unsigned );	mutator to change the month
	void setDay(unsigned );	mutator to change the day
	void setYear(unsigned);	mutation to change the year
	friend ostream & operator<<(ostream &, const Date & );
				overloaded operator<< as a friend function with chaining
	operator++();	pre-increment operator overloaded adds one to the day
	operator++(int); post-increment operator overload adds one to the daypouncer1995





*********************************************************************************************/

#include <iostream>

using namespace std;

#ifndef DATE_H_
#define DATE_H_


class Date
{
 public:
	Date();				//default constructor  sets m=01, d=01, y=0001
	Date(unsigned m, unsigned d, unsigned y); //explicit value constructor
						//to set date equal to today's
						//date. Use 2 - digits for month (m) and day (d),
						//and 4 - digits for year (y);
						//this function should print a message if a leap year.

	void display();		//output Date object to the screen
	int getMonth();		//accessor to output the month
	int getDay();		//accessor to output the day
	int getYear();		//accessor to output the year
	void setMonth(unsigned m);	//mutator to change the month
	void setDay(unsigned d);	//mutator to change the day
	void setYear(unsigned y);	//mutation to change the year
	friend ostream & operator<<(ostream & out, const Date & dateObj);
				//overloaded operator<< as a friend function with chaining
				//you make add other functions if necessary
	Date & operator++(); // pre increment
	Date & operator++(int); // post increment - uses copy constructor
	Date(const Date &);	// copy constructor
  private:
	void setDefaultDate();	// set date to m=01, d=01, y=01; used in constructors
	void incrementDate();	// add one to the day and adjust month and year as needed
	int myMonth, myDay, myYear; //month, day, and year of a Date obj respectively
};


#endif /* DATE_H_ */
