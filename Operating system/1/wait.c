#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
    if(fork()==0)
    {
        printf("hello from the child, the process ID is %d\n",getpid());
    }
    else{
        printf("Hello from the parent process, The process ID is %d\n",getpid());
        wait(NULL);
        printf("Child has been terminated, PID is %d\n",getpid());
    }
    printf("Bye, The PID is %d\n",getpid());
}