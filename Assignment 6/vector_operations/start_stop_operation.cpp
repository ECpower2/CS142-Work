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
    int int_list[] = {1,2,3,4,5};
    vector<int> int_vec(int_list,int_list+5);

    string str_list[] = {"a","e","i","o","u"};
    vector<string> str_vec(str_list,str_list+5);

    cout << "Original Integer Vector: ";
    println(int_vec);
    cout << "Original String Vector: ";
    println(str_vec);

    vector<int>::iterator int_itr = int_vec.begin();
    vector<int> sub_int_vec(int_itr,int_itr+3);

    vector<string>::iterator str_itr = str_vec.begin();
    vector<string> sub_str_vec(str_itr+2,str_itr+5);

    cout << "Modified Integer Vector: ";
    println(sub_int_vec);
    cout << "Modified String Vector: ";
    println(sub_str_vec);

    return 0;
    }
