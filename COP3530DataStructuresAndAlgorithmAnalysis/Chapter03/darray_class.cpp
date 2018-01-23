
#include<iostream>
#include<fstream>

using namespace::std;

class ARRAY
{
public:

	ARRAY();
	~ARRAY();
	void Insert(int);
	bool Is_Full(){return count == capacity;};
	bool Is_Empty(){return count == 0;};
	void Print();
	int Search(int);
	void Remove(int);
private:
	int count;
	int capacity;
	int *Array;
};

/*this is an example of a default constructor*/
ARRAY::ARRAY()
{
	cout<<"defualt constructor has been invoked \n";
	count =0;
	capacity =12;
	Array = new int[capacity];
	int i;
	ifstream in;
	in.open("myData.txt");

	while(!in.eof())
	{
		in>>i;
		Insert(i);
	}
	in.close();
}

ARRAY::~ARRAY()
{
	cout<<"destructor has been invoked\n";
	delete [ ] Array;
}

void ARRAY::Insert(int i)
{
	cout<<"Insert has been invoked\n";
	if (!Is_Full())
	{
		Array[count] = i;
		count++;
	}
}

void ARRAY::Print()
{
	cout<<"Print has been Invoked\n";
	for (int i = 0; i<count; i++)
	{
		cout<<"Array[ "<< i << " ] = " << Array[i] <<endl;
	}
}

int ARRAY::Search(int key)
{
	cout<<"Search has been invoked \n";
	for (int i=0; i<count; i++)
	{
		if (Array[i] == key)
		{
			return i;
		}
	}
	return -1;
}

void ARRAY::Remove(int key)
{
	cout<<"Remove has been invoked \n";
	int i = Search(key);

	if (i != -1)
	{
		for(int j = i; j<count -1; j++) //shifting array down
		{
			Array[j] = Array[j+1];
		}
	}
}


int main()
{
	ARRAY yourArray;

	yourArray.Print();

	return 0;
}