#include "efficient_sort.h"

#include <stdlib.h> 
#include <string.h> 


void merge(void* arr, void* temp, int left, int right, int mid,
            size_t elem_size, int (*cmp)(const void*, const void*),
            long *comparsions, long *swaps){
    int i = left;
    int j = mid + 1;
    int t = left;

    while (i <= mid && j <= right){
        if (comparsions)
            (*comparsions)++;

        if (cmp(get_ptr(arr, i, elem_size), get_ptr(arr, j, elem_size)) <= 0){
            memcpy(get_ptr(temp, t, elem_size), get_ptr(arr, i, elem_size), elem_size);
            i++;
            t++;
        }

        else {  
            memcpy(get_ptr(temp, t, elem_size), get_ptr(arr, j, elem_size), elem_size);
            j++;
            t++;
        }
    }

    while (i <= mid){
        memcpy(get_ptr(temp, t, elem_size), get_ptr(arr, i, elem_size), elem_size);
            i++;
            t++;
    }

    while (j <= right){
        memcpy(get_ptr(temp, t, elem_size), get_ptr(arr, j, elem_size), elem_size);
        j++;
        t++;
    }

    for (i = left; i <= right; i++){
        memcpy(get_ptr(arr, i, elem_size), get_ptr(temp, i, elem_size), elem_size);

        if (swaps)
            (*swaps)++;
    }   
}


void merge_sort_rec(void* arr, void* temp, int left, int right,
            size_t elem_size, int (*cmp)(const void*, const void*),
            long *comparisons, long *swaps){
    if (left >= right)
        return;
    
    int mid = left + (right - left) / 2;

    merge_sort_rec(arr, temp, left, mid, elem_size, cmp, comparisons, swaps);

    merge_sort_rec(arr, temp, mid + 1, right, elem_size, cmp, comparisons, swaps);

    merge(arr, temp, left, right, mid, elem_size, cmp, comparisons, swaps);       
}


void merge_sort(void *arr, int n, size_t elem_size,
                int (*cmp)(const void*, const void*),
                long *comparisons, long *swaps) {
    if (n <=1)
        return;

    void* temp = malloc(n * elem_size);
    if (!temp)
        return;
    
    merge_sort_rec(arr, temp, 0, n-1, elem_size, cmp, comparisons, swaps);

    free(temp);
}
