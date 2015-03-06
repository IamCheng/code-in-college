#include<stdio.h>
void main()
{
	int i,j;
	i=8;
	j=10;
	printf("%d,%d\n",++i,++j);
	i=8;
	j=10;
	printf("%d,%d\n",i++,j++); 
	i=8;
	j=10;
	printf("%d,%d\n",++i,i);
    i=8;
	j=10;
	printf("%d,%d\n",i++,i);
}