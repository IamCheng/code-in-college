#include<stdio.h>
void main()
{
	int m,n,y,x,z,p;
	printf("������������\n");
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
	printf("���Լ��Ϊ��%d\n��С������Ϊ��%d\n",m,p);
}
