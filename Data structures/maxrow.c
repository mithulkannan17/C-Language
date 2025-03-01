#include<stdio.h>
void maximum(int (*a)[10],int *r,int *c)
{
    int i=0,j,max=0,res[20];
    for(i=0;i<*r;i++)
    {
        for(j=0;j<*c;j++)
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
            }
        }
        res[i]=max;
        max=0;
    }
    printf("Maximum element in each row is:\n");
    for(i=0;i<*r;i++)
    {
        printf("%d\n",res[i]);
    }
}

int main()
{
    int arr[10][10],m,n,i,j;
    printf("Enter the number of rows and column\n");
    scanf("%d %d",&m,&n);
    printf("Enter the elements in the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    maximum(arr,&m,&n);
    return 0;
}