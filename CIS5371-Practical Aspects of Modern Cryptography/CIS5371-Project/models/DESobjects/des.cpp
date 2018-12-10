/*
 * des.h
 *
 *  Created on: Sep 14, 2018
 *      Author: Christopher Foley / Bijayita Thapa
 */
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <assert.h>
#include <stdint.h>
#include <malloc.h>
#include "des.h"

using namespace std;
/*****************************************************************************
 * uint64_to_string - convert a unisgned 64 bit value to C++ string
 *
 * Precondition: none
 *
 *
 * Postcondition: a string containing the value of the unsigned 64 bit input
 *
 ******************************************************************************/
string uint64_to_string( uint64_t value ) {
    std::ostringstream os;
    os << value;
    return os.str();
};

// special functions to rotate the top 28 bits of unsigned 32 bit integer
/*****************************************************************************
 * rol28 - rotate left the upper 28 bits of unsigned integer
 *
 * Precondition: none
 *
 *
 * Postcondition: the upper 28 bits of a unsigned integer are rotated.  The lower
 * bits will be in an undermined state.
 *
 ******************************************************************************/
static unsigned int rol28(unsigned int x, int n)
{
	assert(n<28);
	return (x<<n | x >> (28-n));
}

/*****************************************************************************
 * rol28 - rotate right the upper 28 bits of unsigned integer
 *
 * Precondition: none
 *
 *
 * Postcondition: the upper 28 bits of a unsigned integer are rotated.  The lower
 * bits will be in an undermined state.
 *
 ******************************************************************************/
static unsigned int ror28(unsigned int x, int n)
{
	assert(n<28);
	return(x>>n | x << (28-n));
}

/*****************************************************************************
 * DES::DES - constructor for DES data structure
 *
 * Precondition: none
 *
 * Input:  key - 64 bit key used to (de/en)crypt
 *         mode - mode of operation (ECB or CBC).  If not specified ECB is selected.
 *
 * Postcondition: a DES structure is initialized with values. The 16 sub keys
 *                used in encryption and decryption are created.
 *
 ******************************************************************************/
