#include <stdio.h> 
#include <stdlib.h> 
// Define the structure for a node in the circular singly linked list 
struct Node { 
int data; 

struct Node* next; 
}; 
// Function to insert a node at the beginning of the circular linked list 
void insertAtBeginning(struct Node** last, int value) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
if (*last == NULL) { 
// If the list is empty, create a single node circular linked list 
newNode->next = newNode; 
*last = newNode; 
} else { 
newNode->next = (*last)->next; 
(*last)->next = newNode; 
} 
} 
// Function to insert a node at the end of the circular linked list 
void insertAtEnd(struct Node** last, int value) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = value; 
if (*last == NULL) { 
// If the list is empty, create a single node circular linked list 
newNode->next = newNode; 
*last = newNode; 
} else { 
newNode->next = (*last)->next; 
(*last)->next = newNode; 
*last = newNode; 
} 
} 
// Function to delete a node from the circular linked list 
void deleteNode(struct Node** last, int value) { 
if (*last == NULL) { 
printf("List is empty.\n"); 
return; 
 
} 
struct Node *current = (*last)->next, *previous = *last; 
// If the list contains only one node 
if (current == *last && current->data == value) { 
free(current); 
*last = NULL; 
printf("Deleted %d from the list.\n", value); 
return; 
} 
// If the node to be deleted is the first node 
if (current->data == value) { 
previous->next = current->next; 
(*last)->next = current->next; 
free(current); 
printf("Deleted %d from the list.\n", value); 
return; 
} 
// Traverse the list to find the node to delete 
while (current != *last) { 
if (current->data == value) { 
previous->next = current->next; 
free(current); 
printf("Deleted %d from the list.\n", value); 
return; 
} 
previous = current; 
current = current->next; 
} 
// If the node to be deleted is the last node 
if (current->data == value) { 
previous->next = current->next; 
*last = previous; 
free(current); 
printf("Deleted %d from the list.\n", value); 

} else { 
printf("Node with value %d not found.\n", value); 
} 
} 
// Function to display the circular linked list 
void display(struct Node* last) { 
if (last == NULL) { 
printf("List is empty.\n"); 
return; 
} 
struct Node* temp = last->next; 
do { 
printf("%d -> ", temp->data); 
temp = temp->next; 
} while (temp != last->next); 
printf("(Back to Start)\n"); 
} 
// Main function to test the circular singly linked list implementation 
int main() { 
struct Node* last = NULL; 
// Insert elements at the beginning 
insertAtBeginning(&last, 10); 
insertAtBeginning(&last, 20); 
insertAtBeginning(&last, 30); 
printf("List after inserting at the beginning:\n"); 
display(last);  // Output: 30 -> 20 -> 10 -> (Back to Start) 
// Insert elements at the end 
insertAtEnd(&last, 40); 
insertAtEnd(&last, 50); 
printf("\nList after inserting at the end:\n"); 
display(last);  // Output: 30 -> 20 -> 10 -> 40 -> 50 -> (Back to Start) 

// Delete a node 
deleteNode(&last, 20); 
printf("\nList after deleting 20:\n"); 
display(last);  // Output: 30 -> 10 -> 40 -> 50 -> (Back to Start) 
// Delete another node 
deleteNode(&last, 50); 
printf("\nList after deleting 50:\n"); 
display(last);  // Output: 30 -> 10 -> 40 -> (Back to Start) 
return 0; 
}