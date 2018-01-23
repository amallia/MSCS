/********************************************************************************************
bst.cpp
Name: Christopher Foley             Z#: Z15092976
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: 05-Dec-2016           Due Time: 23:59
Total Points: 100
Assignment:  Implement Binary Search Tree - Unit 12

Description:   This is a simple program given to provide experience writing code
  for binary trees.  This is a CLASS implementation of the BST ADT. 

  NOTE:  For class purposes the header file uses the std namespace.  A better implementation
  would be to omit this and explicitly reference the std name space where needed. Thus giving
  users flexibility.

*********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;

/*****************************************************************************
* bst::empty - boolean function to determine if tree is empty
*
* Precondition: bst root properly initialized
*
* Postcondition: true if tree does not exist, false otherwise, no changes
*
****************************************************************************/
bool bst::empty()
{
   return (root==0);
}

/*****************************************************************************
* bst::insert - insert node into tree based upon lexicographical comparison 
*			    of county name.  CASE SENSITIVE
*
* Precondition: bst root properly initialized
*
* Postcondition: node inserted into tree or error if not unique.
*
****************************************************************************/
void bst::insert(string item, double pop)
{
	
	insert(root,item, pop);
	insert(population, pop, item);
}

/*****************************************************************************
* bst::insert - insert node into tree or subtree rooted at loc_ptr based upon 
*               lexicographical comparison of county name.  CASE SENSITIVE
*
* Precondition: bst root properly initialized
*
* Postcondition: node inserted into tree or error if not unique.
*
****************************************************************************/
void bst::insert(treenode * & loc_ptr,string item, double population)
{
    if (loc_ptr==0)
    {
       loc_ptr = new treenode;
       loc_ptr->lchild=loc_ptr->rchild=0;
       loc_ptr->county_name=item;
	   loc_ptr->population_size = population;
    }
    else if (loc_ptr->county_name.compare(item) > 0)		// item lexically less than loc_prt
       insert(loc_ptr->lchild,item, population);
    else if (loc_ptr->county_name.compare(item) < 0)		// item lexically greater than loc_ptr
       insert(loc_ptr->rchild,item, population);
    else
       cout<<"the item is already in the tree\n";
}

/*****************************************************************************
* bst::insert - insert node into tree or subtree rooted at loc_ptr based upon
*               population
*
* Precondition: bst root properly initialized
*
* Postcondition: node inserted into tree or error if not unique.
*
****************************************************************************/
void bst::insert(treenode * & loc_ptr, double population, string item)
{
	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = item;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->population_size > population)		// item lexically less than loc_prt
		insert(loc_ptr->lchild, population, item);
	else if (loc_ptr->population_size < population)		// item lexically greater than loc_ptr
		insert(loc_ptr->rchild, population, item);
	else
		cout << "the item is already in the tree\n";
}

/*****************************************************************************
* bst::search - search full tree for county_name matching passed parameter
*
* Precondition: bst root properly initialized
*
* Postcondition: pointer to node containing county name, if found or 0 returned
*
****************************************************************************/
treenode * bst::search_tree(string item)
{
	return search_tree(root, item);
}

/*****************************************************************************
* bst::search - search subtree for county_name matching passed parameter
*
* Precondition: bst sub tree starting at loc_ptr properly initialized
*
* Postcondition: pointer to node containing county name, if found or 0 returned
*
****************************************************************************/
treenode * bst::search_tree(treenode * loc_ptr, string item)
{
    if (loc_ptr!=0)
    {
       if(loc_ptr->county_name.compare(item) == 0)
          return loc_ptr;
       else if (loc_ptr->county_name.compare(item) > 0)
          return search_tree(loc_ptr->lchild,item);
       else
          return search_tree(loc_ptr->rchild,item);
    }
    else
         return loc_ptr;
}

/*****************************************************************************
* bst::search - search full tree for county population matching passed parameter
*
* Precondition: bst root properly initialized
*
* Postcondition: pointer to node containing county with desired size, if found or 0 returned
*
****************************************************************************/
treenode * bst::search_tree(double target)
{
	return search_tree(population, target);
}

