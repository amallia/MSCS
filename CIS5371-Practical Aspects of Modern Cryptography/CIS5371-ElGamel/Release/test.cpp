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
//			A = a_times_b_mod_c(A, A, n);
//			if (k.GetBit(i)) b = a_times_b_mod_c(A, b, n); //(A * b) %n;
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

    Integer x,a, p, g, q;
    ThreadUserTimer timer,t2, t3;

    AutoSeededRandomPool prng;

    AlgorithmParameters params = MakeParameters("BitLength", bit_count, false)
        ("RandomNumberType", Integer::PRIME, false);
/*
    for (unsigned int i = 0; i < 23570; i++)
    {
    	x = 2;
    	a = i;
    	p = 2357;
    	if (A_exp_B_mod_C(x,a,p).IsUnit())
    	{
    		std::cout << x << "^" << a << "mod " << p << " = 1" << std::endl;
    	}
    }*/
    timer.StartTimer();
    double t = timer.ElapsedTimeAsDouble();

    std::cout << "Begin B/A tests" << std::endl;
    std::string plaintext = "";
    std::string plainertext, ciphertext;
    ElGamal TestA = ElGamal(128, 2357, 2, 1185, 1751);
    ElGamal TestB = ElGamal(128, 2357, 2, 1185, 1520);
    TestB.get_public_key(&p, &g, &q);
    if (!TestB.get_private_key(&x))
    {
    	std::cout << "TestB: PRIVATE KEY NOT DEFINED - ENCRYPT ONLY\n";
    }
    std::cout << "TestB: P=" << std::hex << p << std::endl
    		  << "       G=" << std::hex << g << std::endl
			  << "       Q=" << std::hex << q << std::endl
			  << "       X=" << std::hex << x << std::endl;

    TestA.get_public_key(&p, &g, &q);
    if (!TestA.get_private_key(&x))
    {
    	std::cout << "TestA    : PRIVATE KEY NOT DEFINED - ENCRYPT ONLY\n";
    }
    std::cout << "TestA: P=" << std::hex << p << std::endl
    		  << "       G=" << std::hex << g << std::endl
			  << "       Q=" << std::hex << q << std::endl
			  << "       X=" << std::hex << x << std::endl;
/*
    plaintext = "\a\xf3";  //"\x07\xf3";

    ciphertext = TestB.encrypt(plaintext);
    std::cout << "From encrypt:" << std::hex << ciphertext << std::endl;
    plainertext = TestA.decrypt(ciphertext);
    std::cout << std::hex << "plaintext:[" << plaintext << "] ?= plainertext:[" << plainertext << "]" << std::endl;
    if (plaintext == plainertext)
    {
    	std::cout << "decrypt match\n";
    }
    else
    {
    	std::cout << "decrypt mismatch\n";
    }

    plaintext = "\t\?";

    ciphertext = TestA.encrypt(plaintext);
    std::cout << "From encrypt:" << std::hex << ciphertext << std::endl;
    plainertext = TestB.decrypt(ciphertext);
    std::cout << std::hex << "plaintext:[" << plaintext << "] ?= plainertext:[" << plainertext << "]" << std::endl;
    if (plaintext == plainertext)
    {
    	std::cout << "decrypt match\n";
    }
    else
    {
    	std::cout << "decrypt mismatch\n";
    }
*/
    plaintext = "\x01";
    ciphertext = TestB.encrypt(plaintext);
    plainertext = TestA.decrypt(ciphertext);
    std::cout << "Plaintext  :" << std::hex << plaintext << "\n"
     		  << "Ciphertext :" << std::hex << ciphertext << "\n"
 			  << "Plainertext:" << std::hex << plainertext << std::endl;
   std::cout << "plaintext:[" << std::hex << plaintext << "] ?= plainertext:[" << std::hex << plainertext << "]" << std::endl;
    if (plaintext == plainertext)
    {
    	std::cout << "decrypt match\n";
    }
    else
    {
    	std::cout << "decrypt mismatch\n";
    }

    std::cout << "Begin Bob/Alice tests" << std::endl;
    ElGamal alice = ElGamal(bit_count, CZERO, CZERO, CZERO, CZERO);
    alice.get_public_key(&p, &g, &q);
    ElGamal bob =   ElGamal(bit_count, p, g, q, CZERO);
    bob.get_public_key(&p, &g, &q);
    if (!bob.get_private_key(&x))
    {
    	std::cout << "Bob: PRIVATE KEY NOT DEFINED - ENCRYPT ONLY\n";
    }
    std::cout << "Bob: P=" << std::dec << p << " : " << std::hex << p << std::endl
    		  << "     G=" << std::dec << g << " : " << std::hex << g << std::endl
			  << "     Q=" << std::dec << q << " : " << std::hex << q << std::endl
			  << "     X=" << std::dec << x << " : " << std::hex << x << std::endl;

    alice.get_public_key(&p, &g, &q);
    if (!alice.get_private_key(&x))
    {
    	std::cout << "Alice: PRIVATE KEY NOT DEFINED - ENCRYPT ONLY\n";
    }
    std::cout << "Alice: P=" << std::dec << p << " : " << std::hex << p << std::endl
    		  << "       G=" << std::dec << g << " : " << std::hex << g << std::endl
			  << "       Q=" << std::dec << q << " : " << std::hex << q << std::endl
			  << "       X=" << std::dec << x << " : " << std::hex << x << std::endl;

    for (int i = 1; i < 10; i++)
    {
    	q = i*(p-1);
    	x = A_exp_B_mod_C(g, q, p);
    	if (!x.IsUnit())
    	{
    		std::cout << "Generator error " << std::hex << g << std::endl;
    	}
    }
    plaintext = "\x00"; //"Thisisatestmessage.";//0123456789abcdefabcdefghijk";

    ciphertext = bob.encrypt(plaintext);
    std::cout << "From encrypt:" << ciphertext << std::endl;
    plainertext = alice.decrypt(ciphertext);
    std::cout << "Plaintext  :" << std::hex << plaintext << "\n"
    		  << "Ciphertext :" << std::hex << ciphertext << "\n"
			  << "Plainertext:" << std::hex << plainertext << std::endl;
    std::cout << "decrypt(ciphertext) does";
    if (plaintext != plainertext) std::cout << " not";
    std::cout << " match plaintext\n";
    std::cout << "Time: " << (timer.ElapsedTimeAsDouble() - t) << " seconds" << std::endl;
    std::cout << "Elapsed Time: " << timer.ElapsedTimeAsDouble() << " seconds" << std::endl;

    plaintext = "Thisisatestmessage.0123456789abcdefabcdefghijk";

    ciphertext = bob.encrypt(plaintext);
    std::cout << "From encrypt:" << ciphertext << std::endl;
    plainertext = alice.decrypt(ciphertext);
    std::cout << "Plaintext  :" << std::hex << plaintext << "\n"
    		  << "Ciphertext :" << std::hex << ciphertext << "\n"
			  << "Plainertext:" << std::hex << plainertext << std::endl;
    std::cout << "decrypt(ciphertext) does";
    if (plaintext != plainertext) std::cout << " not";
    std::cout << " match plaintext\n";
    std::cout << "Time: " << (timer.ElapsedTimeAsDouble() - t) << " seconds" << std::endl;
    std::cout << "Elapsed Time: " << timer.ElapsedTimeAsDouble() << " seconds" << std::endl;

    return 0;
}



