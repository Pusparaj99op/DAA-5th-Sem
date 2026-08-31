// Aim: implement Quick Sort and evaluate its performance
#include <stdio.h>

int comparisons = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {35, 12, 89, 4, 67, 23, 50, 8};
    int n = 8;

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Total comparisons: %d\n", comparisons);
    return 0;
}
