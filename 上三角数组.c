#include<stdio.h>
void main()
{
	int a[25][25],n,p,x,y,z,m=1,r=0,i=0,j=0;
	printf("������һ��������\n");
	scanf("%d",&n);
	//x��ʾ����ĸ�����yб��ĸ�����zΪ����ĸ���
	x=n;
	y=n-1;
	z=n-2;
	//��3Ϊһ������

	for(r=0;r<n/3;r++)
	{
		for(p=0;p<x;p++)
		{
			a[i][j]=m;
			m++;
			j++;
		}
		for(p=0,j=j-2,i=i+1;p<y;p++)
		{
			a[i][j]=m;
			i++;
			j--;
			m++;
		}
		for(p=0,i=i-2,j=j+1;p<z;p++)
		{
			a[i][j]=m;
			i--;
			m++;
		}
		x=x-3;
		y=y-3;
		z=z-3;
		j++;
		i++;
	}
	
	if(n%3>=1)
   	{
		a[i][j]=m;
		
		if(n%3==2) 
		{	
			a[i][j+1]=m+1;
			a[i+1][j]=m+2;
		}
	}
	printf("����Ľ��Ϊ��\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-1-i;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
}

