#include<stdio.h>
#include<string.h>
void main()
{
	char a[50];
	int i,j=0,m=0;
	printf("输入一行字符：\n");
	gets(a);
	j=strlen(a);
	for(i=0;i<=j/2;i++)
	{
		if(a[i]==a[j-i-1])
			m++;
	}
	if(m==j/2+1)
        printf("%s是回文\n",a);
		else printf("%s不是回文\n",a);
}
