#include<stdio.h>
void main()
{
	int a[8],b,i;
	printf("����˸�����\n");
	for(i=0;i<8;i++)
		scanf("%d",&a[i]);
	for(i=0;i<4;i++)
	{
	  b=a[i];
	  a[i]=a[7-i];
	  a[7-i]=b;
	}
	printf("���鷴���ţ�\n");
	for(i=0;i<8;i++)
		printf("%2d",a[i]);
printf("\n");

}