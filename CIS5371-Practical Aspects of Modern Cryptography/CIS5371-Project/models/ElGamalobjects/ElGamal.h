/*
 * ElGamal.h
 *
 *  Created on: Oct 22, 2018
 *      Author: Christopher Foley / Bijayita Thapa
 */
#include <string>
#include <cstring>
#include "cryptopp/integer.h"
#ifndef ELGAMAL_H_
#define ELGAMAL_H_

enum state {FIRST, ENCRYPTION, DECRYPTION};

class ElGamal
{
public:
	ElGamal(int bit_length);
	ElGamal(int bit_length, CryptoPP::Integer prime, CryptoPP::Integer generator, CryptoPP::Integer public_key, CryptoPP::Integer private_key); // encrypt/decrypt
	~ElGamal();
	bool get_public_key(CryptoPP::Integer *prime, CryptoPP::Integer *generator, CryptoPP::Integer *public_key);
	bool get_private_key(CryptoPP::Integer *private_key);
	std::string encrypt(std::string );
	std::string decrypt(std::string );
private:
	int 			  bit_length=0;
	CryptoPP::Integer prime;
	CryptoPP::Integer private_key;
	CryptoPP::Integer generator;
	CryptoPP::Integer public_key;
	CryptoPP::Integer A_exp_B_mod_C(CryptoPP::Integer , CryptoPP::Integer , CryptoPP::Integer );  // redefine cryptopp
	bool 			  isPrime(CryptoPP::Integer);															  // our own isPrime
	bool 			  relativelyPrime(CryptoPP::Integer, CryptoPP::Integer);									  // and our relatively prime
	void              _set_ElGamal(int, CryptoPP::Integer, CryptoPP::Integer, CryptoPP::Integer, CryptoPP::Integer); // initialize context
	CryptoPP::Integer hexStringToInteger(std::string);
	std::string       integerToHexString(CryptoPP::Integer);
};

#endif /* ELGAMAL_H_ */
