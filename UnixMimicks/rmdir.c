/************
* Name: rmdir.c
* Author: Kenneth Hunter
* Date: March 11, 2014
* Version: 1.0
* Course: CENG411
* 
* Purpose: To remove a directory
**************/
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;	//Counter

	 //Check if the Argumnets are Correct
	 if(argc > 2) {
		fprintf(stderr, "More Argumnets Required.");
		return 1;
		}

	//Checks all the argumnets and removes the following directories 
	// if possible
	 for(i = 1; i < argc; i++) {
		if(rmdir(argv[i]) == 0) 
			continue;
		else {
			perror("ERROR");	//Return Error, if cannot.
			return errno;
			 }
		}
}


