#include<stdio.h>
void main()
{
	int a;
	void t(int);
    printf("输入一个十进制数：\n");
	scanf("%d",&a);
	t(a);
	printf("八进制：%o\n",a);
	printf("十六进制：%x\n",a);
	
}
void t(int x)
{
	int a[16],b=0;
	for(;b<16;b++)
	{
        a[b]=x%2;
        x=x/2;

	}
	printf("二进制：");
    for(b=15;b>=0;b--)
		printf("%d",a[b]);
	printf("\n");
}
