/********************************************************************************************
file: BQUEUE.cpp
Name: Christopher Foley             Z#:15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time:
Total Points: 100
Assignment:  Program Unit 8

Description: This file implements circular queue.

*********************************************************************************************/


#include "BQUEUE.h"

using namespace std;

/*****************************************************************************
 * bqnode::bqnode - constructor for bqnode data structure used for queue
 *
 * Precondition: none
 *
 *
 * Postcondition: a bqnode structure is initialized with prev and next pointers
 * pointing to itself.  "time" field (specified in requirements) is explicitly
 * initialized to 0.
 *
 ******************************************************************************/

bqnode::bqnode(): prev(this), next(this), time(0)
{};

/*****************************************************************************
 * BQUEUE::BQUEUE - Default constructor
 *
 * Precondition: none
 *
 *
 * Postcondition: a BQUEUE structure is initialized to accept queued data
 *
 *
 *****************************************************************************/
BQUEUE::BQUEUE():front(NULL)
{};

/*****************************************************************************
 * BQUEUE::BQUEUE - Default destructor
 *
 * Precondition: a BQUEUE structure pointing to valid bqnodes exists or has
 * 			     a zero pointer
 *
 *
 * Postcondition: all bqnodes are dequeued and freed, BQUEUE.front is cleared.
 *
 *
 *****************************************************************************/

BQUEUE::~BQUEUE()
{
	while (front != NULL)
	{
		Dequeue();
	}

}

/*****************************************************************************
 * BQUEUE::BQUEUE(const BQUEUE &) - copy constructor
 *
 * Precondition: valid BQUEUE
 *
 *
 * Postcondition: a BQUEUE structure containing a copy of the source queue is
 * 				  created
 *
 *****************************************************************************/

BQUEUE::BQUEUE(const BQUEUE &source):front(NULL)
{

	if (source.front != NULL)
	{
		bqnode *s = source.front;
		do
		{
			Enqueue(s->time);
			s = s->next;
		} while (s != source.front);
	}
}

/*****************************************************************************
 * BQUEUE::Dequeue - remove first element of queue and free it
 *
 * Precondition: BQUEUE created via valid constructor
 *
 *
 * Postcondition: first element removed and queue adjusted
 *
 *
 *****************************************************************************/
void BQUEUE::Dequeue()
{
	bqnode *p = front;

	if (p != NULL)
	{
		if (front->next == front)		// only one node remains
		{
			front = NULL;
		}
		else
		{								// more than one node
			p->next->prev = p->prev;		// next points back to previous
			p->prev->next = p->next;		// previous points to my next
			front = p->next;				// update front pointer
		}
		delete p;
		p = front;
	}

}

/*****************************************************************************
 * BQUEUE::Enqueue(int) - add integer element to queue
 *
 * Precondition: none
 *
 *
 * Postcondition: a BQUEUE structure is initialized to accept queued data
 *
 *
 *****************************************************************************/
void BQUEUE::Enqueue(int value)
{
	bqnode *p = new bqnode();
	p->time = value;

	if (front == NULL)					// first node?
	{
		front = p;
	}
	else
	{
		p->next = front;
		p->prev = front->prev;
		front->prev = p;
		p->prev->next = p;
	}

}

/*****************************************************************************
 * BQUEUE::Print() - print contents of queue
 *
 * Precondition: none
 *
 *
 * Postcondition: none
 *
 *
 *****************************************************************************/
void BQUEUE::Print()
{
	cout << "{ ";

	if ( front != NULL)
	{
		bqnode *p = front;
		do
		{
			cout << p->time;
			if (p->next != front) cout << ", ";		// print delimiter
			p = p->next;
		} while (p != front);
	}

	cout << " }" << endl;

}

