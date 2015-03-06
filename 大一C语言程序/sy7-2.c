#include<stdio.h>
void main()
{
	int m,n;
	int fun(int,int);
	printf("输入两个两位的整数：\n");
	scanf("%d%d",&m,&n);
    
	printf("m=%d,n=%d\nc=%d",m,n,fun(m,n));
}
fun(int x,int y)
{
	return(x/10*1000+x%10+y/10*100+y%10*10);
}