#include<stdio.h>
void main()
{
	int a,b,c,d;
	printf("������������\n");
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
	printf("���Լ��Ϊ��%d\n",a);
}
	
