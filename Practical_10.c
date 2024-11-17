#include <stdio.h> 
#include <stdlib.h> 
// Define the structure for a node in the AVL tree 
struct Node { 
int data; 
struct Node* left; 
struct Node* right; 
int height; 
}; 
// Function to get the height of a node 
int getHeight(struct Node* node) { 
return node ? node->height : 0; 
} 
// Function to get the maximum of two integers 

int max(int a, int b) { 
return (a > b) ? a : b; 
} 
// Function to create a new node 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
newNode->data = data; 
newNode->left = newNode->right = NULL; 
newNode->height = 1; // New node is initially added at leaf 
return newNode; 
} 
// Function to perform a right rotation 
struct Node* rightRotate(struct Node* y) { 
struct Node* x = y->left; 
struct Node* T2 = x->right; 
// Perform rotation 
x->right = y; 
y->left = T2; 
// Update heights 
y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
return x; 
} 
// Function to perform a left rotation 
struct Node* leftRotate(struct Node* x) { 
struct Node* y = x->right; 
struct Node* T2 = y->left; 

// Perform rotation 
y->left = x; 
x->right = T2; 
// Update heights 
x->height = max(getHeight(x->left), getHeight(x->right)) + 1; 
y->height = max(getHeight(y->left), getHeight(y->right)) + 1; 
return y; 
} 
// Function to get the balance factor of a node 
int getBalance(struct Node* node) { 
return node ? getHeight(node->left) - getHeight(node->right) : 0; 
} 
// Function to insert a node in the AVL tree 
struct Node* insert(struct Node* node, int data) { 
if (node == NULL) return createNode(data); 
if (data < node->data) 
node->left = insert(node->left, data); 
else if (data > node->data) 
node->right = insert(node->right, data); 
else // Duplicate keys not allowed 
return node; 
// Update height of this ancestor node 
node->height = 1 + max(getHeight(node->left), getHeight(node->right)); 
// Check balance factor and perform rotations if necessary 
int balance = getBalance(node); 
// Left Left Case 

if (balance > 1 && data < node->left->data) 
return rightRotate(node); 
// Right Right Case 
if (balance < -1 && data > node->right->data) 
return leftRotate(node); 
// Left Right Case 
if (balance > 1 && data > node->left->data) { 
node->left = leftRotate(node->left); 
return rightRotate(node); 
} 
// Right Left Case 
if (balance < -1 && data < node->right->data) { 
node->right = rightRotate(node->right); 
return leftRotate(node); 
} 
return node; // Return the (unchanged) node pointer 
} 
// Function for in-order traversal of the AVL tree 
void inorder(struct Node* root) { 
if (root != NULL) { 
inorder(root->left); 
printf("%d ", root->data); 
inorder(root->right); 
} 
} 
// Main function to test the AVL tree implementation 
int main() { 
struct Node* root = NULL; 
// Insert nodes into the AVL tree 
root = insert(root, 30); 

root = insert(root, 20); 
root = insert(root, 40); 
root = insert(root, 10); 
root = insert(root, 25); 
root = insert(root, 35); 
root = insert(root, 50); 
printf("Inorder traversal of the AVL tree: "); 
inorder(root); 
printf("\n"); 
return 0; 
} 