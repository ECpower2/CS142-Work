#include <iostream>
#include "string.h"
using namespace std;

int main() {
    char test[5] = {'t','e','s','t'};
    String test_str(test);
    std::cout << "Test String: ";
    test_str.print(std::cout);
    std::cout << std::endl;

    //Test length method
    int str_length = test_str.length();
    cout << "Length of string: " << str_length << std::endl;

    //Test indexing operator
    cout << "First character in test string: " << test_str[0] << std::endl;

    //Test clear method
    cout << "Clearing string" << std::endl;
    test_str.clear_str();

    char hello[6] = {'h','e','l','l','o'};
    String hello_str(hello);

    char world[6] = {'w','o','r','l','d'};
    String world_str(world);



    }
