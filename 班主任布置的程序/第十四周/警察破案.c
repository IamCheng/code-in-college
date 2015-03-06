#include<stdio.h>
void main()
{
	int i,j,m,n,sum,k;
		for(i=0;i<=9;i++)
		{
			m=i*10+i;
			for(j=0;i<=9&&i!=j;j++)
			{
				n=j*10+j;
		        sum=m*100+n;
				for(k=0;k<100;k++)
					if(k*k==sum)
						printf("³µºÅÎª:A%d\n",sum);
			}
		}
}
