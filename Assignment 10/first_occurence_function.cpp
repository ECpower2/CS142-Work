
#include <iostream>
#include <iterator>

template <typename T>
int first_occurence(T * arr,int start,int stop,T element) {
    if (arr[start] == element)
        return start;
    else
        if (start != stop)
            first_occurence(arr,start+1,stop,element);
        else
            return (-1);

    }

int main() {
    int int_arr[5] = {1,2,3,4,5};

    int result = first_occurence(int_arr,0,4,3);

    if (result < 0)
        std::cout << "Element not found\n";
    else
        std::cout << "Found element at index: " << result << std::endl;
    }
