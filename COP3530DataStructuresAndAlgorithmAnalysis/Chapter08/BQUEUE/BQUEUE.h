/********************************************************************************************
file: BQUEUE.h
Name: Christopher Foley             Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Program Unit 8

Description: header file for BQUEUE assignment
*********************************************************************************************/


#ifndef BQUEUE_H_
#define BQUEUE_H_
#include <iostream>
using namespace std;

class bqnode
{
public:
	bqnode();

	int time;
	bqnode *prev, *next;
};

class BQUEUE {
public:
	BQUEUE();
	BQUEUE(const BQUEUE &);
	~BQUEUE();
	void Enqueue(int);
	void Dequeue();
	void Print();

private:
	bqnode *front;		// only permitted one pointer
};


#endif /* BQUEUE_H_ */
