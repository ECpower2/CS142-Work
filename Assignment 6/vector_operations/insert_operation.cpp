#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;

template <typename T>
void println(vector<T> & v) {
    for (const T & e : v) cout << e << ' ';
    cout << '\n';
    }

int main() {
    int int_list[] = {1,2,3,5};
    vector<int> int_vec(int_list,int_list+4);

    string str_list[] = {"a","e","i","o"};
    vector<string> str_vec(str_list,str_list+4);

    cout << "Original Integer Vector: ";
    println(int_vec);
    cout << "Original String Vector: ";
    println(str_vec);

    vector<int>::iterator int_itr = int_vec.begin()+3;
    int_vec.insert(int_itr,4);

    vector<string>::iterator str_itr = str_vec.end();
    str_vec.insert(str_itr,string("u"));

    cout << "Modified Integer Vector: ";
    println(int_vec);
    cout << "Modified String Vector: ";
    println(str_vec);

    return 0;
    }
