/*
Galvin : Operating Systems
The Fibonacci sequence is the series of numbers 0,1,1,2,3,5,8,...
Write a C program using the fork()
system call that that generates the
Fibonacci sequence in the child process. The number of the sequence
will be provided in the command line. For example, if 5 is provided, the
first five numbers in the Fibonacci sequence will be output by the child
process. Because the parent and child processes have their own copies
of the data, it will be necessary for the child to output the sequence.
Have the parent invoke the
wait()
call to wait for the child process to
complete before exiting the program. Perform necessary error checking
to ensure that a non-negative number is passed on the command line.
*/
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[])
{
    int limits = atoi(argv[1]);
   // ensure proper usage
    if (argv[1] < 0)
    {
        fprintf(stderr, "No negative number please\n");
        return 1;
    }

    int a = 0, b = 1, c = b + a;

    pid_t pid;
	pid = fork();
	pid_t wait(int *stat_loc);

	//Entering child
	if (pid == 0)
	{
	    printf("0 1 ");
        for(int i = 0; i < limits - 2; i++)
        {
            printf("%d ", c);
            a = b;
            b = c;
            c = a + b;
        }
	}
    //Entering parent
    else
    {
        wait(NULL);
        printf("\nParent says, \"My child has done the Job\"\n");
    }

argc = argc + 1; //Just to make sure compiler dosen't cries argc is being unused
}