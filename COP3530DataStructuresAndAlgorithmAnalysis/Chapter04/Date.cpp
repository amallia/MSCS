/********************************************************************************************

Name: Christopher Foley             Z#:15092976
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
Source file containing implementation of the following operations and helpers

Operations:
	Date()- default constructor  sets m=01, d=01, y=0001
	Date(unsigned , unsigned , unsigned ) - explicit value constructor to set date equal to today's
						date. Use 2 - digits for month (m) and day (d), and 4 - digits for year (y);
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
#include <iomanip>
#include "date.h"
using namespace std;


/*************************************************************************************
Name:  Date
Precondition: The state of the object (private data) has not been initialized
Postcondition: The state has been initialized to the default date 01-Jan-0001
Description:  This is the default constructor which will be called automatically when
an object is declared.  It will initialize the state of the class

*************************************************************************************/
Date::Date()
{
	cout << "Default Constructor has been called" << endl;
	setDefaultDate();
	cout << *this << endl;

}



//*************************************************************************************
//Name:  Date
//Precondition:  The state of the object, private data, is uninitialized.
//Postcondition: The date is set to the date month/day/year input, if valid
//				 an invalid date will be set to the default date.
//Description:  This is the constructor called with a specific date to be reviewed
//				Invalid dates fall into the following intervals:
//					year > 0
//			        month not integer in [1,12],
//                  day not integer between [1, end of month] will result in error message an default date set.
//				    leap year will produce a message indicating leap year.
//				Values are checked in the following order: year, month, day.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit-value constructor has been called" << endl;
		setDefaultDate();
		setYear(y);
		setMonth(m);
		setDay(d);
	// check to see it is a valid date otherwise set to default
		if (getYear() != y || getMonth() != m || getDay() != d) setDefaultDate();

	cout << *this << endl;
}


/*************************************************************************************
Name:  Date
Precondition: Copy Constructor, receives valid Date object
Postcondition: field by field copy
Description:  This is the copy constructor which will copy the fields from the input
              constructor.

*************************************************************************************/
Date::Date(const Date &dateObj)
{
	cout << "Copy Constructor has been called" << endl;
	setYear(dateObj.myYear);
	setMonth(dateObj.myMonth);
	setDay(dateObj.myDay);
	cout << this << endl;

}
//*************************************************************************************
//Name:  Display
//Precondition:	date has been initialized to a valid date
//Postcondition: date is output to cout in a mm/dd/yyyy format.
//Description: Formatted date output.
//
//
//*************************************************************************************
void Date::display()
{
	cout << setfill('0') << setw(2) << myMonth << "/"
		 <<	setw(2) << myDay << "/"
			<< setw(4) << myYear << endl;
}

//*************************************************************************************
//Name:  getMonth
//Precondition:  Date properly initialized
//Postcondition: returns stored month
//Description: Returns month stored. Assumes January=01, December=12
//
//
//*************************************************************************************
int Date::getMonth()
{
return myMonth;
}

//*************************************************************************************
//Name:  getDay
//Precondition: Date properly initialized
//Postcondition: returns day stored
//Description: returns day field of month stored
//
//
//*************************************************************************************
int Date::getDay()
{
return myDay;
}

//*************************************************************************************
//Name:  getYear
//Precondition: date properly initialized
//Postcondition: returns year stored
//Description: returns year stored
//
//
//*************************************************************************************
int Date::getYear()
{
return myYear;
}

//*************************************************************************************
//Name: setMonth
//Precondition: date properly initialized
//Postcondition: month changed to input value, if correct. Otherwise month is
//				 unchanged.
//Description: Changes month to input value.  If month is not correct, error message
//             displayed and month is unchanged.
//
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	if ((m < 1) || (m > 12))
	{
		cout << "Month = " << m << " is incorrect" << endl;
		m = myMonth;
	}
myMonth = m;
}

