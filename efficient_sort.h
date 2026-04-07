#ifndef SORT_ALGORYTHMS
#define SORT_ALGORYTHMS

#include <stddef.h>

void* get_ptr(void* arr, int index, size_t elem_size);
void swap(void* a, void* b, size_t elem_size, long *swaps);

//Merge sort
void merge(void* arr, void* temp, int left, int right, int mid,
           size_t elem_size, int (*cmp)(const void*, const void*),
           long *comparisons, long *swaps);
void merge_sort_rec(void* arr, void* temp, int left, int right,
                    size_t elem_size, int (*cmp)(const void*, const void*),
                    long *comparisons, long *swaps);
void merge_sort(void *arr, int n, size_t elem_size,
                int (*cmp)(const void*, const void*),
                long *comparisons, long *swaps);

//Quick sort
int partition_lomuto(void *arr, int n, size_t elem_size,    
                     int (*cmp)(const void*, const void*), 
                     long *comparisons, long *swaps);
void quick_sort_lomuto(void* arr, int n, size_t elem_size,
                       int (*cmp)(const void*, const void*),
                       long *comparisons, long *swaps);

int partition_hoar(void *arr, int n, size_t elem_size, int pivot,
                   int (*cmp)(const void*, const void*), 
                   long *comparisons, long *swaps);
void quick_sort_hoar(void* arr, int n, size_t elem_size,
                     int (*cmp)(const void*, const void*),
                     long *comparisons, long *swaps);

//Heap sort
void sift_down(void* arr, int root, int n, size_t elem_size, 
               int (*cmp)(const void*, const void*), 
               long *comparisons, long *swaps);
void heap_sort(void* arr, int n, size_t elem_size,
                int (*cmp)(const void*, const void*),
                long *comparisons, long *swaps);

#endif
