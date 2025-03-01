#include<stdio.h>

int fabonacci(int);

int main()
{
    int n,i,res;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    printf("Fabonacci series\n");
    for(i=0;i<n;i++)
    {
        res=fabonacci(i);
        printf("%d",res);
    }
    printf("%d\t is the last element in the series",res);
    return 0;
}

int fabonacci(int n)
{
    if(n==0)
    return 0;
     else if(n==1)
     return 1;
    else
    return (fabonacci(n-1)+fabonacci(n-2))
}