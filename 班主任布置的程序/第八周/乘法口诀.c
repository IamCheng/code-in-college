#include<stdio.h>
void main()
{
	int a,b,c;
	printf("³Ë·¨¿Ú¾ö£º\n");
	for(a=1;a<10;a++)
		{
		   for(b=1;b<=a;b++)
		   printf("%2d*%d=%d",a,b,a*b);
		   printf("\n");
		}
}