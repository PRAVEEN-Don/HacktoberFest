#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int data) {
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

// Function to search for a value in the BST
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int data) {
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
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function for in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to demonstrate the BST operations
int main() {
    Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // In-order traversal of the BST
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the BST
    int searchValue = 40;
    Node* foundNode = search(root, searchValue);
    if (foundNode) {
        printf("Value %d found in the BST.\n", foundNode->data);
    } else {
        printf("Value %d not found in the BST.\n", searchValue);
    }

    // Delete a node from the BST
    printf("Deleting 20...\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    printf("Deleting 30...\n");
    root = deleteNode(root, 30);
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    printf("Deleting 50...\n");
    root = deleteNode(root, 50);
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