DES::DES(uint64_t key, uint64_t iVector, des_mode mode)
{
	this->key = key;
	this->vector = (mode!=ECB) ? iVector : 0;
	next_vector = 0;
	modus_operandi = mode;
	for (int i=0; i<16; i++) key_array[i]=0;

	//  code to create 16 keys

	static const int vshift[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
	// create first key
	uint64_t temp_key=0;
	unsigned long c=0,d=0;
	for (int bit=0; bit<28; bit++)
	{
		c |= (key & rol64(1, (64-pc1[bit]))) ? 1<<(31-bit) : 0;		// PC1 bits are 1 relative
		d |= (key & rol64(1, (64-pc1[bit+28]))) ? 1<<(31-bit):0;
	}
	key_array[0] = key;

								// begin rotate of c,d and store key
	for (int i=1; i<=16; i++)
	{
		temp_key = 0;
		c = rol28(c,vshift[i-1]);
		d = rol28(d,vshift[i-1]);
		uint64_t k = rol64(c, 32) & 0xFFFFFFF000000000;
		k |= rol64(d,4) & 0x0000000fffffff00;
		for (int j = 0; j<48; j++)
		{
			temp_key |= (k & rol64(1, (64-pc2[j])) ? rol64((uint64_t)1, (63-j)) : 0);
		}
		key_array[i] = temp_key;
	};
}

/*****************************************************************************
 * DES::f - provides the f function in DES
 *
 * Precondition: DES must be instantiated.
 *
 * Input: key - unsigned 64 bit key
 *          t - 32 bit half of 64 bits to
 *
 * Postcondition: the value to be XOR'd with the left half of the text
 *
 ******************************************************************************/
unsigned long f(uint64_t key, unsigned long r)
{
	unsigned long rvalue, temp;
	uint64_t	exp;					// 48 bit expansion for xor with key
	exp = 0;
	for (int index=0; index<48; index++)
	{
		exp |=(uint64_t) (r & (1<<(longBit0-ei[index]))) ? rol64(1, (64-index-1)):0;
	}
	exp = exp ^ key;		// xor with key
	rvalue = 0;
	for (int i = 0; i < 8; i++)
	{
		rvalue *=16;
		unsigned int col = rol64(exp, 6) & 0x3f;					// get high order 6 bits
		unsigned int row = col & 0x01;								// get low bit
		row += (col & 0x20) != 0 ? 0x02 : 0; 						// get high bit
		col = (col >> 1) & 0x0f;
		rvalue |= sbox[i][row*16+col];
		exp = exp << 6;
	}

			//      Final permutation
	temp = rvalue;
	rvalue  = 0;

	for (int bit = 0; bit < 32; bit++)
	{
		rvalue |= (temp & (1<<(longBit0-p32i[bit]))) ? (1 << (longBit0-bit-1)) : 0;	// subtract 1 because lonBit0 is 1 relative
	}


	return rvalue;
}

/*****************************************************************************
 * DES::process_block  - process 64 bit block.
 *
 * Precondition: des context
 *
 *
 * Postcondition: encrypted 64 bit block.
 *
 ******************************************************************************/

uint64_t DES::process_block(uint64_t x)
{
	uint64_t plain1, temp=0;
	unsigned long l[17],r[17], fresult;

	/**
	 * 			Initial Permutation
	 */
	plain1 = 0;
	for (int bit=1; bit<=64; bit++)		// DES bits are 1 relative with bit 1 at highest position
	{
		plain1 |= (x & rol64(1, 64-ip[bit-1])) ? rol64(1, 64-bit) : 0;
	}

	/**
	 * 		DES
	 */

	l[0] = (plain1 >> 32) & 0xffffffff;
	r[0] = (plain1 & 0x00000000ffffffff);

	for (int key = 1; key <= 15; key++)
	{
		l[key] = r[key-1];
		fresult = f(key_array[key],r[key-1]) & 0x0ffffffff;
		r[key] = l[key-1] ^ fresult;
	}
		// last iteration don't swap before xor
	l[16] = r[15];
	r[16] = l[15] ^ f(key_array[16], r[15]);


	/**
	 * 			combine left and right followed by
	 * 			Inverse Permutation
	 */
	plain1 = rol64(r[16], 32)  &0xffffffff00000000;
	plain1 |=  (l[16] & 0xffffffff);
	temp = 0;							// Inverse Initial Permutation
	for (int bit=1; bit<=64; bit++)
	{
		temp |= (plain1 & rol64(1, 64-inv_ip[bit-1])) ? rol64(1, 64-bit) : 0;
	}
	return temp;
}
/*****************************************************************************
 * DES::process_text - process string
 *
 * Precondition: DES structures instantiated.
 *
 * This module does all the work.  It assumes that decrypt switches the key array.
 * The input string is padded to a multiple of 64 bits.  64 bit blocks are then
 * extracted and passed to process_block.
 *
 * Input: String to be (de/en)crypted
 * Output: string containing (en/de)cryption
 *
 * Postcondition: string containing (en/de)crypted text.
 *
 ******************************************************************************/

std::string DES::process_text(string plaintext)
{
	uint64_t plain1, temp=0;
	int length = plaintext.length();
	byte x;
	string ciphertext="", padtext=plaintext;
	assert(direction==ENCRYPT || direction==DECRYPT);


	if (length % 8 != 0)	// pad plaintext with X
	{
		for (int i = (length % 8); i < 8; i++) padtext += "X"; //"X";
	}
	length = padtext.length();
	for (int i = 0; i < length;)
	{
		plain1 = 0;							// move one byte at a time

// convert first 8 characters to unsigned 64 bit integer (long long)  it looks ugly, but it works

		// not my favorite way of moving bytes, but it works
		for (int k = 0; k<8;k++)
		{
			plain1 *= (uint64_t)256;
			plain1 |= (int64_t)padtext[i++] & 0xff;
		}

		if (modus_operandi == CBC)
		{
			if (direction == ENCRYPT)
			{
				// CBC XOR plaintext with IV
				temp = plain1 ^ vector;
				plain1 = temp;
			} else
			{
				next_vector = plain1;
			}
		}

		temp = process_block(plain1);

		if (modus_operandi == CBC)
		{
			if (direction == DECRYPT)
	 	 	{				// CBC XOR plaintext with IV
				temp = temp ^ vector;
				vector = next_vector;
	 	 	} else
	 	 	{
	 	 		vector = temp;
	 	 	}
		}

		for (int k=0; k < 8; k++)
		{
			temp = rol64(temp, 8);
			x = temp % 256;
			ciphertext += char(x);
		}
	}
    return ciphertext;
}
/*****************************************************************************
 * DES::encrypt - encrypt input string
 *
 * Precondition: des encryption structure instantiated.
 *
 * Input: plaintext String to be encrypted
 *
 * Output: ciphertext encrypted string.
 *
 * Postcondition: the DES structure is modified to enforce encryption only.
 *                subsequent use of the structure for decryption will generate
 *                an error.
 *
 ******************************************************************************/
std::string DES::encrypt(string plaintext)
{
	string ciphertext;
	assert(direction==ENCRYPT || direction==FIRST);
	direction=ENCRYPT;
	ciphertext = process_text(plaintext);
	return ciphertext;
}

/*****************************************************************************
 * DES::decrypt - decrypt input string
 *
 * Precondition: des encryption structure instantiated.
 *
 * Input: ciphertext String to be encrypted
 *
 * Output: plaintext encrypted string.
 *
 * Postcondition: the DES structure is modified to enforce decryption only.
 *                subsequent use of the structure for encryption will generate
 *                an error.
 *
 ******************************************************************************/

std::string DES::decrypt(string ciphertext)
{
	assert(direction==DECRYPT || direction==FIRST);

	if (direction == FIRST)			// only swap keys first time in this context
	{
		for (int i = 1; i < 9; i++)
		{
			uint64_t swap = key_array[17-i];
			key_array[17-i] = key_array[i];
			key_array[i] = swap;
		}
	}

	direction = DECRYPT;
	string plaintext = process_text(ciphertext);
	return plaintext;
}

/*****************************************************************************
 * DES::~DES - destructor for DES data structure
 *
 * Precondition: instantiated DES structure
 *
 *
 * Postcondition: a DES structure is cleared and deallocated.
 *
 ******************************************************************************/
DES::~DES()
{
	// zero all memory before dispose
	key=0;
	vector=0;	
	next_vector=0;
	// overwrite key array with values to prevent accidental release of keys
	for (int i=0; i<16; i++) key_array[i]=0xffffffffffffffff;
	for (int i=0; i<16; i++) key_array[i]=0xaaaaaaaaaaaaaaaa;
	for (int i=0; i<16; i++) key_array[i]=0x5555555555555555;
	for (int i=0; i<16; i++) key_array[i]=0x0000000000000000;
	direction=FIRST;
};
