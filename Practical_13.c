#include <stdio.h> 
#include <stdlib.h> 
void selectionSort(int arr[], int n) { 
for (int i = 0; i < n - 1; i++) { 
int minIndex = i; 
for (int j = i + 1; j < n; j++) { 
if (arr[j] < arr[minIndex]) { 
minIndex = j; 
} 
} 
// Swap the found minimum element with the first element 

        int temp = arr[minIndex]; 
        arr[minIndex] = arr[i]; 
        arr[i] = temp; 
    } 
} 
 
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j + 1] 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
        } 
    } 
} 
 
void insertionSort(int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j--; 
        } 
        arr[j + 1] = key; 
    } 
} 
 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
} 
 
int main() { 
    int choice, n; 
 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 

    int *arr = (int *)malloc(n * sizeof(int)); 
    printf("Enter the elements:\n"); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Selection Sort\n"); 
        printf("2. Bubble Sort\n"); 
        printf("3. Insertion Sort\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Sorting using Selection Sort...\n"); 
                selectionSort(arr, n); 
                printf("Sorted array: "); 
                printArray(arr, n); 
                break; 
            case 2: 
                printf("Sorting using Bubble Sort...\n"); 
                bubbleSort(arr, n); 
                printf("Sorted array: "); 
                printArray(arr, n); 
                break; 
            case 3: 
                printf("Sorting using Insertion Sort...\n"); 
                insertionSort(arr, n); 
                printf("Sorted array: "); 
                printArray(arr, n); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 4); 
 
    free(arr); 
    return 0; 
} 