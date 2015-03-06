#include<stdio.h>
#define N 40
int main()
{
	int i,j,p,a[N][N],n,m,k=1;
	printf("请输入螺旋矩阵的边长(40之内):");
	scanf("%d",&n);
	if(n%2==0)
		m=n/2;
	else
		m=n/2+1;
	for(p=0,i=0,j=0;p<m;p++)
	{
		i=p,j=p;
		if(n%2!=0&&p==m-1)
		{
			a[i][j]=k;
			break;
		}
		for(;j<n-1-p;j++,k++)
		{
			a[i][j]=k;
		}
		for(;i<n-1-p;i++,k++)
		{
			a[i][j]=k;
		}
		for(;j>0+p;j--,k++)
		{
			a[i][j]=k;
		}
		for(;i>0+p;i--,k++)
		{
			a[i][j]=k;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			printf("%-4d",a[i][j]);
		}
		printf("\n");
	}
     return 0;
}
