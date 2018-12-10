/*
 * ElGamal.cpp
 *
 *  Created on: Oct 22, 2018
 *      Author: Christopher Foley / Bijayita Thapa
 */
#include "cryptopp/integer.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hrtimer.h"
#include "cryptopp/algparam.h"
#include "cryptopp/nbtheory.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <exception>
#include <assert.h>
#include "ElGamal.h"

static const CryptoPP::Integer CZERO((long)0);
CryptoPP::Integer ElGamal::hexStringToInteger(std::string inString)
{
	CryptoPP::Integer x = CZERO;
	for (unsigned int i = 0; i < inString.length(); i++)
	{
		int  n = char(inString[i]);
		if (n >= '0' && n <= '9')
			n = n - '0';
		else
			n = (n < 'a') ? n - 'A' +10 : n - 'a'+10;
		if (inString[i] != 'h')
		{
			x *=0x10;
			n &= 0x0f;
			x |= n;
		}
	}
	return x;

}
std::string ElGamal::integerToHexString(CryptoPP::Integer inInt)
{
	size_t intLen = inInt.MinEncodedSize();
	std::string s;

	s.resize(intLen);
	inInt.Encode((CryptoPP::byte *)s.data(), s.size(), CryptoPP::Integer::UNSIGNED);

	return s;
}
CryptoPP::Integer ElGamal::A_exp_B_mod_C(CryptoPP::Integer a, CryptoPP::Integer k, CryptoPP::Integer n)  // redefine cryptopp
{														// to satisfy requirements
	CryptoPP::Integer b =1.;										// and show we know how
	if (!k.IsZero())			// use non zero for common return
	{
		CryptoPP::Integer A = a;
		unsigned int t=a.BitCount()+16;
		while (!k.GetBit(t)) t--;		// when we finish t is the highest set bit
		if (k.IsOdd()) b = a;
		for (unsigned int i = 1; i <= t; i ++)
		{
			A = (A*A) % n;
			if (k.GetBit(i)) b = (A * b) % n;
		}
	}
	assert (b == a_exp_b_mod_c(a, k, n));
	return b;
}

bool ElGamal::relativelyPrime(CryptoPP::Integer a, CryptoPP::Integer b)
{
	CryptoPP::Integer q=a, r=b;
	while ((q > 1.) && (r > 1.))
	{
		if (q > r)
		{
			q %= r;
		}
		else
		{
			r %= q;
		}
	}
	return (q.IsUnit() || r.IsUnit());
}

