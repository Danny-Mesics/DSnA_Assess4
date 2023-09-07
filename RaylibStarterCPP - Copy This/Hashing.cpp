// Hashing.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Hash.h"

namespace HashFunction {

    // implementation of a basic addition hash
    unsigned int badHash(const char* data, unsigned int length)
    {
        unsigned int hash = 0;

        for (unsigned int i = 0; i < length; ++i)
            hash += data[i];

        return hash;
    }

    unsigned int MyHash(const char* data, unsigned int length) 
    {
        //Using prime numbers seed all values

        unsigned int hash = 7;
        int evens = 2;
        int odds = 3;

        for (int i = 0; i < length; i++) {
            if (data[i] % 2 == 0) {
                evens += data[i];
            }
            else {
                odds += data[i];
            }
        }

        hash = ((evens * 11) - hash / (odds * 5) - (hash * 13)); 
        

        // Ensures hash will return a 5 digit int
        while (hash < 10000 || hash > 100000) {
            if (hash < 10000) {
                hash = 10000 + (hash / 2);
            }
            if (hash >= 100000) {
                hash = 100000 - (hash / 2);
            }
        }
        
        return hash;
    }
}