#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Define structure for stack node 
struct Node { 
char data[100]; 
struct Node* next; 
}; 

struct Node* top = NULL; 
// Push operation for stack using linked list 
void push(char* change) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
strcpy(newNode->data, change); 
newNode->next = top; 
top = newNode; 
} 
// Pop operation for stack using linked list 
void pop() { 
if (top == NULL) { 
printf("Nothing to undo\n"); 
return; 
} 
struct Node* temp = top; 
printf("Undoing: %s\n", top->data); 
top = top->next; 
free(temp); 
} 
// Display stack 
void displayStack() { 
if (top == NULL) { 
printf("No changes to display\n"); 
return; 
} 
struct Node* temp = top; 
printf("Current changes in editor:\n"); 
while (temp != NULL) { 
printf("%s\n", temp->data); 
temp = temp->next; 
} 
} 
int main() { 
int choice; 
char change[100]; 

 
    while (1) { 
        printf("\n--- Text Editor (Undo functionality) ---\n"); 
        printf("1. Make a change\n"); 
        printf("2. Undo last change\n"); 
        printf("3. Display changes\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter the change: "); 
                scanf(" %[^\n]", change); 
                push(change); 
                break; 
            case 2: 
                pop(); 
                break; 
            case 3: 
                displayStack(); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
 
    return 0; 
} 