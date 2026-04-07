#include "efficient_sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp_int(const void* a, const void* b){
    int val_a = *(const int*)a;
    int val_b = *(const int*)b;

    if (val_a > val_b)
        return 1;
    
    if (val_b > val_a)
        return -1;
    return 0;
}

int print_arr(int* arr, int n){
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    
    printf("\n");
}


int main(){
    int n;

    printf("Enter the number of elements in the array:\n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Incorrect size entry\n");
        return 1;
    }

    int* arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }

    printf("Enter %d numbers separated by spaces:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Select algorithm sort\n");
    printf("1. Quick Sort (Lomuto)\n");
    printf("2. Quick Sort (Hoar)\n");
    printf("3. Merge Sort\n");
    printf("4. Heap Sort\n");
    printf("5. Cancel\n");

    int choice;
    scanf("%d", &choice);

    long comparisons = 0; long swaps = 0;

    switch (choice) {
        case 1:
            printf("\nRunning Quick Sort (Lomuto)...\n");
            quick_sort_lomuto(arr, n, sizeof(int), cmp_int, &comparisons, &swaps);
            break;

        case 2:
            printf("\nRunning Quick Sort (Hoar)...\n");
            quick_sort_hoar(arr, n, sizeof(int), cmp_int, &comparisons, &swaps);
            break;

        case 3:
            printf("\nRunning Merge Sort...\n");
            merge_sort(arr, n, sizeof(int), cmp_int, &comparisons, &swaps);
            break;

        case 4:
            printf("\nRunning Heap Sort...\n");
            heap_sort(arr, n, sizeof(int), cmp_int, &comparisons, &swaps);
            break;

        case 5:
            printf("\nCanceled. Exiting...\n");
            free(arr); 
            return 0;

        default:
            printf("\nInvalid choice! Exiting...\n");
            free(arr);
            return 1;
    }

    printf("Result:\n");
    print_arr(arr, n);
    printf("Comparisons: %ld, Swaps: %ld\n", comparisons, swaps);

    free(arr);
    return 0;


}