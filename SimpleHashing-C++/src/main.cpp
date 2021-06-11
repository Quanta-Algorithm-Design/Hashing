//      ---------------------------------------------------------------------------
//      ===========================================================================
//      Title:          Simple Hashing
//      Author:         Alpha Leo
//      Description:    Use this hash table for string matching with high speed
//      ===========================================================================
//      To do: 
//              - Implement the Extended Euclidean Algorithm to find the modular inverse
//              - ...
//      ===========================================================================
//      ---------------------------------------------------------------------------

#include <iostream>

class Table
{
    /* Our hash table class: Requires:
     * hash: to store the hashed result,
     * magic: store an intermediate variable which it's calculation is difficult so we store it since it doesn't change a lot.
     * p: is our prime number for the hash function
     * base: is the base in which we represent our characters. e.g. 256 for ASCII
     * i_base: this is the Modualar inverse of base, with respect to p (our prime number)
     */

    private:
        int hash;
        int magic;
        int p;
        int base;
        int i_base;

    private:
        Table(int b, int prime)
        {
            // Initializer
            // At first nothing is stored so:
            hash = 0;
            magic = 1;
            p = prime;
            base = b;
            i_base = modular_inverse(b, p);
        }

        void append(int new_char)
        {
            hash = (hash * base + new_char) % p;        // Update hash for adding a new char in the end of the array
            magic = (magic * base) % p;                 // update magic -> we take the mod to make sure we are working with small numbers / It's mathematically safe
        }

        void skip(int old_char)
        {
            hash = (hash - old_char * magic + p * base) % p;        // Again to update the hash after removeing the char in index 0 of the array
            magic = magic / i_base % p;                             // Update magic again
        }

};


int main()
{

    std::cin.get();
}
