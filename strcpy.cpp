#include<stdio.h>
int strcpy(char *b,char *a)
{
	int i=0,j=0;
	if(a[i]=='\0')
		return 0;
	else
		while(a[i]!='\0')
			b[j++]=a[i++];
		b[j]='\0';
		return 1;
}
void main()
{
     char *p,a[30],s[]="adfadfasdfsadf";
	 p=a;
	 strcpy(p,s);
	 printf("%s",a);
	
}
