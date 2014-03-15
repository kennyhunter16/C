/**************
* Name: rem.c
* Author: Kenneth Hunter
* Date: March 8th, 2014
* Version 1.0
*
* Purpose: Remove a File from a Directoy
****************/
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

int main (int argc, char *argv[]) 
{
	// Check to see if any files have been added
	if (argc == 1) {
		fprintf(stderr, "No File(s) Selected\n");
		return 1;
	} 

	//Remove the file on argv one! 
	if (unlink(argv[1]) == 0)
		return 0;

	else perror ("ERROR");

	return errno;

	} 
