/********************************************************************************************

Name:              Z#:                            
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:            Due Time: 
Total Points: 100
Assignment:  

Description: 

*********************************************************************************************/

#include "erlang.h"
using namespace std;

double B(const int servers, double load)
{
	if (servers == 0) return 1;

	return (load * B(servers-1, load)) / (servers + load * B(servers - 1, load));
}

double C(const int servers, double load)
{
	return B(servers, load) / (1 - (load/servers)*(1 - B(servers, load)));
}

int choose(const int n, const int k)
{
	if (k > n) return 0;
	if (k == n) return 1;
	if (k == 0) return 1;
	return choose(n-1, k-1)*n / k;
}

unsigned long lchoose(const int n, const int k)
{
	if (k==0) return 1;
	if (k==n) return 1;
	if (k > n) return (unsigned long) 0;
	return lchoose(n-1, k-1)* n / k;
}

long double ldchoose(const int n, const int k)
{
	if (k > n) return 0;
	if (k == n) return 1;
	if (k == 0) return 1;
	return ldchoose(n-1, k-1)*n/k;

}
