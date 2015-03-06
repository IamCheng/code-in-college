#include<stdio.h>
void judge(int n,int *s)
{
	(*s)++;
	if(n==1)
		return ;
	else
		if(n%2==1)
			judge(3*n+1,s);
		else
			judge(n/2,s);
}
int main()
{
	int a,b,mm,i,max,a1;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		max=0;
		mm = a>b?a:b;
		for(i=a<b?a:b;i<=mm;i++)
		{
			a1=0;
			judge(i,&a1);
			if(a1>max)
				max=a1;
		}
		printf("%d %d %d\n",a,b,max);
	}
	return 0;
}