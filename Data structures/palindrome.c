#include<stdio.h>
#include<string.h>
#define max 20


int top=-1;
char stack[max];
void push(char x)
{
    if(top==max-1)
    {
        printf("Overflow\n");
    }
    else
    {
        stack[++top]=x;
    }
}

int pop()
{
    return (stack[top--]);
}

int main()
{
    int len,i;
    char str[20],revstr[20];
    printf("Enter the string\n");
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    push(str[i]);
    for(i=0;i<len;i++)
    revstr[i]=pop();
revstr[i]='\0';
printf("revered string is %s",revstr);
if(strcmp(str,revstr)==0)
{
    printf("palindrome");
}
else
{
    printf("not a plaindrome");
}
}