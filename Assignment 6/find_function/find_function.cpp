#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;

#include <iterator>
using std::iterator;

template <class InputIterator,class T>
InputIterator find(InputIterator start,InputIterator stop, const T & e) {
    for (InputIterator location = start; location != stop; ++location) {
        if (*location == e) return location;
        }

    return stop;
    }

template <typename T>
void println(vector<T> & v) {
    for (const T & e : v) cout << e << ' ';
    cout << '\n';
    }

int main() {
    int int_list[] = {1,2,3,4,5};
    vector<int> int_vec(int_list,int_list+5);

    string str_list[] = {"coding","can","be","hard","sometimes"};
    vector<string> str_vec(str_list,str_list+5);

    cout << "Original Integer Vector: ";
    println(int_vec);
    cout << "Original String Vector: ";
    println(str_vec);

    vector<int>::iterator int_found = find(int_vec.begin(),int_vec.end(),3);

    vector<string>::iterator str_found = find(str_vec.begin(),str_vec.begin()+2,string("sometimes"));

    cout << *int_found << std::endl;
    cout << *str_found << std::endl;



    return 0;
    }
