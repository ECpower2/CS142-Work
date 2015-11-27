#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class StartsWith {
    public:
        StartsWith(char c) : c(c) {}
        bool operator()(string str) { return c == str.at(0); }
    private:
        char c;
    };

int main() {
    string str = "yarn"; //Bahaha string jokes
    char c = 'c';
    char y = 'y';

    StartsWith c_check(c);
    cout << "Does string start with 'c'? ";
    if ( c_check(str) == 1)
        cout << "Yes " << endl;
    else
        cout << "No" << endl;

    StartsWith y_check(y);
    cout << "Does string start with 'y'? ";
    if ( y_check(str) == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    }
