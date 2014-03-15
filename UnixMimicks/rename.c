/*********************
* Name: rename.c
* Author: Kenneth Hunter
* Date: March 8th, 2014
* Version: 1.0
*
* Purpose: To rename a file
*********************/
#include <stdio.h>
#include <errno.h>

int main (int argc, char *argv[])
{
	//Checking for argumnets
	if (argc > 3) {
		fprintf(stderr, "Too many argumnets.");
		return 1;
		} 
	
	//Rename file(argv 1) to argumnet 2
	if (rename(argv[1], argv[2]) == 0) 
		return 0;
	
	//Error for failure
	else perror ("ERROR");

	return errno;
}
