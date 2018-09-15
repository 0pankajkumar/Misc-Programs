#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int value = 5;

int main()
{
	pid_t pid;
	pid = fork();
	pid_t wait(int *stat_loc);

	if (pid == 0)
	{
	    value += 15;
	    printf("\nCHILD: value = %d\n", value);
	}
	else if (pid > 0)
	{
	    wait(NULL);
	    printf("\nPARENT: value = %d\n", value);
	    exit(0);
	}
}