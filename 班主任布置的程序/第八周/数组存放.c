#include<stdio.h>
void main()
{
	int a[8],b,i;
	printf("输入八个数：\n");
	for(i=0;i<8;i++)
		scanf("%d",&a[i]);
	for(i=0;i<4;i++)
	{
	  b=a[i];
	  a[i]=a[7-i];
	  a[7-i]=b;
	}
	printf("数组反向存放：\n");
	for(i=0;i<8;i++)
		printf("%2d",a[i]);
printf("\n");

}