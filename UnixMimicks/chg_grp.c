/************
* Name: modGroup.c
* Author: Kenneth Hunter
* Date: March 12, 2014
* Version: 1.0
* Course: CENG411
* 
* Purpose: To create a directory
**************/
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <grp.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <dirent.h>
#include <stdbool.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int i;	//Counter
    char *groupID = argv[1]; //Load the Group ID
    struct group *groups = getgrnam(groupID); //Gets GROUP NAME
    
    //Check to see if the Group is LEGIT
    if(groups  == NULL) {
        perror("ERROR: Couldn't find group.");
        return errno;
    }

	//Go though the files and change the groups when the file found
	// It will get the Group ID and print the correct Group Title
    for(i = 2; i < argc; i++) {
        if(chown(argv[i], (uid_t)-1, groups->gr_gid) == 0)
			continue;
        else {
			//If you they cannot change the group, print this message
            perror("ERROR: Couldn't change group, check permissions!");
            return errno;
        }
    }

    return 0;
}
