#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max],top=-1;

void pop();
void push();
void display();

int main()
{
    int num, choice;
    while(1)
    {
        printf("1. TO PUSH \n");
        printf("2. TO POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            printf("EXIT");
            exit(0);
        }
    }
    return 0;
}

void push ()
{
    int item;
    if(top==max-1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the value\n");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
}

void pop()
{
    int item;
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        item=stack[top];
        top=top-1;
        printf("\n The poped element: %d\t",item);
    }
}

void display()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        for(int i = top; i >= 0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}