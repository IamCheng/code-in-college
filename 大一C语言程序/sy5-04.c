#include<stdio.h>
void main()
{
	int i,sum=1,j=1;
	for(i=2;i<21;i++)
    { 
	   j=j*i;
	   sum=j+sum;
	}
	printf("1!+2!+...+20!=%d\n",sum);
}