/*****************************************************************************
* bst::search - search subtree for county population matching passed parameter
*
* Precondition: bst subtree properly initialized
*
* Postcondition: pointer to node containing county with desired size, if found or 0 returned
*
****************************************************************************/
treenode * bst::search_tree(treenode *loc_ptr, double target)
{  
	if (loc_ptr != 0)
	{
		if (loc_ptr->population_size  == target)
			return loc_ptr;
		else if (loc_ptr->population_size > target)
			return search_tree(loc_ptr->lchild, target);
		else
			return search_tree(loc_ptr->rchild, target);
	}
	else
		return loc_ptr;
}
	

/*****************************************************************************
* bst::del_name - delete node containing a given name
*
* Precondition: bst root properly initialized
*
* Postcondition: selected root deleted or error displayed
*
****************************************************************************/
void bst::del_name(string item)
{
	treenode *index = search_tree(item);
	if (index == 0)
	{
		cout << "Error: " << item << " not found" << endl;
	}
	else
	{
		double size = index->population_size;
		del_name(root, item);
		del_population(population, size);
	}
}

/*****************************************************************************
* bst::del_name - delete node in a subtree containing a given name
*
* Precondition: bst sub tree properly initialized
*
* Postcondition: selected root deleted or error displayed
*
****************************************************************************/
void bst::del_name(treenode * & loc_ptr, string item)
{

   if (loc_ptr==0)
       cout<<"item " << item << " not in tree\n";

   else if (loc_ptr->county_name.compare(item) > 0)
       del_name(loc_ptr->lchild, item);

   else if (loc_ptr->county_name.compare(item) < 0)
       del_name(loc_ptr->rchild, item);
   
   else
   {
       treenode * ptr;

       if (loc_ptr->lchild == 0)
       {
          ptr=loc_ptr->rchild;
          delete loc_ptr;
          loc_ptr=ptr;
       }
       else if (loc_ptr->rchild == 0)
       {
          ptr=loc_ptr->lchild;
          delete loc_ptr;
          loc_ptr=ptr;
       }
       else
       {
          ptr=inorder_succ(loc_ptr);
          loc_ptr->county_name = ptr->county_name;
		  loc_ptr->population_size = ptr->population_size;
          del_name(loc_ptr->rchild, ptr->county_name);
       }
    }

}

/*****************************************************************************
* bst::del_population - delete node containing specific population
*
* Precondition: bst root properly initialized
*
* Postcondition: node containing population deleted or error displayed.
*
****************************************************************************/
void bst::del_population(double target)
{
	treenode *index = search_tree(target);
	if (index == 0)
	{
		cout << "Error: " << target << " not found" << endl;
	}
	else
	{
		string item = index->county_name;
		del_population(population, target);
		del_name(root, item);
	}
}

/*****************************************************************************
* bst::del_population - delete node in a subtree containing a given population
*
* Precondition: bst sub tree properly initialized
*
* Postcondition: selected root deleted or error displayed
*
****************************************************************************/
void bst::del_population(treenode * & loc_ptr, double target)
{

	if (loc_ptr == 0)
		cout << "item " << target << " not in tree\n";

	else if (loc_ptr->population_size > target)
		del_population(loc_ptr->lchild, target);

	else if (loc_ptr->population_size < target)
		del_population(loc_ptr->rchild, target);

	else
	{
		treenode * ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			loc_ptr->population_size = ptr->population_size;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}

}

/*****************************************************************************
* bst::inorder_succ - find in order successor 
*
* Precondition: bst root properly initialized
*
* Postcondition: successor returned
*
****************************************************************************/
treenode * bst::inorder_succ(treenode * loc_ptr)
{

  treenode *ptr=loc_ptr->rchild;

  while(ptr->lchild!=0)
  {
     ptr=ptr->lchild;
  }
    return ptr;
}


/*****************************************************************************
* bst::population_ranges - print county names to screen containing population 
*                          between low and high limits
*
* Precondition: bst root properly initialized, low <= high
*
* Postcondition:names output.
*
****************************************************************************/
void bst::population_ranges(const double &low, const double &high)
{
	population_ranges(population, low, high);
}

