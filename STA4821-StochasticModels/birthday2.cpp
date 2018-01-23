#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;
double P_birthday(int n)
{
	if (n <= 1 )		// should not be needed but be safe
	{
		return 0;
	}
	if (n >= 366) return 1.0;
	if (n <= 2)
	{
		return 1.0/365.0 ;
	}
	else
	{
		return P_birthday(n-1)*((367-n)/365.0 * (n-1)/(n-2));
	}
}

int main()
{

	int experiment[] = { 1, 2, 3, 4, 5, 10, 25, 50, 100, 1000, 10000, 20000, 50000, 100000, 250000, 500000, 1000000};
	int index=0, j=01, n=0, m=0;
	cout << sizeof(experiment) << endl;

        for (int i = 2; i <= 365; i++)
	{
		cout << "P(" << i << ") = " << P_birthday(i) << endl ;
	}
	cout << endl;
        n=01;
	do
	{
		double prob=0;
		do
		{
			n=n+1;
			prob += P_birthday(n);
		}
		while ( abs((double)random() / RAND_MAX) >= prob );
		m += n+1;
                //cout << j << " : " << n+1 << "  : " << (double)m/j << endl;
		if (experiment[index] == j)
		{
			cout << j << " : " << n+1 << " : " << 1.0*m/j << endl;
			index++;
		}
		j++;
		n=01;
	} while (j <= experiment[sizeof(experiment)/sizeof(int)-1]);
}
