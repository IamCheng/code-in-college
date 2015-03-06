#include<stdio.h>
#define Max 20
void print(int a[])
{
	int i;
	for(i=4;i>=0;i--)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{
	float sum,tmp[4];
	int a[5];
	for(a[4]=20;a[4]>=5;a[4]--)
	{
		sum=0;
		sum+=(float)1/a[4];
		tmp[0]=sum;
		for(a[3]=a[4]-1;a[3]>=4;a[3]--)
		{
			sum=tmp[0];
			sum+=(float)1/a[3];
			tmp[1]=sum;
			for(a[2]=a[3]-1;a[2]>=3;a[2]--)
			{
				sum=tmp[1];
				sum+=(float)1/a[2];
				tmp[2]=sum;
				for(a[1]=a[2]-1;a[1]>=2;a[1]--)
				{
					sum=tmp[2];
					sum+=(float)1/a[1];
					a[0]=0;
					if(sum==1.0)
						print(a);
				}
			}
		}
	}
	
	
}
