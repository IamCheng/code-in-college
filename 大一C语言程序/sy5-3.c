#include<stdio.h>
void main()
{
	int m,n,y,x,z,p;
	printf("输入两个数：\n");
    scanf("%d%d",&m,&n);
	z=m*n;
    if(m<n)
	{y=m;
	m=n;
	n=y;}
	for(;x!=0;)
	{x=m%n;
	 m=n;
	 n=x;
	}
	p=z/m;
	printf("最大公约数为：%d\n最小公倍数为：%d\n",m,p);
}
