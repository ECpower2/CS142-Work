#include <iostream>
using std::cin;
using std::cout;
using std::ostream;

#include <algorithm>
using std::replace;
using std::max_element;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iterator>
using std::iterator;

void print_string_vector(vector<string> & v, ostream & out) {
    for (vector<string>::iterator itr = v.begin(); itr != v.end(); ++itr) {
        out << *itr << " ";
        }
    out << std::endl;
    }

void print_int_vector(vector<int> & v, ostream & out) {
    for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
        out << *itr << " ";
        }
    out << std::endl;
    }

void test_replace() {
    string str_elements[] = {"Aardvark","Buffalo","Capybara","Dingo","Echidna"};
    int int_elements[] = {1,1,2,3,5,8,13,21,34,55};

    vector<string> v1(str_elements,str_elements+5);
    vector<int> v2(int_elements,int_elements+10);

    cout << "Vector v1: ";
    print_string_vector(v1,cout);

    cout << "Vector v2: ";
    print_int_vector(v2,cout);

    string replace_str = "Buffalo";
    string replace_with = "Brumby";

    replace(v1.begin(),v1.end(),replace_str,replace_with);
    replace(v2.begin(),v2.end(),1,0);

    cout << "Vector v1 (with substitution): ";
    print_string_vector(v1,cout);

    cout << "Vector v2 (with substitution): ";
    print_int_vector(v2,cout);
    }

void test_max_element() {
    string str_elements[] = {"Antelope","Brontosaurus","Caiman","Dodo","Eel"};
    int int_elements[] = {3,1,4,1,5,9,2,6,5,3};

    vector<string> v1(str_elements,str_elements+5);
    vector<int> v2(int_elements,int_elements+10);

    vector<string>::iterator v1_itr = max_element(v1.begin(),v1.end());
    vector<int>::iterator v2_itr = max_element(v2.begin(),v2.end());

    cout << "Vector v1: ";
    print_string_vector(v1,cout);

    cout << "Vector v2: ";
    print_int_vector(v2,cout);

    cout << "Max Element in v1: " << *v1_itr << std::endl;
    cout << "Max Element in v2: " << *v2_itr << std::endl;
    }

int main() {
    test_replace();
    cout << std::endl;
    test_max_element();
    }
