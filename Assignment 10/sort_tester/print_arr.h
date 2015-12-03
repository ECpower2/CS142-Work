#ifndef PRINT_ARR_H_INCLUDED
#define PRINT_ARR_H_INCLUDED

void print_sort_arr(int * arr) {
    for (int ix = 0; ix < 8; ++ix)
        std::cout << arr[ix] << " ";
    std::cout << std::endl;
    }

#endif // PRINT_ARR_H_INCLUDED
