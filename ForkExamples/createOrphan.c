/********
* Name: createOrphan.c
* Author: Kenneth Hunter
* Course: CENG411
* Date: April 11th, 2014
* Purpose: An example on how to create an orphan class
**********/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main (void)
{
	pid_t returningChild;
	int status;

	switch (fork())
	{
		case 0:
			fprintf(stdout, "This is the child process");
			fprintf(stdout, "Child pid %d created!\n", getpid());
			while (1) {
				kill(getppid(), SIGINT);
				} 
			break;
		case -1:
			perror("Failed to fork child");
			break;
		default:
			fprintf(stdout, "YOUR CHILD IS DEAD. RIP \n");
	} 
	return 0;
}
