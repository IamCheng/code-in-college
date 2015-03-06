#include<stdio.h>
void main()
{
	int a[10],i,j,t;
	printf("输入十个整数：\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<9;i++)
	{

	for(j=0;j<9-i;j++)
			if(a[j]>a[j+1])
			{t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
			};
	}
	printf("按从大到小的顺序排列：\n");
	for(j=9;j>=0;j--)
		printf("%3d",a[j]);
	printf("\n");

}


