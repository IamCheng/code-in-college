#include<stdio.h>
#include<math.h>
int judge(int num)
{
	int i;
	for(i=2;i<=sqrt(num);i++)
		if(num%i==0)
			return 0;
	return 1;

}
int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if (0 == n)
			break;
		for(i=1;i<n/2;i++)
		{
			j = 2 * i + 1;
			if(judge(n-j)&&judge(j))
			{
				printf("%d = %d + %d\n",n,j,n-j);
				break;
			}
		}
		if( i == n/2)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}