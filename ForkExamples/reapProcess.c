/********
* Name: reapProcess.c
* Author: Kenneth Hunter
* Course: CENG411
* Date: April 12th, 2014
* Purpose: An example how to reap a process.
**********/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main (void)
{
	int exitCode = 0;

	switch (fork())
	{
		case 0:
			fprintf(stdout, "Hello I'm the child process\n");
			exit(17);
			break;
		case -1:
			perror("Failed to fork child");
			break;
		default:
			wait(&exitCode); //Wait for the Exit Code from the Child
			fprintf(stdout,"The exit code for the Child Process was: (Expected 17): %d",exitCode>>8);
			fprintf(stdout,"\nI am the Parent Process: My ID is: %d\n",getpid());
	} 
	return 0;
}
