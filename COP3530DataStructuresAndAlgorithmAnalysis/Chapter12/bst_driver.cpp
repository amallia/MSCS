/********************************************************************************************
bst_driver.cpp
Name: Christopher Foley             Z#: Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 05-Dec-2016           Due Time: 23:59
Total Points: 100
Assignment:  Implement Binary Search Tree - Unit 12

Description: This is a simple program given to provide experience writing code
  for binary trees.  This is a driver to test the CLASS implementation of the BST ADT. 

*********************************************************************************************/

#include <iostream>
#include "bst.h"

using namespace std;
//Sample driver.  Make correction and changes as necessary

int main( )
{

	cout<<"Test1: default constructor\n";
	bst  myTree;

	myTree.print_tree();
	cout<<"End Test1\n";

	{
		cout << "Test1a: test default destructor \n";
		bst B;
	}
	cout << "Test1a: End\n";

	cout<<"Test2:insert\n";
	myTree.insert("new-county", 234658);
    myTree.insert("Newer-county", 12345678);
	myTree.print_tree();
	cout<<"End Test2\n";

	cout<<"Test3: population_ranges\n";
	myTree.population_ranges(0,50000);
	cout<<"End Test3\n";

	cout<<"Test4: del_populaton\n";
	myTree.del_population(173094);
	myTree.print_tree();
	cout<<"End Test4\n";

	cout<<"Test5: del_name\n";
	cout << "First test should fail due to case sensitivity\n";
	myTree.del_name("miami-dade");
	myTree.del_name("new-county");
	cout<<"End Test5\n";

	cout << "Test 5a: delete locally\n";
	{
		bst B;
		B.del_name("Broward");
	}
	cout << "End test 5a\n";
	cout<<"Test6: sorted_info\n";
	myTree.sorted_info();
	cout<<"End Test6\n";

	return 0;
}


