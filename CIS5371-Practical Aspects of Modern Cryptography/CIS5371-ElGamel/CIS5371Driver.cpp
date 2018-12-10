/*
 * ElGamalDriver.cpp
 *
 *  Created on: Sep 14, 2018
 *      Author: Christopher Foley / Bijayita Thapa
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <assert.h>
#include <sstream>
#include <fstream>
#include <cerrno>
#include "sys/stat.h"
#include "ElGamal.h"
#include "cryptopp/integer.h"

using namespace std;
static const CryptoPP::Integer CZERO = CryptoPP::Integer((long)0);

CryptoPP::Integer hexStringToInteger(std::string inString)
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

static void show_help(string pgm_name="CIS5371Driver")
{
	cout << "Usage: " << pgm_name << " -h |  -e | -d [-k key_length -K file_name] -f MESSAGE_FILE \n"
	     << "       -d  - decrypt MESSAGE_FILE, use of -d prohibits use of -e\n"
	     << "       -e  - encrypt MESSAGE_FILE, use of -e prohibits use of -d\n"
	     << "       -h  - display this message.  If use this must be the first parameter.\n"
    	 << "       -k key length, specified as a multiple of 2 greater than or equal to 128 bits, if omitted 128 bits is used\n"
		 << "       -K file_name  -file containing public key, generator and generated parameter. \".pub\" is appended for public key, "
		 << "          \".key\" is appended for private key. if file_name does not exist keys will be generated \n"
	     << "       -f MESSAGE_FILE fully qualified path of file to encrypt.\n"
		 << "          use of the MESSAGE_FILE will result in the output being directed to MESSAGE_FILE.out.\n"
		 << "          MESSAGE_FILE will be broken into n byte chunks where n is the minimum number of bytes needed to store the key\n"
		 << "          output file will be n byte chunks containing a generated key and cipher text separated by a semicolon (;)\n"<< endl;
}


int main(int argc, char *argv[])
{
	string::iterator it;			// create iterator for param parsing
	unsigned int key_length=0;
	CryptoPP::Integer public_key=CZERO, private_key=CZERO, prime=CZERO, generator=CZERO;
	string plaintext, ciphertext;
	state direction = FIRST;
	bool key_file, public_file, message_file;			// input from file output to a.out
	string key_filename, public_filename, message_filename;
	key_file = public_file = message_file = false;
	unsigned int message_size=0;
	struct stat stat_buf;

	bool parmerror = (argc < 2);
	if (!parmerror)
	{
		int index = 1;
		while (!parmerror && index <= argc-1)
		{
			string argument = argv[index++];
			string parameter;
			if (argument == "-h")
			{
				parmerror = true;
				direction = DECRYPTION;		// set it to avoid an error message about direction when help selected
			}
			else if (argument == "-d" && direction == FIRST)
			{
				direction = DECRYPTION;
			}
			else if (argument == "-e" && direction == FIRST)
			{
				direction = ENCRYPTION;
			}
			else if (argument == "-k" && (index+1)<argc)
			{
				parameter = argv[index++];
				key_length = stoi(parameter);
				if (((key_length & (key_length-1)) != 0) || key_length < 128)
				{
					cout << "Key Length must be a power of 2 and greater than 128\n"
						 << "(128, 256, 512, 1024, 2048\n";
					parmerror = true;
				}
			}
			else if (argument == "-K" && (index == argc-1))
			{
			// file to string
				if (key_filename == "")
				{
					//  read file into a string

					key_filename = string(argv[index])+".key";
					public_filename = string(argv[index])+".pub";
					bool keyExists, publicExists;
					{
						struct stat statbuff;
						keyExists = stat(key_filename.c_str(), &statbuff) == 0;
						publicExists = stat(public_filename.c_str(), &statbuff) == 0;
					}
					if (publicExists)
					{
						ifstream  keyfile (key_filename, ios::in);
						if (!keyfile)
						{
							cout << key_filename <<  " file open error: "
								 << strerror(errno) << std::endl;
							parmerror = true;
						}
						else
						{
							stringstream keyStream;
							keyStream << keyfile.rdbuf();
							string k1, k2, k3, d1, d2;
							keyStream >> k1 >> d1 >> k2 >> d2 >> k3;
							prime = hexStringToInteger(k1);
							generator =  hexStringToInteger(k2);
							public_key = hexStringToInteger(k3);
						}
					}
					if (keyExists)
					{
						ifstream  keyfile (public_filename, ios::in);
						if (!keyfile)
						{
							cout << key_filename <<  " file open error: "
								 << strerror(errno) << std::endl;
							parmerror = true;
						}
						else
						{
							stringstream keyStream;
							keyStream << keyfile.rdbuf();
							string k1;
							keyStream >> k1;
							private_key = hexStringToInteger(k1);
						}
					}
				}
			}
			else if (argument == "-f" && (index == argc-1))
			{
			// file to string
				if (plaintext == "")
				{
					//  read file into a string
					char inchar;

					message_filename = argv[index];
					if (!stat(argv[index++], &stat_buf))
					{
						cout << argv[index-1] << " File open error: \n";
						cout << strerror(errno);
						cout << endl;
						parmerror = true;
						return 1;
					}
					else
					{
						ifstream plainfile (message_filename, ios::in | ios::binary);
						plaintext = new char[stat_buf.st_size];
						message_size = stat_buf.st_size;
						while (!plainfile.eof())
						{
							plainfile.get(inchar); // do it one char at a time
							plaintext += inchar;
						}
						plainfile.close();
						message_file = true;
					}
				}
				else
					parmerror = true;
			}
			else
				parmerror = true;
		}
	}

	// if direction specified do encrypt/decrypt and output result
	parmerror |= direction == FIRST;

	if (parmerror)
	{
		show_help(argv[0]);
		return 1;
	}
	ElGamal elgamal = ElGamal(key_length, prime, generator, public_key, private_key);
	if (direction == ENCRYPTION)
	{
		ciphertext = elgamal.encrypt(plaintext);
	}
	else
	{
		plaintext = elgamal.decrypt(ciphertext);
	}

	string outfilename(message_filename);
	outfilename += ".out";
	ofstream cipherfile (outfilename, ios::out | ios::binary);
	cipherfile << ciphertext;
	cipherfile.close();
return 0;

}
