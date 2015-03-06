#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int main()
{
	/*int i;
	int *pn=(int*)malloc(5*sizeof(int));
	printf("%p\n",pn);
	for(i=0;i<5;i++)
		scanf("%d",&pn[i]);
	pn=(int *)realloc(pn,10*sizeof(int));
	printf("%p\n",pn);
	for(i=0;i<5;i++)
		printf("%3d",pn[i]);
	printf("\n");
	free(pn);
	return 0;*/
	char *a;
	a=(char*)malloc(10*sizeof(char));
	scanf("%s",a);
	printf("%s\n",a);
	a=(char*)realloc(a,20*sizeof(char));
	printf("%s\n",a);
	a[10]='a';
	a[11]='d';
	a[12]='d';
	a[9]='r';a[13]='\0';
	printf("%s\n",a);

}
