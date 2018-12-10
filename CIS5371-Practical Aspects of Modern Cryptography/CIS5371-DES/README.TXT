-- CONTRIBUTORS

* Christopher Foley (Florida Atlantic University) - cfoley3@fau.edu
* Bijayita Thapa (Florida Atlantic University)  - bthapa@my.fau.edu

~-- SUMMARY --

The CIS5371-DES project provides a module to encrypt / decrypt C++ strings using the DES standard 
and return a C++ string.  Electronic Codebook (ECB) and Cipher-Block Chaining (CBC) are supported.
A command line input is provided to convert input text to encrypted form.   A file name may be provided 
to the command line and output will be directed to a file.  A help option is provided.

A series of Eclipse generated and subsequently modified makefiles are provided for product development.

For a full description of the module, examination of the code is recommended.

To submit bug reports and feature suggestions, or to track changes:
  cfoley3@fau.edu


-- REQUIREMENTS --

Gnu Make, gcc


-- INSTALLATION –

* The following files are provided in this release package:
   - des.h – header file required for use of the des.cpp module
   - des.cpp – DES Algorithm Implementation for (de/en)cryption.
   - DESDriver.cpp – program to trigger DES functions, accepts commands as flags
                     and identifies text or files to encrypt.
   - README.TXT – this file



* it is recommended that the files be copied to a directory and make be used to build.

* WARNING:  Use of the -O option with the GCC compiler is discouraged.  Code Optimization 
with levels -O1, -O2, and -O3 have been observed to produce errors in Encryption.  No 
encryption errors have been observed with code optimization with -O0 (default or no optimization) 
or -Os (optimize for size) set during the build process.

* WARNING: Code assumes access to 64-bit long long int provided with C++ (2011).
.  
-- CONFIGURATION --

* Configuration is by the command line options.  The following syntax may be used:

Usage: DESDriver -h |  -e | -d [-k KEY -iv INITIAL VECTOR [MESSAGE | - f MESSAGE_FILE ]]
       -d  - decrypt MESSAGE or MESSAGE_FILE, use of -d prohibits use of -e
       -e  - encrypt MESSAGE or MESSAGE_FILE, use of -e prohibits use of -d
       -h  - display this message.  If use this must be the first parameter.
       -k KEY  - 64 bit key as characters, if omitted a weak key of 0x0000000000000000 will be used
       -iv INTIALIZATION_VECTOR - if omitted a weak vector of 0x0000000000000000 will be used
       MESSAGE  - message to encrypt must be last
       -m ECB | CBC - mode of operation only one may be selected (ECB is default if none specified)
       -f MESSAGE_FILE fully qualified path of file to encrypt.
          use of the MESSAGE_FILE will result in the output being directed to MESSAGE_FILE.out

-h, -e or -d is required.

If a key is not specified 0 is used.
The initialization vector of 0 is used for CBC mode. Initialization vector is ignored for ECB mode.

If a file is specified, the output will be to a file having the same name as the input with ".out" appended to the 
file name (e.g. message file of a.in will result in a file of a.in.out).

It is not possible to input hexadecimal characters directly as a parameter to DESDriver

-- CUSTOMIZATION --

* 
-- TROUBLESHOOTING --

* 

-- FAQ --

Q: How do I know it works.

A: Use the test key (0x0123456789ABCDEF) and sequence ("Now is the time for all ").  It will result in the following output: 

./DESDriver -e -k 0123456789abcdef "Now is the time for all "
Encryption Input  (hex): 4E6F772069732074 68652074696D6520 666F7220616C6C20
Encryption Output (hex): 3FA40E8A984D4815 6A271787AB8883F9 893D51EC4B563B53

Q: How can I input hexadecimal characters for decryption.

A: Input them to a file and decrypt the file.

Q: How do you know this works.

A: 1) See the first question, it is a known pattern.
   2) A command line sequence similar to the following was attempted.
       ./DESDriver -e -k 0123456789abcdef -f a.in
       ./DESDriver -d -k 0123456789abcdef -f a.in.out
       cp a.in b.in
       ./DESDriver -e -k 0123456789abcdef -m CBC b.in
       ./DESDriver -d -k 0123456789abcdef -m CBC b.in.ou
     diff a.in b.in  
     diff a.in a.in.out.out
     diff b.in b.in.out.out
     diff a.in.out b.in.out

The first diff (a.in, b.in) showed no differences.  The second and third showed differences only at the end of the file where padding occurred.  The last showed significant differences, as expected.

- CONTACT --

Current maintainers:
* Christopher Foley (Florida Atlantic University) - cfoley3@fau.edu
* Bijayita Thapa (Florida Atlantic University)  - bthapa@my.fau.edu
