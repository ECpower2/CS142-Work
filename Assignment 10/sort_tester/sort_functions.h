#ifndef SORT_FUNCTIONS_H_INCLUDED
#define SORT_FUNCTIONS_H_INCLUDED

#include "print_arr.h"
#include <algorithm>

void selection_sort(int arr[],int arr_length) {
    print_sort_arr(arr);
    if (arr_length > 0) {
        int index_max = 0;
        for (int ct = 0; ct < arr_length; ++ct) {
            if (arr[ct] > arr[index_max])
                index_max = ct;
            }
        std::swap(arr[index_max],arr[arr_length-1]);

        selection_sort(arr,arr_length-1);
        }
    }

void insertion_sort(int arr[],int arr_length) {
    if (arr_length > 0) {
        print_sort_arr(arr);

        insertion_sort(arr,arr_length-1);

        for (int ct = arr_length - 1; ct > 0; --ct) {
            if (arr[ct-1] > arr[ct]) {
                std::swap(arr[ct],arr[ct - 1]);
                }
            }
        print_sort_arr(arr);
        }
    }

void merge_(int arr[], int start, int middle, int stop) {
    int * merge_arr = new int[stop - start];

    int half1_ix,merge_ix = start;

    int half2_ix = middle;

    std::cout << "1\n";

    while (half1_ix < middle && half2_ix < stop) {
        if (arr[half1_ix] <= arr[half2_ix]) {
            merge_arr[merge_ix] = arr[half1_ix];
            ++half1_ix;
            }
        else {
            merge_arr[merge_ix] = arr[half2_ix];
            ++half2_ix;
            }
        ++merge_ix;
        }

    std::cout << "2\n";

    std::copy(arr + half1_ix,arr + middle,merge_arr + merge_ix);
    std::copy(arr + half2_ix,arr + stop,merge_arr + merge_ix);
    std::copy(merge_arr,merge_arr+(stop-start),arr+start);

//    while (half1_ix < middle) {
//        merge_arr[merge_ix] = arr[half1_ix];
//        ++half1_ix;
//        ++merge_ix;
//        }
//
//    while (half2_ix < stop) {
//        merge_arr[merge_ix] = arr[half2_ix];
//        ++half2_ix;
//        ++merge_ix;
//        }
//
//    for (int ct = start; ct < stop; ++ct)
//        arr[ct] = merge_arr[ct];

    delete [] merge_arr;
    }

void merge_sort(int arr[], int start, int stop) {
    if (start < stop) {
        int middle = (start + stop) / 2;

        print_sort_arr(arr);

        merge_sort(arr,start,middle);
        merge_sort(arr,middle+1,stop);

        std::inplace_merge(arr + start,arr + middle,arr + stop);
        //merge_(arr,start,middle,stop);
        }
    }

void quick_sort(int arr[], int start, int stop) {
    int i = start;
    int j = stop;

    int pivot_ix = (start+stop)/2;
    int pivot = arr[pivot_ix];

    print_sort_arr(arr);

    while (i <= j) {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;

        if (i <= j) {
            std::swap(arr[i],arr[j]);
            ++i;
            ++j;
            }
        }

    if (start < j)
        quick_sort(arr,start,j);
    if (i < stop)
        quick_sort(arr,j,stop);
    }


#endif // SORT_FUNCTIONS_H_INCLUDED
