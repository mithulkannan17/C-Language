#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} N;

N *root;

N* insert(N *, int);
void printpath(N* root, int path[], int pathlen);

int main() {
    int option, val, pathlen, path[100];
    root = NULL;
    while(1) {
        printf("1. INSERT ELEMENT\n");
        printf("2. PRINT PATH\n");
        printf("3. STOP\n");
        printf("Enter the option\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Enter the value\n");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printpath(root, path, 0);
                break;
            case 3:
                printf("EXITED..\n");
                exit(0);
                break;
            default:
                printf("Incorrect option. Try again\n");
                break;
        }
    }
    return 0;
}

N* insert(N *root, int val) {
    N *new_node, *temp, *ptr;
    
    // Allocate memory for new node
    new_node = (N*)malloc(sizeof(N));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if(root == NULL) {
        root = new_node;  // If the tree is empty, the new node becomes the root
    } else {
        ptr = root;
        while(ptr != NULL) {
            temp = ptr;
            if(val < ptr->data) {
                ptr = ptr->left;  // Move to the left subtree
            } else {
                ptr = ptr->right;  // Move to the right subtree
            }
        }
        // Insert the new node at the correct position
        if(val < temp->data) {
            temp->left = new_node;
        } else {
            temp->right = new_node;
        }
    }
    return root;
}

void printpath(N *root, int path[], int pathlen) {
    int i;
    if(root == NULL) return;  // Base case: if the node is NULL, do nothing

    // Add the current node's data to the path
    path[pathlen] = root->data;
    pathlen++;

    // If it's a leaf node, print the path
    if(root->left == NULL && root->right == NULL) {
        for(i = 0; i < pathlen; i++) {
            printf("%d ", path[i]);  // Print the path with spaces between numbers
        }
        printf("\n");
    } else {
        // Recurse for left and right children
        printpath(root->left, path, pathlen);
        printpath(root->right, path, pathlen);
    }
}
