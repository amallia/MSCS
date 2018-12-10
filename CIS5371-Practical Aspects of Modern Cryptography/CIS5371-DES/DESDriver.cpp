/*
 * des.h
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
#include <stdint.h>
#include <malloc.h>
#include <sstream>
#include <fstream>
#include <cerrno>
#include "des.h"

using namespace std;

static string strToHex16(string inString)
{
	static const char *hexValues = "0123456789ABCDEF";
	string outstring;
	for (int i = 0; i < inString.length(); i++)
	{	byte hi,low;
		if ((i % 8 == 0) & (i > 0)) outstring += " ";
		hi = low = char(inString[i]);
		hi = (hi >> 4) & 0x0f;
		low &= 0x0f;
		outstring += hexValues[hi];
		outstring += hexValues[low];
	}
	return outstring;
}
static void show_help(string pgm_name="des")
{
	cout << "Usage: " << pgm_name << " -h |  -e | -d [-k KEY -iv INITIAL VECTOR [MESSAGE | - f MESSAGE_FILE ]]\n"
	     << "       -d  - decrypt MESSAGE or MESSAGE_FILE, use of -d prohibits use of -e\n"
	     << "       -e  - encrypt MESSAGE or MESSAGE_FILE, use of -e prohibits use of -d\n"
	     << "       -h  - display this message.  If use this must be the first parameter.\n"
    	 << "       -k KEY  - 64 bit key as characters, if omitted a weak key of 0x0000000000000000 will be used\n"
    	 << "       -iv INTIALIZATION_VECTOR - if omitted a weak vector of 0x0000000000000000 will be used\n"
    	 << "       MESSAGE  - message to encrypt must be last\n"
		 << "       -m ECB | CBC - mode of operation only one may be selected (ECB is default if none specified)\n"
	     << "       -f MESSAGE_FILE fully qualified path of file to encrypt.\n"
		 << "          use of the MESSAGE_FILE will result in the output being directed to MESSAGE_FILE.out" << endl;
}


int main(int argc, char *argv[])
{
	string::iterator it;			// create iterator for param parsing
	uint64_t key=0x0000000000000000, ini_vector=0x0000000000000000;
	string plaintext="", ciphertext="";
	des_state direction= FIRST;
	des_mode mode = ECB;
	bool use_file = false;			// input from file output to a.out
	char *filename;
	// validate ip tables
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
				direction = DECRYPT;		// set it to avoid an error message about direction when help selected
			}
			else if (argument == "-d" && direction == FIRST)
			{
				direction = DECRYPT;
			}
			else if (argument == "-e" && direction == FIRST)
			{
				direction = ENCRYPT;
			}
			else if (argument == "-k" && (index+1)<argc)
			{
				parameter = argv[index++];
				key = stoull(parameter, 0, 16);
			}
			else if (argument == "-iv" && (index+1)< argc)
			{
				parameter = argv[index++];
				ini_vector = stoull(parameter, 0, 16);
			}
			else if (argument == "-m" && (index+1) < argc)
			{
				parameter = argv[index++];
				if (parameter == "ECB")
					mode = ECB;
				else if (parameter == "CBC")
					mode = CBC;
				else
					parmerror = true;

			}
			else if (argument == "-f" && (index == argc-1))

			{
			// file to string
				if (plaintext == "")
				{
					//  read file into a string
					char inchar;
					filename = argv[index];
					ifstream plainfile (argv[index++], ios::in | ios::binary);
					if (!plainfile)
					{
						cout << argv[index-1] << " File open error: \n";
						cout << strerror(errno);
						cout << endl;
						parmerror = true;
						return 1;
					}
					else
					{
						while (!plainfile.eof())
						{
							plainfile.get(inchar); // do it one char at a time
							plaintext += inchar;
						}
						plainfile.close();
						use_file = true;
					}
				}
				else
					parmerror = true;
			}
			else if (index == argc)		// message to encrypt
			{
				if (plaintext == "")
					plaintext = argument;
				else
				{
					parmerror = true;
				}
			}
			else
				parmerror = true;
		}
	}

	// if direction specified do encrypt/decrypt and output result
	parmerror |= direction == FIRST;
	if ((ini_vector != 0) && (mode == ECB))
	{
		cerr << "Warning: Initialization Vector specified with ECB mode, initialization vector will be ignored." << endl;
		ini_vector = 0;
	}

	if (parmerror)
	{
		show_help(argv[0]);
		return 1;
	}
	DES des = DES(key, ini_vector, mode);
	if (direction == ENCRYPT)
	{
		ciphertext = des.encrypt(plaintext);
	}
	else
	{
		ciphertext = des.decrypt(plaintext);
	}

	if (use_file)					// input from file, output to a.out
	{
		// TODO: read file into a string
		char inchar;
		string outfilename(filename);
		outfilename += ".out";
		ofstream cipherfile (outfilename, ios::out | ios::binary);
		cipherfile << ciphertext;
		cipherfile.close();
	}
	else
	{
		string directionstr =  (direction == ENCRYPT) ? "Encryption " : "Decryption " ;
		cout << directionstr << "Input  (hex): " << strToHex16(plaintext) << endl;
	    cout << directionstr << "Output (hex): " << strToHex16(ciphertext) << endl;

		DES sed(key, ini_vector, mode);				// add some last minute verification
		if (direction == ENCRYPT)
		{
			assert(sed.decrypt(ciphertext)==plaintext);
		} else
		{
			assert(sed.encrypt(plaintext)==ciphertext);
		}
	}
return 0;

}
