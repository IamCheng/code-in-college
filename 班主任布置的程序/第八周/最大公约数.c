#include<stdio.h>
void main()
{
	int a,b,c,d;
	printf("输入两个数：\n");
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		c=a;
	    a=b;
     	b=c;
	}
	
	for(;b!=0;)
	{   
		d=a%b;
		a=b;
		b=d;
	}
	printf("最大公约数为：%d\n",a);
}
	
