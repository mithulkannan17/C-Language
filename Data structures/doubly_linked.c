#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *leftlink;
    int data;
    struct node *rlink;
};

typedef struct node N;

N* insertfront(N*,int);
N* insertleft(N*,int,int);
N* deletekey(N*,int);
void display(N*);

int main()
{
    int num,choice,position,key;
    N *start = NULL;
    while(1)
    {
        printf("1. INSERT AT FRONT\n");
        printf("2. INSERT AT LEFT OF NODE\n");
        printf("3. DELETE AT POSITION\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value\n");
            scanf("%d",&num);
            start = insertfront(start,num);
            break;

            case 2: 
            printf("Enter the value\n");
            scanf("%d",&num);
            printf("Enter the position\n");
            scanf("%d",&position);
            start = insertleft(start,num,position);
            break;

            case 3:
            printf("Enter the key\n");
            scanf("%d",&key);
            start = deletekey(start,key);
            break;

            case 4:
            display(start);
            break;

            case 5:
            printf("EXITED..!\n");
            exit(0);
            break;

            default:
            printf("Incorrect choice. Try again\n");
            break;
        }
    }
    return 0;
}

N* insertfront(N* start, int n)
{
    N* new_node;
    new_node = (N*)malloc(sizeof(struct node));
    new_node->data = n;
    new_node->rlink = NULL;
    new_node->leftlink = NULL;
    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        new_node->rlink = start;
        start->leftlink = new_node;
        start = new_node;
    }
    return start;
}

N* insertleft(N* start, int n, int p)
{
    N* new_node, *ptr, *temp;
    new_node = (N*)malloc(sizeof(struct node));  // Corrected "sizof" to "sizeof"
    new_node->data = n;
    
    if(start == NULL)
    {
        printf("The list is empty\n");
    } 
    else
    {
        ptr = start;
        while((ptr != NULL) && (ptr->data != p))
        {
            ptr = ptr->rlink;
        }
        if(ptr == NULL)
        {
            printf("Invalid position\n");
        }
        else
        {
            new_node->rlink = ptr;
            new_node->leftlink = ptr->leftlink;
            if(ptr->leftlink != NULL)
            {
                ptr->leftlink->rlink = new_node;
            }
            ptr->leftlink = new_node;
        }
    }
    return start;
}

N* deletekey(N* start, int k)
{
    N *temp, *ptr;
    if(start == NULL)
    {
        printf("The list is empty\n");
    }
    else if(start->data == k)
    {
        ptr = start;
        printf("Item deleted = %d\n", start->data);
        start = start->rlink;
        if(start != NULL)
        {
            start->leftlink = NULL;
        }
        free(ptr);
    }
    else
    {
        ptr = start;
        while((ptr != NULL) && (ptr->data != k))
        {
            temp = ptr;
            ptr = ptr->rlink;
        }
        if(ptr == NULL)
        {
            printf("Invalid key\n");
        }
        else 
        {
            temp->rlink = ptr->rlink;
            if(ptr->rlink != NULL)
            {
                ptr->rlink->leftlink = temp;
            }
            printf("Item deleted: %d\n", ptr->data);
            free(ptr);
        }
    }
    return start;
}

void display(N* start)
{
    N* ptr;
    if(start == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        ptr = start;
        printf("The list data is:\n");
        while(ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->rlink;
        }
    }
}