/*****************************************************************************
* bst::population_ranges - print county names to screen containing population
*						   between low and high limits
*
* Precondition: bst root properly initialized
*
* Postcondition:
*
****************************************************************************/
void bst::population_ranges(treenode *loc_ptr, const double &low, const double &high)
{
	if (loc_ptr != 0)
	{
		population_ranges(loc_ptr->lchild, low, high);
		if (loc_ptr->population_size >= low && loc_ptr->population_size <= high)
		{
			cout << loc_ptr->county_name << endl;
		}
		population_ranges(loc_ptr->rchild, low, high);
	}
}

/*****************************************************************************
* bst::print_tree - print tree in order based on population size
*
* Precondition: bst properly initialized
*
* Postcondition: tree output
*
****************************************************************************/
void bst::print_tree()
{
	print_tree(population);
}

/*****************************************************************************
* bst::print_tree - print tree in order based on given root
*
* Precondition: bst properly initialized
*
* Postcondition: tree output
*
****************************************************************************/
void bst::print_tree(treenode * loc_ptr)
{
  if (loc_ptr!=0)
  {
   print_tree(loc_ptr->lchild);
   cout<<loc_ptr->county_name << "\t" << loc_ptr->population_size <<endl;
   print_tree(loc_ptr->rchild);
  }
}

/*****************************************************************************
* bst::sorted_info - print county records to file
*
* Precondition: bst root properly initialized
*
* Postcondition: "county_info.txt" created
*
****************************************************************************/
void bst::sorted_info()
{
	ofstream out;
	out.open("county_info.txt");
	sorted_info(out, root);
	out.close();
}

/*****************************************************************************
* bst::sorted_info - print tree below a specific root
*
* Precondition: bst root properly initialized
*
* Postcondition: tree output
*
****************************************************************************/
void bst::sorted_info(ofstream &out, treenode *loc_ptr)
{
	if (loc_ptr != 0)
	{
		sorted_info(out, loc_ptr->lchild);
		out << loc_ptr->county_name << "\t" << loc_ptr->population_size << "\n";
		sorted_info(out, loc_ptr->rchild);
	}
}

void bst::delete_tree(treenode *root)
{
	if (root != 0)
	{
		delete_tree(root->lchild);
		delete_tree(root->rchild);
		delete root;
	}
}
/*****************************************************************************
* bst::~bst - bst destructor
*
* Precondition: bst root properly initialized
*
* Postcondition:
*
****************************************************************************/
bst::~bst()
{
	delete_tree(root);
	root = 0;
	delete_tree(population);
	population = 0;
}

/*****************************************************************************
* bst::bst - constructor
*
* Precondition: bst root properly initialized
*
* Postcondition:
*
****************************************************************************/
bst::bst()
{
	ifstream in;
	string name;
	double size;
    root = 0;
	population = 0;
	in.open("county_data.txt");

	in >> name >> size;
	
	while (!in.eof())
	{
		insert(name, size);
		in >> name >> size;
	}

	in.close();
}


/*****************************************************************************
* bst::bst_main - test main method
*
* Precondition: bst root properly initialized
*
* Postcondition:
*
****************************************************************************/
int bst_main()
{
    bst B;
	//treenode *root1=0, *root2=0;
    string s;
	int p;
    char ch;
    string key3; 
    string key4;
	string response;
	string r1, r2;
    cout<<"enter command, c=count, i=insert item,s=search tree,d=delete item,p=print tree, r = range, e=exit: ";
    cin>>ch;
    cout<<endl;

    while (ch!='e')
    {
       switch (ch)
       {
	   case 'i'  :cout<<"enter string: ";
             cin>>s;
			 cout << "enter number: ";
			 cin >> p;
             B.insert(s, p );
             break;
 
       case 's'  :cout<<"enter word to search for: ";
             cin>>s;
             if (!B.search_tree(s))
                cout<<s<<"not in tree\n";
             else
                cout<<s<<" was found in the tree\n";
             break;
       case 'd'  :cout<<"enter word to delete: ";
                  cin>>s;
                  B.del_name(s);
                  break;
       case 'p'  :cout<<"...printing tree...\n";
             B.print_tree();
			 break;
		   
				default:break;
      }
      cout<<"enter command, i=insert item,s=search tree,d=delete item,p=print tree, e=exit: ";
      cin>>ch;
      cout<<endl;
    }
	cout<<endl<<"no more binary tree.....\n";
    return 0;
} 
     
