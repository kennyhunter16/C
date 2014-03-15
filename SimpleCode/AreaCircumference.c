/**
* Name: AreaCircumference.c
* Author: Kenneth Hunter
* Date: Feb 5th, 2014
* Version: 0.1
* Purpose: To Calculate the Area & Circumference of a Circle
******************************************
Using the Following Formulas:
- PI = 3.14159265358979323846
- Area of a Circle = (PI * R^2)
- Diameter of a Circle = (2 * Radius)
- Circumference of Circle = 2(PI * Radius)
****************************************/
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846  //Define PI

void Area (float radius)
{
	float output;
	output = (PI * (pow(radius,2)));
	fprintf(stdout,"\nArea of Circle = %.2f", output);
}

void Diameter(float radius)
{
	float output;
	output = (2 * radius);
	fprintf(stdout,"\nDiameter of Circle = %.2f", output);
}

void Circumference(float radius)
{
	float output;
	output = ((PI * radius) * 2);
	fprintf(stdout,"\nCircumference of Circle = %.2f\n\n",output);
}
 
int main (void)
{
	float radius;
	fprintf(stdout,"Enter a Radius: ");
	fscanf(stdin,"%f",&radius);
	Area(radius);
	Diameter(radius);
	Circumference(radius);
	return 0;
} 
