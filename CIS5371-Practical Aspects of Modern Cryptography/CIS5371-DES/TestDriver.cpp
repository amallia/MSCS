/*
 * TestDriver.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: chris
 */
#include <iostream>
#include <string>
#include <cctype>
#include <assert.h>
#include <stdint.h>
#include <malloc.h>
#include <fstream>
#include "des.h"

using namespace std;

int main(int argc, char *argv[])
{
	string::iterator it;			// create iterator for param parsing
	uint64_t key=0x0000000000000000, ini_vector=0x0000000000000000;
	string plaintext="", ciphertext="";
   	// set test values
	uint64_t test_key = 0x0123456789ABCDEF;
	string   plaint01 = "Now is t";
	string   plaint02 = "he time ";
	string   plaint03 = "for all ";
	string         plaint="Now is the time for all ";
	const uint64_t checkv01 = 0x3FA40E8A984D4815;
	const uint64_t checkv02 = 0x6a271787ab8883f9;
	const uint64_t checkv03 = 0x893d51ec4b563b53;
	{
		uint64_t key=0x0000000000000000, iv=0x0000000000000000;
		// do stuff with weak key first for simplest tests
		DES weak = DES(key, iv);

		assert(plaint01 == weak.encrypt(plaint01)); 	// should be same since key is 0
		assert(plaint02 == weak.encrypt(plaint02));
		assert(plaint03 == weak.encrypt(plaint03));

		string s;
		assert(plaint01 == weak.decrypt(weak.encrypt(plaint01))); 	// should be same
		assert(plaint02 == weak.decrypt(weak.encrypt(plaint02)));
		assert(plaint03 == weak.decrypt(weak.encrypt(plaint03)));
	}

	/**
//do stuff with test keys
DES des=DES(test_key,0);
ciphertext = des.encrypt(&plaint01);
assert(ciphertext == checkv01);
ciphertext = des.encrypt(&plaint02);
ciphertext = des.encrypt(&plaint03);
assert(ciphertext == checkv03);


	 */
	return 0;

}



