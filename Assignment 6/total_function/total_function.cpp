#include <vector>
using std::vector;

#include <iostream>
using std::cout;

int total(vector<int>::const_iterator v1, vector<int>::const_iterator v2) {
    int total_ele;

    for (total_ele = 0; v1 != v2; ++v1) {
        ++total_ele;
        }

    return total_ele;
    }

int main() {
    int int_list[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> int_vec(int_list,int_list+10);

    vector<int>::const_iterator start = int_vec.begin();
    vector<int>::const_iterator stop = int_vec.end();

    int total_int = total(start,stop);
    cout << "Total number of elements: " << total_int;

    return 0;
    }
