#include<stdio.h>
#include<stdio.h>
#define max 5

int queue[max],front=-1,rear=-1;
void insert(int);
void delete();

int main()
{
    int choice,num;
    while(1)
    {
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT");
        printf("Enter the choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the value\n");
            scanf("%d",&num);
            insert(num);
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("EXITED...\n");
            exit(0);
            break;

            default:
            printf("Incorrect choice.Try again..!\n");
            break;
        }
    }
    return 0;
}

void insert(int num)
{
    if(rear==max-1)
    {
        printf("Overflow\n");
    }
    else if(rear==-1 && front==-1)
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=num;
}

void delete()
{
    if(front==-1||front>rear)
    {
        printf("Underflow\n");
    }
    else
    {
        int val;
        val = queue[front];
        printf("Delete item %d",val);
        front++;
        if(front>rear)
        {
            front=rear=-1;
        }
    }
}

void diaplay()
{
    if(front>rear||front==-1)
    {
        printf("The queue si empty");
    }
    else
    {
        printf("queue data is\n");
        for(i=front;i<rear;i++)
        {
            printf("\t %d",queue[i]);
        }
    }
}