#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} N;

N *root;
N *insertnode(N *, int);
int total(N *);

int main() {
    int option, val;
    N *root = NULL;

    while (1) {
        printf("1. INSERT ELEMENT\n");
        printf("2. TO COUNT THE LEAF NODES\n");
        printf("3. STOP\n");
        printf("Enter the option\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value\n");
                scanf("%d", &val);
                root = insertnode(root, val);
                break;

            case 2:
                printf("Leaf nodes are: ");
                int leaf_count = total(root);
                printf("\nTotal leaf nodes: %d\n", leaf_count);
                break;

            case 3:
                printf("EXITED\n");
                exit(0);

            default:
                printf("Incorrect option. Try again..\n");
                break;
        }
    }
    return 0;
}

N *insertnode(N *root, int val) {
    N *new_node, *temp, *ptr;

    new_node = (N *)malloc(sizeof(N));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
        root = new_node;
    } else {
        ptr = root;
        while (ptr != NULL) {
            temp = ptr;
            if (val < ptr->data) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }
        if (val < temp->data) {
            temp->left = new_node;
        } else {
            temp->right = new_node;
        }
    }
    return root;
}

int total(N *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return 1;
    } else {
        return total(root->left) + total(root->right);
    }
}
