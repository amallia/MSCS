/********************************************************************************************
bst.h
Name: Christopher Foley             Z#: Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 05-Dec-2016           Due Time: 23:59
Total Points: 100
Assignment:  Implement Binary Search Tree - Unit 12

Description: This is a simple program given to provide experience writing code
  for binary trees.  This is a header file for the CLASS implementation of the BST ADT. 

  NOTE:  For class purposes the header file uses the std namespace.  A better implementation 
  would be to omit this and explicitly reference the std name space where needed. Thus giving 
  users flexibility.

*********************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#ifndef BST_H_
#define BST_H_

class treenode
{
public:
   string county_name;
   double population_size;
   treenode *lchild, *rchild;
};

class bst
{
public:
	bst();										// stores "county_data.txt" in tree
	~bst();										// deallocate tree
	bool empty();								// is tree empty
	void insert(string, double);					// insert record into tree based on name
	void insert(treenode * &, string item, double);		// see insert above
	void del_name(string item);					// delete a county based on name
	void del_population(double);				// delete a county record based on population
	treenode * search_tree(treenode *,string item); /// return pointer to node with item name
	treenode * search_tree(string item);		// see above
	treenode * search_tree(treenode *, double population);		// return pointer based on population
	treenode * search_tree(double population);	// return pointer based on population
	treenode * inorder_succ(treenode *);		// in order successor to current node
	void print_tree();							// print tree in order
	void print_tree(treenode *);				// print tree in order starting at node
	void population_ranges(const double &, const double &); // print counties with population in ranges
	void sorted_info();							// output tree to "county_info.txt"

private:
	void del_name(treenode * & loc_ptr, string item);	// see above
	void del_population(treenode * &, double);	// see above
	void population_ranges(treenode *, const double &, const double &);	// see above
	void sorted_info(ofstream &, treenode *);
	void insert(treenode *&, double, string);	// insert based upon population
	void delete_tree(treenode * loc_ptr);		// delete entire tree rooted at loc_ptr;

	treenode *root, *population;
};





#endif /* BST_H_ */
