#include<stdio.h>
void main()
{
	int a[3][4],max,r,c,i,j;
	printf("����12����\n");
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
	printf("%d\n��Ӧ���У�%d,��Ӧ���У�%d\n",max,r+1,c+1);
}