bool ElGamal::isPrime(CryptoPP::Integer p)
{
	CryptoPP::Integer a, r, y, p1;							// a relatively prime value is required
	unsigned int s;

    CryptoPP::AutoSeededRandomPool prng;

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
#ifndef _USE_FERMAT
	for (int i = 0; i < 40; i++)
	{
		a = p;
		a++;					// force a to be greater than p for loop trigger
		while( a > p) a.Randomize(prng, 2, p-2);
		CryptoPP::Integer y = A_exp_B_mod_C(a, r, p);		// assignment requires our own exp
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
#else

	// Find Integer a relatively prime to p
	do
	{
		a.GenerateRandom(prng, params);
	} while (!relativelyPrime(a, p));


	a = a_exp_b_mod_c(a, p-1, p);

	return a.IsUnit();
#endif
}

bool ElGamal::get_public_key(CryptoPP::Integer *prime, CryptoPP::Integer *generator, CryptoPP::Integer *public_key)
{
	if (!this->prime.IsZero())
	{
		*prime = this->prime;
		*generator = this->generator;
		*public_key = this->public_key;
	}
	return !this->prime.IsZero();
}

bool ElGamal::get_private_key(CryptoPP::Integer *private_key)
{
#ifdef _ELGAMAL_DEBUG_
	*private_key = this->private_key;
#endif
	return !this->private_key.IsZero();
}
ElGamal::ElGamal(int key_length)
{
	CryptoPP::Integer CZERO = 0;
	_set_ElGamal(key_length, CZERO, CZERO, CZERO, CZERO);
}
ElGamal::ElGamal(int key_length, CryptoPP::Integer p=((long) 0), 			/* prime number - forms modulus */
		                         CryptoPP::Integer generator=CryptoPP::Integer((long)0),		/* field generator */
								 CryptoPP::Integer public_key=0, 	/* generated public key */
								 CryptoPP::Integer private_key=0)	/* private key */
{
	_set_ElGamal(key_length, p, generator, public_key, private_key);
}

void ElGamal::_set_ElGamal(int key_length, CryptoPP::Integer p=((long) 0), 			/* prime number - forms modulus */
		                         CryptoPP::Integer generator=CryptoPP::Integer((long)0),		/* field generator */
								 CryptoPP::Integer public_key=0, 	/* generated public key */
								 CryptoPP::Integer private_key=0)	/* private key */
{
	if ((key_length & (key_length-1)) != 0) throw "bit length not power of 2";
	this->private_key = private_key;
	this->prime = p;
	this->generator = generator;
	this->public_key = public_key;
	this->bit_length = key_length;
	int random_size = key_length;

    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::AlgorithmParameters params = CryptoPP::MakeParameters("BitLength", random_size, false)
                ("RandomNumberType", CryptoPP::Integer::ANY, false);

    CryptoPP::PrimeAndGenerator png;
    //  new parameters

    if (this->prime.IsZero())
    {
    	png.Generate(1, prng, key_length, key_length-16);
    	this->prime = png.Prime();
    	this->generator = png.Generator();
    	while (!isPrime(this->prime))
    	{
    		this->prime.GenerateRandom(prng, params);				// Generate large prime
    	}


    	/*
    	 * Find private key - a prime in range 1 - prime
    	 */
    }
    if (this->private_key.IsZero()) this->private_key = CryptoPP::Integer(prng, (CryptoPP::Integer)1, this->prime-16);
    if (this->public_key.IsZero()) 	this->public_key = A_exp_B_mod_C(this->generator, this->private_key, this->prime);

}

ElGamal::~ElGamal()
{
	this->private_key = 0;
	this->generator = 0;
}

std::string ElGamal::encrypt(std::string ciphertext)
{
	CryptoPP::Integer m,x, k, g, d;
	unsigned int pi=0;				// cipher index and plain index
	std::string temp, plaintext=ciphertext;
	std::stringstream gs;  // generator stream, encrypted stream

    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::AlgorithmParameters params = CryptoPP::MakeParameters("BitLength", bit_length, false)
                ("RandomNumberType", CryptoPP::Integer::ANY, false);

    if (public_key.IsZero())
    {
		throw "Key not set.";
	}
    if (private_key.IsZero())
    {
    	private_key = CryptoPP::Integer(prng, (CryptoPP::Integer)1, this->prime-2);
    }
    g = A_exp_B_mod_C(generator, private_key, prime);
#ifdef _ELGAMAL_DEBUG_
    std::cout << "Generator:" << std::hex << generator << "^" << private_key << " = " << g << std::endl;
#endif

	gs << std::hex << g;
	gs >> ciphertext;
	ciphertext += " ; ";

	{
		std::stringstream xs;  // generator stream, encrypted stream

		m = 0;
		for (unsigned int i=0; i < prime.MinEncodedSize();i++)				// use bytes to encode prime - 1 (zero relative)
		{
			if (pi < plaintext.length())
			{
				m *= 0x100;
				unsigned int j = (int)plaintext[pi++] & 0x00ff;		// move character otherwise pad with zero due to shift
				m += j;
			}
		}
		x = (m * A_exp_B_mod_C(public_key, private_key, prime)) % prime;
//	x = a_times_b_mod_c(m, A_exp_B_mod_C(public_key, private_key, prime), prime);
#ifdef _ELGAMAL_DEBUG_
		std::cout << "m (hex):" << std::hex << m << std::endl;
		std::cout << "Cipher??" << std::hex << x << std::endl;
#endif
		xs << std::hex << x;
		xs >> temp;
	    ciphertext = ciphertext + temp;
#ifdef _ELGAMAL_DEBUG_
//		std::cout << "Temp:" << temp << std::endl;
//		std::cout << "rvalue:" << ciphertext << std::endl;
#endif
	}

	return ciphertext;
}

std::string ElGamal::decrypt(std::string plaintext)
{
	std::string ciphertext, temp, delimiter;
	std::stringstream ss, ss2;
	CryptoPP::Integer m,x,d,g,q;

	if (private_key.IsZero())
	{
		throw "Key not set.";
	}
	ss << plaintext;
	ss >> temp >> delimiter >> ciphertext;
	plaintext = "";
#ifdef _ELGAMAL_DEBUG_
//	std::cout  << "decrypt g(string):" << temp << std::endl;
//	std::cout  << "decrypt y(string):" << ciphertext << std::endl;
#endif
	g = hexStringToInteger(temp);
	{
		x = hexStringToInteger(ciphertext);
		q = prime - 1 - private_key;
		d = A_exp_B_mod_C(g, q , prime);
		m = (d * x) % prime;				//a_times_b_mod_c(d, x, prime);
#ifdef _ELGAMAL_DEBUG_
		std::cout << "decrypt g:(Integer)" << std::hex << g << std::endl;
		std::cout << "decrypt prime      " << std::hex << prime << std::endl;
		std::cout << "decrypt x:(Integer)" << std::hex << x << std::endl;
		if (q.IsNegative()) std::cout << "oh crap! \n";
		std::cout << "m:>>" << std::hex << m << "<<:" << std::endl;
#endif
		plaintext += integerToHexString(m);
	}
	return plaintext;
}
