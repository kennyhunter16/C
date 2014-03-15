/************
* Name: mktemp.c
* Author: Kenneth Hunter
* Date: March 11, 2014
* Version: 1.0
* Course: CENG411
* 
* Purpose: To create a temp file
**************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *input;
	char *newfile;

	//If argumnet is found, start the tempfile name with that argumnet
	if(argc < 2) 
		input = strcat(argv[0], "XXXXXX");
	else 
		input = strcat(argv[1], "XXXXXX");

	newfile  = mktemp(input);

	//Attempt to create file, if not send error. 
	if(fopen(newfile, "w+") != NULL) {
		fprintf(stdout, "%s\n", newfile);
		return 0;
	}
	
	//ERROR code > 
	else {
		 perror("ERROR: Failed to Create Temp File");
		 return errno;
		}
}
