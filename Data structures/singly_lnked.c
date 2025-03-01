#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node N;

N *insert(N*,int);
N *in_pos(N*,int,int);
N *in_del(N*,int);
void display(N*);

int main()
{
    int num,choice,key,position;
    N *start = NULL;

    while(1)
    {
        printf("\n1. INERST FRONT");
        printf("\n2. INERST IN POSITION");
        printf("\n3. DELETE BY VALUE");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the value:");
            scanf("%d",&num);
            start = insert(start,num);
            break;

            case 2:
            printf("\nEnter the value:");
            scanf("%d",&num);
            printf("\nEnter the position:");
            scanf("%d",&position);
            start = in_pos(start,num,position);
            break;

            case 3:
            printf("\nEnter the key to be deleted");
            scanf("%d",&key);
            start = in_del(start,key);
            break;

            case 4:
            display(start);
            break;

            case 5:
            printf("Exited...");
            exit(0);

            default :
            printf("\nyou have enter the wrong choice. Enter the youe choice again\n");
            break;
        }       
    }
    return 0;
}

N* insert(N*start,int n)
{
    N *new_node;
    new_node = (N*)malloc(sizeof(struct node));
    new_node -> data = n;
    new_node -> next = start;
    start = new_node;
    return start;
}

N* in_pos(N* start,int n,int p)
{
    N *new_node,*temp,*ptr;
    int count;
    new_node = (N*)malloc(sizeof(struct node));
    new_node -> data = n;
    if((start==NULL)&&(p==1))
    {
        new_node -> next = NULL;
        start = new_node;
    }
    else if((start == NULL) && (p>1))
    {
        printf("invalid position");
    }
    else
    {
        count = 1;
        ptr = start;
        while((ptr!=NULL) && (count!=p))
        {
            temp=ptr;
            ptr=ptr->next;
            count++;
        }
        if(ptr==NULL)
        {
            printf("Invalid\n");
        }
        else
        {
        new_node->next=ptr;
        temp -> next = new_node;
        }
    }
    return start;
}

N* in_del(N* start,int k)
{
    N *temp,*ptr;
    if(start == NULL)
    {
        printf("No node present\n");
    } 
    else if(start->data==k)
    {
        printf("Item Deleted:%d\n",start->data);
        ptr=start;
        start=start->next;
        free(ptr);
    }
    else
    {
        ptr = start;
        while((ptr!=NULL)&& (ptr->data!=k))
        {
            temp=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL)
        {
            printf("invalid\n");
        }
        else
        {
            temp ->next = ptr->next;
            printf("Item Deleted:%d",ptr->data);
            free(ptr);
        }
    }
    return start;
}

void display(N* start)
{
    N* ptr;
    if(start==NULL)
    {
        printf("the list is empty");
    }
    else
    {
        ptr = start;
        printf("the list data is");
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
