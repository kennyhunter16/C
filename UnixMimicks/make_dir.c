/************
* Name: make_dir.c
* Author: Kenneth Hunter
* Date: March 11, 2014
* Version: 1.0
* Course: CENG411
* 
* Purpose: To create a directory
**************/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int i;   //Counter

	//Check if there are the correct argumnents
	if(argc < 2) {
		fprintf(stderr, "More argumnents required.\n");
		return 1;
		}
	
	//The Permission Requirements for the directory
	mode_t permissions = S_IRUSR | S_IRGRP | S_IROTH | //Everyone  Read
						 S_IWUSR |					  //user gets Write
						 S_IXUSR | S_IXGRP | S_IXOTH; //Everyone excute

	//Create the directory, with the permissions above
	for(i = 1; i < argc; i++) {
		if(mkdir(argv[i], permissions) == 0) 
			continue;

	//Error
	else {
		perror("ERROR");
		return errno;
		}
 return 0;
} 
}
