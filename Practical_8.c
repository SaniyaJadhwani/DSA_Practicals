#include <stdio.h> 
#include <stdlib.h> 
// Define structure for a node in the circular doubly linked list 
struct Node { 
int data; 
struct Node* next; 
struct Node* prev; 
}; 
// Function to insert a node at the beginning of the circular doubly linked list 

void insertAtBeginning(struct Node** last, int value) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
if (*last == NULL) { 
// If the list is empty, create a single node circular doubly linked list 
newNode->next = newNode; 
newNode->prev = newNode; 
*last = newNode; 
} else { 
struct Node* first = (*last)->next; 
newNode->next = first; 
newNode->prev = *last; 
first->prev = newNode; 
(*last)->next = newNode; 
} 
printf("Inserted %d at the beginning.\n", value); 
} 
// Function to insert a node at the end of the circular doubly linked list 
void insertAtEnd(struct Node** last, int value) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
if (*last == NULL) { 
// If the list is empty, create a single node circular doubly linked list 
newNode->next = newNode; 
newNode->prev = newNode; 
*last = newNode; 
} else { 
struct Node* first = (*last)->next; 
newNode->next = first; 
newNode->prev = *last; 
(*last)->next = newNode; 
first->prev = newNode; 
*last = newNode; 

    } 
 
    printf("Inserted %d at the end.\n", value); 
} 
 
// Function to delete a node from the circular doubly linked list 
void deleteNode(struct Node** last, int value) { 
    if (*last == NULL) { 
        printf("List is empty.\n"); 
        return; 
    } 
 
    struct Node* current = (*last)->next; 
 
    // Traverse the list to find the node to delete 
    do { 
        if (current->data == value) { 
            if (current == *last && current->next == current) { 
                // If the list contains only one node 
                free(current); 
                *last = NULL; 
            } else { 
                struct Node* prevNode = current->prev; 
                struct Node* nextNode = current->next; 
 
                prevNode->next = nextNode; 
                nextNode->prev = prevNode; 
 
                if (current == *last) { 
                    *last = prevNode; // Update the last pointer if the last node is being deleted 
                } 
 
                free(current); 
            } 
 
            printf("Deleted %d from the list.\n", value); 
            return; 
        } 
 
current = current->next; 
} while (current != (*last)->next); 
printf("Node with value %d not found.\n", value); 
} 
// Function to display the circular doubly linked list 
void display(struct Node* last) { 
if (last == NULL) { 
printf("List is empty.\n"); 
return; 
} 
struct Node* temp = last->next; 
printf("Circular Doubly Linked List: "); 
do { 
printf("%d -> ", temp->data); 
temp = temp->next; 
} while (temp != last->next); 
printf("(Back to Start)\n"); 
} 
// Main function to test the circular doubly linked list implementation 
int main() { 
struct Node* last = NULL;  // Initialize an empty list 
// Insert elements at the beginning 
insertAtBeginning(&last, 10); 
insertAtBeginning(&last, 20); 
insertAtBeginning(&last, 30); 
// Display list after insertion at beginning 
printf("\nList after inserting at the beginning:\n"); 
display(last); 
// Insert elements at the end 
insertAtEnd(&last, 40); 
insertAtEnd(&last, 50); 

// Display list after insertion at end 
printf("\nList after inserting at the end:\n"); 
display(last); 
// Delete nodes 
deleteNode(&last, 20); 
deleteNode(&last, 50); 
// Display list after deletions 
printf("\nList after deleting nodes:\n"); 
display(last); 
return 0; 
}