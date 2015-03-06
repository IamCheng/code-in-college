#include<stdio.h>
#include<stdlib.h>
#include<String.h>
int compare(const void *a,const void *b)
{
		return strcmp((char*)a,(char*)b);
}
void main()
{
	char a[100],*p;
	int lenth[100]={0};
	int i=0,j=1;
	scanf("%s",a);
	printf("%s\n",a);
	qsort(a,strlen(a),sizeof(char),compare);
	printf("%s\n",a);
	p=a;
	while(*p!='\0')
	{
		if(*p!=*(p+1))
		{
			lenth[i]=j;
			i++;
		}
		if(*p==*(p+1))
			j++;
		else
			j=1;
		p++;
	}
	printf("¹²ÓÐ%dÖÖ×Ö·û£¡\n",i);
	for(j=0;lenth[j]!=0;j++)
		printf("%d ",lenth[j]);
}