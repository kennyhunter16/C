/*************
* Name: links.c
* Author: Kenneth Hunter
* Date: March 9th, 2014
* Version: 1.0
*
* Purpose: To create both hard links and symbolic links.
**************/
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	// -f flag and -s flag
	bool forceflag = false;
	bool softlink = false;
	int flag;
	
	//Capture the Flags
	while ((flag = getopt(argc, argv, "fs")) != -1)
	{ 
		switch (flag){
			case 'f':
				forceflag = true;
				break;
			case 's':
				softlink = true;
				break;
			default:
				perror("Bad Flag");
				}
	}

	//Capture file names
	const char *oldfile = argv[optind];
	const char *newfile = argv[optind+1];

	/***********
	* If -f flag is set = will remove newfile, if possible
	  IF -s flag is set = will create symbolic link of oldfile to new
	  IF no flag is set = will create a hard link of oldfile to new
	*********/

	if (forceflag) {
		if(unlink(newfile) !=0)
			perror("ERROR: Deleteing Link");
		}
	
	if (softlink){
		if (symlink(oldfile, newfile) == 0)
			 return 0;
		else {
			 perror("ERROR: Failed to create Symbolic Link");
			 return errno;
		     }
		}
    
	else {
		if (link(oldfile, newfile) == 0)
			return 0;
		
		else {
			perror("ERROR: Failed to create Hard Link");
			return errno;
			} 
		} 
	
	return errno;
}
