#include<stdio.h>
void main()
{
	float a,x=8.5,y=2.5,z=4;
	
	a=x-z%2*(x+y)%2/2;

	printf("%f\n",a);
}