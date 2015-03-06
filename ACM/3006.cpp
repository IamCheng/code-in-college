#include<stdio.h>
#include<math.h>
int judge(int num)
{
	int i;
	if(num==1)
		return 0;
	if(num==2)
		return 1;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
			return 0;
	}
	return 1;
}
void main()
{
	int i,j,a,d,n,tmp;
	int sum=0;
	while(scanf("%d%d%d",&a,&d,&n)!=EOF)
	{
		j=0;
		if(a==0&&d==0&&n==0)
			break;
		for(i=1;i<=n;j++)
		{
			tmp =a+d*j;
			if(judge(tmp))
				i++;	
		}
		printf("%d\n",a+d*(j-1));
	}
}