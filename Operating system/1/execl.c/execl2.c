#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Before exec: This will be replace \n");

    execl1("./execl1","./execl1",NULL);

    printf("This line won't be executed\n");

    return 0;
}

// OUTPUT statements
// gcc -o execl1 execl1.c
// gcc -o execl2 execl2.c
// ./execl1
// ./execl2*/