//*************************************************************************************
//Name:  setDay
//Precondition: Date properly initialiized
//Postcondition: day changed to input value, if correct.
//Description: Changes day to input value.  If day is not correct for previously stored
//			   month, error code displayed and day is unchanged.
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	if (myMonth == 9 || myMonth == 4 || myMonth == 6 || myMonth == 11)
	{
		if (d < 1 || d > 30)
		{
			cout << "Day = " << d << " is incorrect" << endl;
			d  = myDay;
		}
	}
	else
		if (myMonth == 2)
		{
			if ((myYear % 4 == 0 && myYear % 4000 != 0))  // leap year
			{
				if (d < 1 || d > 29)
				{
					cout << "Day = " << d << " is incorrect" << endl;
					d = myDay;
				}
			}
			else
			{
				if (d < 1 || d > 28)
				{
					cout << "Day = " << d << " is incorrect" << endl;
					d = myDay;
				}
			}
		}
		else
			if (d <1 || d > 31)
			{
				cout << "Day = " << d << " is incorrect" << endl;
				d  = myDay;
			};

	myDay = d;
}

//*************************************************************************************
//Name:  setYear
//Precondition: Date properly initialized.
//Postcondition: Year changed to input value, if correct. If not correct, unchanged
//Description: Year changed to input value,  Negative or zero value for year will
//			   be rejected and year is unchanged.
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	if (y < 1)
	{
		cout << "Year = " << y << " is incorrect" << endl;
		y = myYear;
	}
	myYear = y;
	if (y % 4 == 0 && y % 4000 != 0) cout << "This is a leap year."<< endl;
}

/*********************************************************************************
 * Name: operator<< - overloaded out stream operator
 * Preconditions: valid output stream exists
 * Postcondition: current stored date is placed in the output stream in the
 *  			  form mm/dd/yyyy.
 * Description: places the current date into the output stream
 ********************************************************************************/
ostream & operator<<(ostream & out, const Date & dateObj)
{
	out << setfill('0') << setw(2) << dateObj.myMonth << "/"
		<< setw(2) << dateObj.myDay << "/"
		<< setw(4) << dateObj.myYear;
	return out;
}

/*********************************************************************************
 * Name: operator++() - overloaded preincrement operator
 * Precondition:	valid date object
 * Postcontidion:	day advanced to next calendar date
 * Description: 	one is added to the day and if month or year is changed the
 * 					date object is updated appropriately. Uses private incrementDate
 ********************************************************************************/
Date & Date::operator++()
		{
			this->incrementDate() ;
			return *this;
		}

/*********************************************************************************
 * Name: operator++() - overloaded postincrement operator
 * Precondition:	valid date object
 * Postcontidion:	day advanced to next calendar date
 * Description: 	one is added to the day and if month or year is changed the
 * 					date object is updated appropriately. Uses private incrementDate
 ********************************************************************************/
Date & Date::operator++(int)
		{
			this->incrementDate();
			return *this;
		}

/*********************************************************************************
 * Name: inrementDate
 * Precondition:	valid date object
 * Postcontidion:	day advanced to next calendar date
 * Description: 	one is added to the day and if month or year is changed the
 * 					date object is updated appropriately. Private function
 ********************************************************************************/
void Date::incrementDate()
{
	myDay++;

	// first check if we went beyond the end of the month
	if (myMonth == 9 || myMonth == 4 || myMonth == 6 || myMonth == 11)
	{
		if (myDay > 30)
		{
			myDay = 1;
			myMonth++;
		}
	}
	else
		if (myMonth == 2)
		{
			if ((myYear % 4 == 0 && myYear % 4000 != 0))  // leap year
			{
				if (myDay > 29)
				{
					myDay = 1;
					myMonth = 3;  // set to march since it is the only possiblity
				}
			}
			else
			{
				if (myDay > 28)
				{
					myDay = 1;
					myMonth = 3; // march is the only possibility
				}
			}
		}
		else
			if (myDay > 31)
			{
				myDay = 1;
				myMonth++;
			};

	if (myMonth > 12)
		{
			myMonth = 1;
			myYear++;
		}

}

/*********************************************************************************
 * Name: setDefaultDate - set date object to default values
 * Precondition:	date object exists
 * PostCondition:	date set to 01/01/0001
 * Description:		sets date object to 01/01/0001 overwriting existing data if
 * 					any.  It is used by constructors to initialize Date before
 * 					setting to actually input values.
 ********************************************************************************/
void Date::setDefaultDate()
{
	myMonth = 01;			//January
	myDay = 01;				// 01
	myYear = 0001;			// 0001 AD ??
}
