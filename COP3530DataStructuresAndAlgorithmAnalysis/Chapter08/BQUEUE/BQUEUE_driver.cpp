/********************************************************************************************
File: BQUEUE_driver.cpp
Name: Christopher Foley             Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  Program Unit 8

Description: In this assignment we do the following: (1) allocate memory dynamically, (2) manipulate
pointers, (3) Implement a default constructor, copy constructor and destructor for doubly linked queue
(4) a requirement is to only use a pointer to the front of the queue.

*********************************************************************************************/

#include <iostream>
#include "BQUEUE.h"

using namespace std;

int main()
{
	BQUEUE k;

	k.Enqueue(60);
	k.Print();
	k.Enqueue(20);
	k.Enqueue(30);
	k.Print();
	k.Enqueue(10);
	k.Print();
	k.Enqueue(50);
	k.Enqueue(40);

	cout << "expected values: 60, 20, 30, 10, 50, 40" << endl;
	k.Print();

	cout << "copy constructor print j" << endl;
	BQUEUE j = k;

	j.Print();

	cout << "dequeue and print to verify correct use" << endl;
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Print();
	j.Dequeue();
	j.Print();
	j.Dequeue();

	j.Print();

	cout << "print k" << endl;

	k.Print();

	{
		BQUEUE l = k;

	}

	cout << "print k, to ensure copy constructor doesnt cause problems" << endl;

	k.Print();
}


