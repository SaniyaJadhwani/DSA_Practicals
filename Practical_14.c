#include <stdio.h> 
#include <stdlib.h> 
 
void merge(int arr[], int left, int mid, int right) { 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 = right - mid; 
 
    int *L = (int *)malloc(n1 * sizeof(int)); 
    int *R = (int *)malloc(n2 * sizeof(int)); 
 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j]; 
 
    i = 0; 
    j = 0; 
    k = left; 
 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 

    } 
 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
 
    free(L); 
    free(R); 
} 
 
void mergeSort(int arr[], int left, int right) { 
    if (left < right) { 
        int mid = left + (right - left) / 2; 
 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
    } 
} 
 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; 
    int i = (low - 1); 
    for (int j = low; j < high; j++) { 
        if (arr[j] < pivot) { 
            i++; 
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
    } 
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp; 
    return i + 1; 
} 
 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

 
void printArray(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
 
int main() { 
    int choice, n; 
 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    int *arr = (int *)malloc(n * sizeof(int)); 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]); 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Merge Sort\n"); 
        printf("2. Quick Sort\n"); 
        printf("3. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Sorting using Merge Sort...\n"); 
                mergeSort(arr, 0, n - 1); 
                printf("Sorted array: "); 
                printArray(arr, n); 
                break; 
            case 2: 
                printf("Sorting using Quick Sort...\n"); 
                quickSort(arr, 0, n - 1); 
                printf("Sorted array: "); 
                printArray(arr, n); 
                break; 
            case 3: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 3); 

free(arr); 
return 0; 
}