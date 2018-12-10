/*
 * test.cpp
 *
 *  Created on: Oct 23, 2018
 *      Author: Christopher Foley / Bijayita Thapa
 */
#include "cryptopp/integer.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hrtimer.h"
#include "cryptopp/algparam.h"
#include "cryptopp/nbtheory.h"
#include <iostream>
#include <string>
#include <cstring>
#include "ElGamal.h"
using namespace CryptoPP;
static int bit_count = 4096;
static const Integer CZERO((long)0);
Integer A_exp_B_mod_C(Integer a, Integer k, Integer n)  // redefine cryptopp
{														// to satisfy requirements
	Integer b =1.;										// and show we know how
	if (!k.IsZero())			// use non zero for commoon return
	{
		Integer A = a;
		unsigned int t = k.BitCount();
		while (!k.GetBit(t)) t--;		// when we finish t is the highest set bit
		if (k.IsOdd()) b = a;
		for (unsigned int i = 1; i <= t; i ++)
		{
			A = (A*A) % n;
			if (k.GetBit(i)) b = (A * b) %n;
		}
	}
	return b;
}
bool relativelyPrime(Integer a, Integer b)
{
	Integer remainder;
	while ((a > 1.) && (b > 1.))
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return (a.IsUnit() || b.IsUnit());
}
bool isPrime(Integer p)
{
	Integer a, r, y, p1;							// a relatively prime value is required
	unsigned int s;

    AutoSeededRandomPool prng;
    AlgorithmParameters params = MakeParameters("BitLength", bit_count, false)
                ("RandomNumberType", Integer::ANY, false);


    p1 = p;				// speed processing with p1 = p-1
    p1--;				// use decrement operatr instead of -1.
	if (p.IsEven())
		return false;

	r = p1;		// evaluate: p-1=(2^r)s
	s=0;
	while (r.IsEven())
	{
		s++;
		r /=2.;
	}
	for (int i = 0; i < 25; i++)
	{
		a = p;
		a++;					// force a to be greater than p for loop trigger
		while( a > p) a.Randomize(prng, 2, p-2);
		Integer y = A_exp_B_mod_C(a, r, p);		// assignment requires our own exp
		if (!y.IsUnit() && (y != p1))
			{
				unsigned int j = 1;
				while ((j <= (s-1)) && ( y != p1))
					{
						y = (y * y) % p;
						if (y.IsUnit()) return false;
						j++;
					}
				if (y != p1) return false;
			}
	}
	return true;					// prime
/** Comment out Fermat Theorem implementation
	do
	{
		a.GenerateRandom(prng, params);
	} while (!relativelyPrime(a, p));

	a = a_exp_b_mod_c(a, p-1, p);
	std::cout << "aexpbmodc " << a << std::endl;

	return a.IsUnit();
 */
}
int main(int , char**)
{
  //  using namespace CryptoPP;

    Integer x,a;
    ThreadUserTimer timer,t2, t3;

    AutoSeededRandomPool prng;

    AlgorithmParameters params = MakeParameters("BitLength", bit_count)
        ("RandomNumberType", Integer::PRIME);

    timer.StartTimer();
    x.GenerateRandom(prng, params);
    double t = timer.ElapsedTimeAsDouble();

    std::cout << "CryptoPP (Random/Integer::Prime) Time: " << t << " seconds" << std::endl;
    std::cout << "Bit Count: (" << x.BitCount() << ")" <<  x << std::endl << std::endl;
    std::cout << "0x" << std::hex << x << std::endl;

    //  new parameters
    params = MakeParameters("BitLength", bit_count)
                ("RandomNumberType", Integer::ANY);

    bool prime = false;
//    t2.StartTimer();
    while (!prime)
    {
    	a.GenerateRandom(prng, params);
    	prime = isPrime(a);
    }
//    t = t2.ElapsedTimeAsDouble();
    std::cout << "CryptoPP (Random/Integer::ANY) Time: " << (timer.ElapsedTimeAsDouble() - t) << " seconds" << std::endl;
    std::cout << "Bit Count: (" << a.BitCount() << ")" <<  a << std::endl << std::endl;
    std::cout << "0x" << std::hex << a << std::endl;

    t = timer.ElapsedTimeAsDouble();

//    t3.StartTimer();
    PrimeAndGenerator png;
    Integer p=4., q, g;
    while (!isPrime(p))
    {
        png.Generate(1, prng, bit_count, bit_count-16);
        p = png.Prime();
        q = png.SubPrime();
        g = png.Generator();

    }
//    t = t3.ElapsedTimeAsDouble();

    std::cout << "CryptoPP (Prime and Generator) Time: " << (timer.ElapsedTimeAsDouble() - t) << " seconds" << std::endl;
    std::cout << "Prime: (" << p.BitCount() << ")" << p
    		  << "\nSubPrime: (" << q.BitCount() << ")" << q
			  << "\nGenerator: (" << g.BitCount() << ")" << g << "\n\n" << std::endl;
    t = timer.ElapsedTimeAsDouble();

    std::cout << "Test square and multiply algorithm:  1430^605 mod 2357 = " << std::dec << A_exp_B_mod_C(1430, 605, 2357) << "(872 = 368h)\n";
    std::cout << "Test square and multiply algorithm:  5^596 mod 1234 = " << A_exp_B_mod_C(5, 596, 1234) << "(1013 = 3f5h)\n";
    std::cout << "Now really test it: (generator)^subprime mod prime=" << A_exp_B_mod_C(g, q, p) << " (1 expected)" << std::endl;

    std::cout << "Try using my methods (CryptoPP / Random/ Integer::ANY) \n";
    p =  4;
    while (!isPrime(p))
    {
        p.GenerateRandom(prng, params);
    }
    std::cout << "Prime: (" << p.BitCount() << ")" << p;
	bool foundGenerator = false;
	q = (p-1) / 2;
	Integer r;
	while (!foundGenerator)
	{
		r = Integer(prng, 1, p);
		foundGenerator = !(A_exp_B_mod_C(r,2, p).IsUnit() ||
						   A_exp_B_mod_C(r, q, p).IsUnit());
	};

    std::cout << "\nGenerator: (" << r.BitCount() << ")" << r << std::endl;
    		    std::cout << "Time: " << (timer.ElapsedTimeAsDouble() - t) << " seconds" << std::endl;


    std::cout << "Now really test it: (generator)^subprime mod prime=" << A_exp_B_mod_C(g, q, p) << " (1 expected)" << std::endl;
   return 0;
}



