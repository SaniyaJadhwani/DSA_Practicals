#include <stdio.h> 
#include <stdlib.h> 
// Define structure for a node in the Binary Search Tree 
struct Node { 
int data; 
struct Node* left; 
struct Node* right; 
}; 
// Function to create a new node 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = data; 
newNode->left = NULL; 
newNode->right = NULL; 
return newNode; 
} 
// Function to insert a new node in the BST 
struct Node* insert(struct Node* root, int data) { 

if (root == NULL) { 
return createNode(data); 
} 
if (data < root->data) { 
root->left = insert(root->left, data); 
} else if (data > root->data) { 
root->right = insert(root->right, data); 
} 
return root; 
} 
// Function to find the minimum value node in the BST 
struct Node* findMin(struct Node* root) { 
while (root->left != NULL) { 
root = root->left; 
} 
return root; 
} 
// Function to delete a node from the BST 
struct Node* deleteNode(struct Node* root, int data) { 
if (root == NULL) { 
return root; 
} 
if (data < root->data) { 
root->left = deleteNode(root->left, data); 
} else if (data > root->data) { 
root->right = deleteNode(root->right, data); 
} else { 
// Node with one child or no child 
if (root->left == NULL) { 
struct Node* temp = root->right; 
free(root); 
return temp; 
} else if (root->right == NULL) { 
struct Node* temp = root->left; 

free(root); 
return temp; 
} 
// Node with two children: Get the inorder successor (smallest in the right 
subtree) 
struct Node* temp = findMin(root->right); 
root->data = temp->data; // Copy the inorder successor's value 
root->right = deleteNode(root->right, temp->data); // Delete the inorder 
successor 
} 
return root; 
} 
// Function for inorder traversal of the BST 
void inorder(struct Node* root) { 
if (root != NULL) { 
inorder(root->left); 
printf("%d ", root->data); 
inorder(root->right); 
} 
} 
// Function for preorder traversal of the BST 
void preorder(struct Node* root) { 
if (root != NULL) { 
printf("%d ", root->data); 
preorder(root->left); 
preorder(root->right); 
} 
} 
// Function for postorder traversal of the BST 
void postorder(struct Node* root) { 
if (root != NULL) { 
postorder(root->left); 
postorder(root->right); 
printf("%d ", root->data); 
} 

} 
// Main function to test the Binary Search Tree implementation 
int main() { 
struct Node* root = NULL; 
// Insert nodes into the BST 
root = insert(root, 50); 
root = insert(root, 30); 
root = insert(root, 20); 
root = insert(root, 40); 
root = insert(root, 70); 
root = insert(root, 60); 
root = insert(root, 80); 
// Print the BST in different traversals 
printf("Inorder traversal: "); 
inorder(root); 
printf("\n"); 
printf("Preorder traversal: "); 
preorder(root); 
printf("\n"); 
printf("Postorder traversal: "); 
postorder(root); 
printf("\n"); 
// Delete a node from the BST 
root = deleteNode(root, 20); 
printf("\nInorder traversal after deleting 20: "); 
inorder(root); 
printf("\n"); 
root = deleteNode(root, 30); 
printf("Inorder traversal after deleting 30: "); 
inorder(root); 
printf("\n"); 
 
root = deleteNode(root, 50); 
printf("Inorder traversal after deleting 50: "); 
inorder(root); 
printf("\n"); 
return 0; 
} 