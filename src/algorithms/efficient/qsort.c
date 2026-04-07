#include "efficient_sort.h"

#include <stdlib.h>  
#include <string.h>
#include <stddef.h>  


int partition_lomuto(void *arr, int n, size_t elem_size,    
              int (*cmp)(const void*, const void*), 
              long *comparisons, long *swaps){
    
    void* pivot = get_ptr(arr, n - 1, elem_size);
    int i = 0;

    for (int j = 0; j < n-1; j++){
        void* current = get_ptr(arr, j, elem_size);

        if (comparisons != NULL) 
            (*comparisons)++;
        
        if (cmp(current, pivot) < 0){
            void* elem_i = get_ptr(arr, i, elem_size);

            swap(elem_i, current, elem_size, swaps);
            i++;
        }
    }
    
    void* elem_i = get_ptr(arr, i, elem_size);
    swap(elem_i, pivot, elem_size, swaps);

    return i;
}


int partition_hoar(void *arr, int n, size_t elem_size, int pivot,
              int (*cmp)(const void*, const void*), 
              long *comparisons, long *swaps){

    void* pivot_ptr = get_ptr(arr, pivot, elem_size);
    char pivot_val[elem_size];
    memcpy(pivot_val, pivot_ptr, elem_size);

    int i = 0; int j = n - 1;

    while (1){

        //left 
        if (comparisons != NULL)
            (*comparisons)++;
        while(cmp(get_ptr(arr, i, elem_size), pivot_val) < 0){
            i++;
            if (comparisons != NULL)
                (*comparisons)++;
        }

        //right 
        if (comparisons != NULL)
            (*comparisons)++;
        while(cmp(get_ptr(arr, j, elem_size), pivot_val) > 0){
            j--;
            if (comparisons != NULL)
                (*comparisons)++;
        }

        //exit
        if (i >=j) 
            return j;

        swap(get_ptr(arr, i, elem_size), get_ptr(arr, j, elem_size), elem_size, swaps);

        i++; j--;
    }
}


void quick_sort_lomuto(void*arr, int n, size_t elem_size,
                int (*cmp)(const void*, const void*),
                long *comparisons, long *swaps){
    if (n <= 1) 
        return;

    int pivot_idx = partition_lomuto(arr, n, elem_size, cmp, comparisons, swaps);

    quick_sort_lomuto(arr, pivot_idx, elem_size,
                cmp, comparisons, swaps);

    void* right_start = get_ptr(arr, pivot_idx + 1, elem_size);
    quick_sort_lomuto(right_start, n - pivot_idx - 1, elem_size,
                cmp, comparisons, swaps);
}


void quick_sort_hoar(void*arr, int n, size_t elem_size,
                int (*cmp)(const void*, const void*),
                long *comparisons, long *swaps){

    if (n <= 1)
        return;
    
    int pivot_idx = partition_hoar(arr, n, elem_size, (n - 1) / 2, cmp, comparisons, swaps);

    quick_sort_hoar(arr, pivot_idx + 1, elem_size,
                    cmp, comparisons, swaps);
    
    void* right_start = get_ptr(arr, pivot_idx + 1, elem_size);
    quick_sort_hoar(right_start, n - (pivot_idx + 1), elem_size,
                    cmp, comparisons, swaps);               
}