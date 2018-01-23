/********************************************************************************************
file: VLIST.H		VLIST header file.
Name: Christopher Foley              Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 07-Nov-2016           Due Time:
Total Points: 100
Assignment: Vectors, Iterators and Templates Chapter 9

Description: Created project RogerRoger to test Vector class.

**********************************************************************************************/

#ifndef VLIST_H_
#define VLIST_H_
using namespace std;

#include <vector>
#include <string>

class VLIST
{

public:
	VLIST();
	VLIST(const VLIST &);
	~VLIST();
	bool Is_Full();
	bool Is_Empty();
	vector<string>::iterator Search(const string &);
	void Insert(const string &);
	void Remove(const string &);
	void Print();
private:
	vector<string> DB;			//vector
								//additonal state variables you may wish add
};



#endif /* VLIST_H_ */
