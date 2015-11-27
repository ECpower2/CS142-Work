#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

template <typename T>
inline T total(initializer_list<T> init_list) {
    T sum = 0;
    for (T n : init_list)
        sum = sum + n;

    return sum;
    }

int main() {
    initializer_list<int> int_ls1 = {1,2,3,4,5};
    int total_int_ls1 = total(int_ls1);
    cout << "Sum of first int list: " << total_int_ls1 << endl;

    initializer_list<int> int_ls2 = {};
    int total_int_ls2 = total(int_ls2);
    cout << "Sum of first int_list: " << total_int_ls2 << endl;

    return 0;
    }
