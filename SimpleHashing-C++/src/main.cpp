#include <iostream>

class Table
{
    private:
        int hash;
        int magic;
        int p;
        int base;
        int i_base;

    private:
        Table(int b, int prime)
        {
            hash = 0;
            magic = 1;
            p = prime;
            base = b;
            i_base = (p + 1) / base;
        }

        void append(int new_char)
        {
            hash = (hash * base + new_char) % p;
            magic = (magic * base) % p;
        }

        void skip(int old_char)
        {
            hash = (hash - old_char * magic + p * base) % p;
            magic = magic / i_base % p;
        }

};


int main()
{
    std::cout << -3 % 23 << std::endl;

    std::cin.get();
}
