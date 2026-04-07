#include "efficient_sort.h"

#include <stddef.h>


void sift_down(void* arr, int root, int n, size_t elem_size, 
               int (*cmp)(const void*, const void*), 
               long *comparisons, long *swaps) {
    int parent = root;

    while (parent * 2 + 1 < n){
        int left = parent * 2 + 1;
        int right = parent * 2 + 2;
        int big_child = left;

        if (right < n){
            if (comparisons != NULL) 
                (*comparisons)++;
            if (cmp(get_ptr(arr, right, elem_size), get_ptr(arr, left, elem_size)) > 0)
                big_child = right;
        }

        if (comparisons != NULL) 
            (*comparisons)++;
        if (cmp(get_ptr(arr, big_child, elem_size), get_ptr(arr, parent, elem_size)) > 0){
            swap(get_ptr(arr, parent, elem_size), get_ptr(arr, big_child, elem_size), elem_size, swaps);
            parent = big_child;
        }

        else
            break;
    }
}


void heap_sort(void* arr, int n, size_t elem_size,
                int (*cmp)(const void*, const void*),
                long *comparisons, long *swaps){
    for (int i = n/2 - 1; i >= 0; i--){
        sift_down(arr, i, n, elem_size, cmp, comparisons, swaps);
    }

    for (int i = n - 1; i > 0; i--){
        swap(get_ptr(arr, 0, elem_size), get_ptr(arr, i, elem_size), elem_size, swaps);
        sift_down(arr, 0, i, elem_size, cmp, comparisons, swaps);
    }
}