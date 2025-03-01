#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} N;

void insertrear(int);
void deletefront();
void display();
N *front = NULL, *rear = NULL;

void main()
{
    int num, choice;
    while (1)
    {
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. STOP\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &num);
            insertrear(num);
            break;

        case 2:
            deletefront();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("EXITED..!\n");
            return;  // Exit the program gracefully

        default:
            printf("Incorrect choice. Try again..!\n");
            break;
        }
    }
}

void insertrear(int n)
{
    N *new_node;
    new_node = (N *)malloc(sizeof(N));  // Correct allocation of new node
    new_node->num = n;
    
    if (front == NULL && rear == NULL)
    {
        // Both front and rear are NULL, create the first node
        front = rear = new_node;
        new_node->next = front;  // Point to itself for circular linkage
    }
    else
    {
        // If the queue is not empty
        rear->next = new_node;
        new_node->next = front;
        rear = new_node;
    }
    return;
}

void deletefront()
{
    if (front == NULL) // Empty queue check
    {
        printf("Queue is empty\n");
        return;
    }
    N *ptr = front;
    if (front == rear)
    {
        // Only one node in the queue
        printf("Item deleted: %d\n", ptr->num);
        free(ptr);
        front = rear = NULL;
    }
    else
    {
        // Multiple nodes in the queue
        front = front->next;
        rear->next = front;
        printf("Item deleted: %d\n", ptr->num);
        free(ptr);
    }
}

void display()
{
    N *ptr = front;
    if (ptr == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue data:\n");
        do
        {
            printf("%d\n", ptr->num);
            ptr = ptr->next;
        } while (ptr != front);  // Stop when we come back to the front
    }
}
