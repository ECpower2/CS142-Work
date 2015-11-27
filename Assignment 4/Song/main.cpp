
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;

#include "Song.h"

int main() {
    cout << "Please select a test driver to run (enter corresponding number):\n";
    cout << "1) Title/Artist Constructor Test Driver\n";
    cout << "2) Input Operator Test Driver\n";

    int user_choice;
    cin >> user_choice;

    if (user_choice == 1) {
        constructor_test_driver();
        }

    else if (user_choice == 2) {
       input_test_driver();
        }

    return 0;
    }
