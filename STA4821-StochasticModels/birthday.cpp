#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int experiment[] = { 1, 2, 3, 4, 5, 10, 25, 50, 100, 1000, 10000, 20000, 50000, 100000, 250000, 500000, 1000000};
	int index=0, j=01, n=0, m=0;
	cout << sizeof(experiment) << endl;
	do
	{
		do
		{
			n=n+1;
		}
		while ( random() % 365 >= n );
		m += n+1;
		if (experiment[index] == j)
		{
			cout << j << " : " << n+1 << " : " << 1.0*m/j << endl;
			index++;
		}
		j++;
		n=0;
	} while (j <= experiment[sizeof(experiment)/sizeof(int)-1]);
}
