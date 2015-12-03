#include <iostream>
#include <iterator>

#include "sort_functions.h"
#include "print_arr.h"

int main() {
    int test_arr[8] = {32,17,45,50,66,29,18,46};
    int select_sort_arr[8] = {32,17,45,50,66,29,18,46};
    int insert_sort_arr[8] = {32,17,45,50,66,29,18,46};
    int merge_sort_arr[8] = {32,17,45,50,66,29,18,46};
    int quick_sort_arr[8] = {32,17,45,50,66,29,18,46};

    std::cout << "Original Array: ";
    print_sort_arr(test_arr);

    std::cout << "SELECTION SORT\n";
    selection_sort(select_sort_arr,8);

    std::cout << "INSERTION SORT\n";
    insertion_sort(insert_sort_arr,8);

    std::cout << "MERGE SORT\n";
    merge_sort(merge_sort_arr,0,8);

    std::cout << "QUICK SORT\n";
    quick_sort(quick_sort_arr,0,8);

    return 0;
    }

