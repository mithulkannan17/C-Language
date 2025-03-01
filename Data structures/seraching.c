#include<stdio.h>
void search(int *,int *,int *);
int main()
{
    int num,i,a[10],key;
    printf("Enter the number of elements to array\n");
    scanf("%d",&num);
    printf("Enter the elements in the array\n");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the key to be search\n");
    scanf("%d",&key);
    search(a,&num,&key);
    return 0;
}
void search(int *arr,int *n,int *k)
{
    int i,flog=0;
    for(i=0;i<*n;i++)
    {
        if(*arr==*k)
        {
            flog = 1;
            printf("Element %d found at position at %d",*k,i+1);
            break;
        }
        arr++;
    }
    if(flog==0)
    {
        printf("Element not found\n");
    }
}