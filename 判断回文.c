#include<stdio.h>
#include<string.h>
void main()
{
	char a[50];
	int i,j=0,m=0;
	printf("����һ���ַ���\n");
	gets(a);
	j=strlen(a);
	for(i=0;i<=j/2;i++)
	{
		if(a[i]==a[j-i-1])
			m++;
	}
	if(m==j/2+1)
        printf("%s�ǻ���\n",a);
		else printf("%s���ǻ���\n",a);
}
