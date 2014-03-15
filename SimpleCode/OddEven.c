/**
* Name: OddEven.c
* Author: Kenneth Hunter
* Version: 0.1
* Date: Feb 5th, 2014
* Purpose: Check to see if interger is odd or even
*************************************************/
#include <stdio.h>

int main (void)
{
	int value,oddeven;
	fprintf(stdout,"Enter an Interger: ");
	fscanf(stdin,"%d",&value);

	oddeven = (value % 2);    //Output can only be 0 or 1
	if (oddeven == 0)
	{  fprintf(stdout,"\nIt's EVEN!\n"); }
	else
	{  fprintf(stdout,"\nIt's ODD!\n"); }
	return 0;
}
