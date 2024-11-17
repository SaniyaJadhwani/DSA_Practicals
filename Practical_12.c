#include <stdio.h> 
#define MAX_PRODUCTS 100 
// Function to perform binary search 
int binarySearch(int arr[], int size, int target) { 
int left = 0; 
int right = size - 1; 

    while (left <= right) { 
        int mid = left + (right - left) / 2; 
 
        // Check if the target is present at mid 
        if (arr[mid] == target) { 
            return mid;  // Target found 
        } 
        // If target is greater, ignore left half 
        else if (arr[mid] < target) { 
            left = mid + 1; 
        } 
        // If target is smaller, ignore right half 
        else { 
            right = mid - 1; 
        } 
    } 
 
    return -1;  // Target not found 
} 
 
int main() { 
    // Sample inventory of product IDs (sorted) 
    int inventory[MAX_PRODUCTS]; 
    int i; 
    int size; 
    int productID; 
 
    printf("\nEnter Number of products:"); 
    scanf("%d",&size); 
     
    for(i=0;i<size;i++) 
    { 
        printf("\nEnter Product Id:"); 
        scanf("%d",&inventory[i]); 
    } 
    printf("Enter the product ID to search for: "); 
    scanf("%d", &productID); 
 
    int result = binarySearch(inventory, size, productID); 
 
    if (result != -1) { 
        printf("Product ID %d found at index %d.\n", productID, result); 
    } else { 
        printf("Product ID %d not found in inventory.\n", productID); 
    } 
 

return 0; 
} 