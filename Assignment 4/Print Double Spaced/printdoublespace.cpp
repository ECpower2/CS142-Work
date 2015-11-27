#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string.h>

void print_double_spaced(char * cs)
    {
    for (int countChar = 0; countChar < strlen(cs); countChar++ )
        {
        cout << cs[countChar];
        if (countChar < strlen(cs) - 1) cout << ' ';
        }
    }

int main()
    {
    print_double_spaced("Testing spacing function");

    return 0;
    }
