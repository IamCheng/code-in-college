#include<stdio.h>
#include<string.h>
void main()
{
	char x[50];	int a,i;
	printf("输入一行字符：\n");
	gets(x);

    a=strlen(x);
	printf("反向显示为：\n");
	for(i=a-1;i>=0;i--)
	printf("%c",x[i]);
	printf("\n");
}