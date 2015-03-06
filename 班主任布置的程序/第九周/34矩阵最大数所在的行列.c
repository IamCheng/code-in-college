#include<stdio.h>
void main()
{
	int a[3][4],max,r,c,i,j;
	printf("输入12个数\n");
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)				
			printf("%3d",a[i][j]);
		printf("\n");
	}
	max=a[0][0];
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
		{
			if(a[i][j]>=max)
			{
				max=a[i][j];
				r=i;
				c=j;
			}
		}
	printf("%d\n对应的行：%d,对应的列：%d\n",max,r+1,c+1);
}