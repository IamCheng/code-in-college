#include<stdio.h>
#include<string.h>
void main()
{
	char x[50];	int a,i;
	printf("����һ���ַ���\n");
	gets(x);

    a=strlen(x);
	printf("������ʾΪ��\n");
	for(i=a-1;i>=0;i--)
	printf("%c",x[i]);
	printf("\n");
}