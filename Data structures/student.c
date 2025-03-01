#include<stdio.h>

struct student
{
    char name[20];
    int usn;
    int m1,m2,m3;
    float avg;
};

int main()
{
    struct student s[20];
    int n,total=0;
    printf("Enter the number of student:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the name:\n");
        scanf("%s",s[i].name);
        printf("Enter the USN: \n");
        scanf("%d",s[i].usn);
        printf("Enter the marks of 3 subject:\n");
        scanf("%d %d %d",&s[i].m1,&s[i].m2,&s[i].m3);
        total=s[i].m1+s[i].m2+s[i].m3;
        s[i].avg=total/3.0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j = i+1; j < n;j++)
        {
            if(s[i].avg<s.[j].avg)
            {
                struct student temp = s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    printf("\t Student details in descending order\n");
    for(int i=0;i<n;i++)
    {
        printf("\n Student USN = %d",s[i].usn);
        printf("\n Student Name = %d",s[i].name);
        printf("\n Student average marks = %.2f",s[i].avg);
        printf("\n");
    }
    return 0;

}