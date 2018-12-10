#include <iostream>
using std::cout;
using std::endl;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

int main (int, char **)
{
    Integer i;
    cout << "i: " << i << endl;

    Integer j("100000000000000000000000000000000");

    cout << "j: " << j ;
    j %= 1999;

    cout << " % 1999=" << j << endl;

    return 0;
}
