/************
* Name: get_dir.c
* Author: Kenneth Hunter
* Date: March 12, 2014
* Version: 1.0
* Course: CENG411
* 
* Purpose: To create a directory
**************/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *dir;	//Hold Directory Value
    //Displays Current Directory
    if((dir = getcwd(NULL, 0)) != NULL) {
        fprintf(stdout, "Current Dir: %s\n", dir);

		//Changes the source to the New Directory
        if(chdir("/etc") == 0)

			//If the changed directory doesn't exist will have NULL
            if((dir = getcwd(NULL, 0)) != NULL)
                fprintf(stdout, "New dir: %s\n", dir);
            else {
                perror("ERROR: Couldn't load current directory");
                return errno;
           		 }
        else {
            perror("ERROR: Couldn't load new directory");
            return errno;
        }
        
        //Bug* Doesn't seem to load the new directory

        return 0;
    }
    else {
        perror("Error getting the directory");
        return errno;
    }
}
