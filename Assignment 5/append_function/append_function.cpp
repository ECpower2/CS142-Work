
#include <iostream>
using std::cin;
using std::cout;
using std::ostream;

#include <vector>
using std::vector;

#include <iterator>
using std::iterator;

void print_int_vector(vector<int> & v, ostream & out) {
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
        out << *itr << " ";
        }
    out << std::endl;
    }

vector<int> append(vector<int> v1, vector<int> v2) {
    for (vector<int>::iterator itr = v2.begin(); itr != v2.end(); ++itr) {
        v1.push_back(*itr);
        //print_int_vector(v1,cout);
        }

    return v1;
    }

int main() {
    int int_set1[] = {1,2,3,4,5};
    vector<int> v1(int_set1,int_set1+5);
    cout << "Vector 1: " << std::endl;
    print_int_vector(v1,cout);

    int int_set2[] ={6,7,8,9,0};
    vector<int> v2(int_set2,int_set2+5);
    cout << "Vector 2: " << std::endl;
    print_int_vector(v2,cout);

    v1 = append(v1,v2);

    cout << "Appended Vector: " << std::endl;
    print_int_vector(v1,cout);
    }
