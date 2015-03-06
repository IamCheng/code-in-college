#include<stdio.h>
void main()
{
	int a[10],max,i;
	printf("input 10 numbers:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	max=a[0];
	for(i=1;i<10;i++)
       if(a[i]>=max)max=a[i];
	   printf("max=%d",max);
}
