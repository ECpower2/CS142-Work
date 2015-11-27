#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

template <typename T>
void print(initializer_list<T> ls, int limit) {
    int element_ct = 0;
    for (T n : ls) {
        if (element_ct < limit) cout << n << endl;
        ++element_ct;
        }
    }

int main() {
    initializer_list<int> fib_seq = {1,1,2,3,5,8,13,21,34,55};
    print(fib_seq, 5);

    cout << endl;

    initializer_list<string> hello_world = {"Hello","World"};
    print(hello_world,10);

    return 0;
    }
