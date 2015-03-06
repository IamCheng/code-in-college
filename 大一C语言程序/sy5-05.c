#include<stdio.h>
void main()
{
	int a,b,c,m;
    printf("三位数的水仙花数为：\n");
	for(m=100;m<1000;m++)
	{
		a=m/100;
		b=m%100/10;
		c=m%100%10;
	if(m==a*a*a+b*b*b+c*c*c)
		printf("%d\n",m);
	}
}
