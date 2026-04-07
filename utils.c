#include "efficient_sort.h"

void* get_ptr(void* arr, int index, size_t elem_size){
    return (char*)arr + (index * elem_size);
}


void swap(void* a, void* b, size_t elem_size, long *swaps){
    char*ptr_a = (char*)a;
    char*ptr_b = (char*)b;

    for (size_t i = 0; i<elem_size; i++){
        char temp = ptr_a[i];
        ptr_a[i] = ptr_b[i];
        ptr_b[i] = temp;
    }

    if (swaps != NULL)
        (*swaps)++;
}