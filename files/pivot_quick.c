#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int random_pivot(int arr[], int left, int right) {
    srand(time(NULL));
    int random_index = rand() % (right - left + 1) + left;
    return random_index;
}


int partition(int arr[], int left, int right) {
    int pivot_index = random_pivot(arr, left, right);
    int pivot_value = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]);
    int store_index = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivot_value) {
            swap(&arr[i], &arr[store_index]);
            store_index++;
        }
    }
    swap(&arr[store_index], &arr[right]);
    return store_index;
}


void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quicksort(arr, left, pivot_index - 1);
        quicksort(arr, pivot_index + 1, right);
    }
}


int main() {
    int x;
    scanf("%d", &x);
    int arr[x];
    for(int i=0;i<x;i++){
        scanf("%d",&arr[i]);
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
