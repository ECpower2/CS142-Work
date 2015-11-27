#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

#include <string>
using std::string;

#include <iterator>
using std::iterator;

#include <vector>
using std::vector;

#include <initializer_list>
using std::initializer_list;

template <class InputIterator>
void print_if(InputIterator start, InputIterator stop, bool (*condition)(int), ostream & out) {
    for (InputIterator itr = start; itr < stop; ++itr) {
        if (condition(*itr)) out << *itr << endl;
        }
    }

inline bool is_positive(int x) {
    return x > 0;
    }

int main() {
    initializer_list<int> int_list = {0,-1,1,-2,2,-3,3};
    vector<int> int_vec(int_list);

    print_if(int_vec.begin(),int_vec.end(),is_positive,cout);

    }
