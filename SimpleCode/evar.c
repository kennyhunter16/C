/****************************
* Name: evar.c
* Author: Kenneth Hunter
* Version: 1.0
* Date: Feb 17, 2014
* Purpose: To show all envp variables
****************************/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[],char * envp[])
{
  int i;
  for(i=0;envp[i];i++)
        fprintf(stdout,"%d. %s\n",i,envp[i]);
  return 0;
}
