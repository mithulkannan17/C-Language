#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node N;

N* insert(N*,int);
N* reverse(N*);
void display();

int main()
{
    int num,choice;
    N* start = NULL;
    while(1)
    {
        printf("1. INSERT\n");
        printf("2. REVERSE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value\n");
            scanf("%d",&num);
            start = insert(start,num);
            break;

            case 2:
            start = reverse(start);
            break;

            case 3:
            display(start);
            break;

            case 4:
            printf("Exited..\n");
            exit(0);
            break;

            default:
            printf("Incorrect choice. try again..!");
        }
    }
    return 0;
}


N* insert(N* start,int n)
{
    N* new_node;
    new_node = (N*)malloc(sizeof(struct node));
    new_node -> data = n;
    new_node -> next = start;
    start = new_node;
    return start;
}

N* reverse(N *start)
{
    N *prev,*temp,*ptr;
    if(start==NULL)
    {
        printf("The list is empty\n");
        return start;
    }
    if(start->next==NULL)
    {
        printf("Only one node in the list\n");
        return start;
    }
    else
    {
        prev = NULL;
        ptr = start;
        while(ptr!=NULL)
        {
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        start = prev;
        return start;
    }
}

void display(N* start)
{
    N *ptr = start;
    if(start==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        start = ptr;
        printf("List data\n");
        while(ptr!=NULL)
        {
            printf("%d",ptr->data);
            ptr = ptr -> next;
        }
    }
}