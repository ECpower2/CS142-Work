#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;

template <typename T>
void read(ifstream & in, vector<T> & v) {
    T element;
    v.erase(v.begin(),v.end());

    while(in >> element) {
        v.insert(v.end(),element);
        }
    }

template <typename T>
void print(vector<T> & v) {
    for (const T & e : v) cout << e << ' ';
    }

int main() {
    ifstream file;
    file.open("test.txt");

    string str_list[] = {"invalid","content"};
    vector<string> str_vec(str_list,str_list+2);

    read(file,str_vec);

    cout << "Elements of vector stored from file: \n";
    print(str_vec);

    return 0;
    }
