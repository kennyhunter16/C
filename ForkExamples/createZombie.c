/********
* Name: createZombie.c
* Author: Kenneth Hunter
* Course: CENG411
* Date: April 11th, 2014
* Purpose: An example on how to create an zombie
**********/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main (void)
{
	pid_t child_pid;
	child_pid  = fork ();

	if (child_pid  > 0) 
	{
	   sleep (60);		//Makes the Zombie for small time
	}
	
	else 
	{
		exit (0);
	}

	return 0;
}
