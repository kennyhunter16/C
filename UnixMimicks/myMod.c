/******************
* Name: myMod.c
* Author: Kenneth Hunter
* Date: March 8th, 2014
* Version 1.0
*
* Purpose: To change permissions of a file, using octal values
           as an input.
*******************/
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

int main (int argc, char *argv[])
{
	if (argc < 3){ 
		fprintf(stderr, "Not enough argumnets");
		return 1;
	    }

	int permHOLD;; //Keeps the Octal Input Value
	int i = 2;	  //Counter Value
	
	// Loads in OCTAL value
	sscanf(argv[1], "%o", &permHOLD);

	//Checks permission access, then changes if possible
	for (i = 2; i < argc; i++) {
		if(chmod(argv[i], permHOLD) == 0) continue;
		else {
			perror("ERORR");
			break;
			} 
		}
}





