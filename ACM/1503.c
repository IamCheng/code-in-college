#include<stdio.h>
#include<string.h>
int sum(char *a,char *b,char *c)
{
	int len_a,len_b,len_c,tmp=0,i=0,j;
	char d[101];
	len_a=strlen(a);
	len_b=strlen(b);
	if(len_a<len_b)
	{	
		strcpy(d,b);
		strcpy(b,a);
		strcpy(a,d);
		len_a = len_a + len_b;
		len_b = len_a - len_b;
		len_a = len_a - len_b;
	}
	len_c=len_a;
	for(;len_a>0;)
	{
		if(--len_b>=0)
			tmp += (a[--len_a]-'0')+(b[len_b]-'0');
		else
			tmp +=a[--len_a]-'0';
		if(tmp<10)
			a[len_a] = tmp+'0';
		else
			a[len_a] = tmp%10+'0';
		tmp /= 10;
	}
	if(tmp==1)
	{
		i=1;
		d[0]=tmp+'0';
	}
	for(j=0;j<=len_c;j++)
		d[i++]=a[j];
	strcpy(a,d);
	return 1;
	
}
void main()
{
	char a[101] = "0",b[101];
	while(scanf("%s",b)!=EOF)
	{
		if(strcmp(b,"0")==0)
			break;
		sum(a,b,a);
	}
	printf("%s\n",a);
	
}