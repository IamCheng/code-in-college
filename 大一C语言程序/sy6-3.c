#include<stdio.h>
void main()
{
	int i,j,a[3][3],b[3][3],sum=0,sum1=0;

	printf("输入9个整数:\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		printf("3*3矩阵为：\n");

	for(i=0;i<3;i++)
	{	for(j=0;j<3;j++)
	{
		  printf("%3d",a[i][j]);
          b[j][i]=a[i][j];
	}
	printf("\n");
	}
	printf("主对角线和：%d+%d+%d=%d\n",a[0][0],a[1][1],a[2][2],a[0][0]+a[1][1]+a[2][2]);
    printf("矩阵转置：\n");

   for(i=0;i<3;i++)
   {
	   for(j=0;j<3;j++)
	        printf("%3d",b[i][j]);
    printf("\n");
   }  
}
