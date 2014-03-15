/**
* Name: ECHO.c
* Author: Kenneth Hunter
* Date: Feb 17th, 2014
* Purpose: To print arguments
*/

#include <stdio.h>
int main(int argc, char * argv[],char * envp[])
{
  for(int i=0;argv[i];i++)
     fprintf(stdout,"%d. %s\n ", i, argv[i]);
  fprintf(stdout,"\n");
  return 0;
  }



