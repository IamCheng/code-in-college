#include<stdio.h>
void main()
{
	int a[50][50],i,j,n,p,q,max;
	printf("输入一个整数：\n");
	scanf("%d",&n);
	printf("输入%d个数：\n",n*n);
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	max=a[0][0];
    printf("%d*%d的矩阵为:\n",n,n);	
	
    for(i=0;i<n;i++)
	{   
		for(j=0;j<n;j++)
		printf("%3d",a[i][j]);
        printf("\n");
	}
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
		{	
			max=a[i][j]>=max?a[i][j]:max;
	       p=i+1;
		   q=j+1;
		}

    	printf("最大的数为：%d\n",max);
		printf("位于第%d行，第%d列\n",p,q);
}

	

