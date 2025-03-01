#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node N;
N *root;
N *insertnode(N*,int);
void preorderTraversal(N*);
void inorderTraversal(N*);
void postorderTraversal(N*);
int main()
{
    int option, val;
    N *root=NULL;
    while(1)
    {
        printf("1. INSERT ELEMENT\n");
        printf("2. PREORDER TRAVERSAL\n");
        printf("3. INORDER TRAVERSAL\n");
        printf("4. POSTORDER TRAVERSAL\n");
        printf("5. STOP\n");
        printf("Enter your choice\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            printf("Enter the value\n");
            scanf("%d",&val);
            root = insertnode(root,val);
            break;

            case 2:
            preorderTraversal(root);
            break;

            case 3:
            inorderTraversal(root);
            break;

            case 4:
            postorderTraversal(root);
            break;

            case 5:
            printf("STOP..!");
            exit(0);
            break;

            default :
            printf("Incorrect option. Try again..!\n");
            break;
        }
    }
    return 0;
}

N *insertnode(N* root,int val)
{
    N* new_node, *ptr, *temp;
    new_node = (N*)malloc(sizeof(struct node));
    new_node -> data = val;
    new_node -> left = NULL;
    new_node -> right = NULL;
    if(root == NULL)
    {
        root = new_node;
    }
    else
    {
        ptr = root;
        while(ptr!=NULL)
        {
            temp=ptr;
            if(val<(ptr->data))
                 ptr = ptr -> left;
            else
                ptr = ptr -> right;
        }
        if(val<(temp->data))
            temp -> left = new_node;
        else
            temp -> right = new_node;
    }
    return root;
}

void preorderTraversal(N *root)
{  // root -> left -> right
    if(root!=NULL)
    {
        printf("%d\t",root->data); 
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(N *root)
{  // left -> root -> right
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(N *root)
{
    if(root!=NULL)
    {  // left -> right -> root
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t",root->data);
    }
}