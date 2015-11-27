#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

#include "Time.h"


int main() {
    cout << "Beginning Test Driver for Time Class...\n";
    Time t1(0,0);
    Time t2;

    cout << "Testing Input and Output Methods:\n";
    cout << "Stored Time: \n" << t1 << endl;

    cout << "Please enter a new time: \n";
    cin >> t2;

    cout << "Testing Subtraction Operator:\n";
    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;
    cout << "The difference between these two times is " << (t2-t1) << " hours.\n";

    cout << "Testing '=' Operator (Setting t = 12):\n";
    t1 = 12;
    cout << "The time is now " << t1;

    return 0;
    }
