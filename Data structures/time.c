#include<stdio.h>
#include<stdlib.h>

struct time
{
    int h,m,s;
    struct time *next;
};

void display(struct time *);
int main()
{
    struct time *t1,*t2;
    t1=malloc(sizeof(struct time));
    printf("Enter the hour,minute and second for time1\n");
    scanf("%d %d %d",&t1->h,&t1->m,&t1->s);
    t2=malloc(sizeof(struct time));
    printf("Enter the hour,minute and second for time2\n");
    scanf("%d %d %d",&t2->h,&t2->m,&t2->s);
    t1->next=t2;
    display(t1);
    return 0;
}

void display(struct time *t)
{
    struct time *temp=t;
    printf("%d:%d:%d\n",temp->h,temp->m,temp->s);
    temp=temp->next;
    printf("%d:%d:%d\n",temp->h,temp->m,temp->s);
}