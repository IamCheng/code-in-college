#include<stdio.h>
void main()
{
	int i,sum;
	i=1;sum=0;
	do
	{sum=sum+i;
	i++;}
	while(i<101);
	printf("%d\n",sum);
}