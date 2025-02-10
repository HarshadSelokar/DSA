#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Binary Search Tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;  // Return the unchanged root pointer
}

// Function to search for a value in the BST
Node* search(Node* root, int key) {
    // Base cases: root is null or key is present at the root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than the root's data, search in the right subtree
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than the root's data, search in the left subtree
    return search(root->left, key);
}

// In-order traversal of the BST (left, root, right)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);     // Visit root
        inorderTraversal(root->right); // Traverse right subtree
    }
}

// Find the node with the minimum value in a given subtree
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in the BST
Node* delete(Node* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        // If the key is the same as root's data, this is the node to be deleted

        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has one child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        else {
            // Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

// Driver program to test the functions
int main() {
    Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform in-order traversal
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node in the BST
    int searchValue = 40;
    Node* result = search(root, searchValue);
    if (result != NULL) {
        printf("Node %d found in the BST.\n", searchValue);
    } else {
        printf("Node %d not found in the BST.\n", searchValue);
    }

    // Delete a node from the BST
    printf("Deleting node 20...\n");
    root = delete(root, 20);

    // Perform in-order traversal after deletion
    printf("In-order traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}