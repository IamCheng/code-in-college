#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct wnc
{
	char ch;
	int w;
	char *code;
}dat,*datptr;
typedef struct nod
{
	int l,r,p;
	int w;
}HTree;
int compare(const void *a,const void *b)
{
	return strcmp((char*)a,(char*)b);
}
int strnum(char *a,int *i,datptr rcd)
{
	int j=1;
	char *p;
	(*i)=0;
	p=(char *)malloc(strlen(a)*sizeof(char)+1);
	strcpy(p,a);
	qsort(p,strlen(p),sizeof(char),compare);
	printf("%s",p);	
	while(*p!='\0')
	{
		if(*p!=*(p+1))
		{
			rcd[(*i)].w=j;
			rcd[(*i)].ch=*p;
			(*i)++;
		}
		if(*p==*(p+1))
			j++;
		else
			j=1;
		p++;
	}
	rcd[(*i)].w=0;
	printf("共有%d种字符！\n",*i);
	for(j=0;rcd[j].w!=0;j++)
		printf("%c  %d\n",rcd[j].ch,rcd[j].w);
	return 1;
}
int Getmin(HTree *T,int n,int *min)
{
	int i,m=1000000;
	for(i=0;i<n;i++)
		if(T[i].p==0)
		{
			if(m>(T[i].w))
			{
				*min=i;
				m=T[i].w;
			}
		}
		return 1;
		
}
int CreatHTree(HTree **T,datptr rcd,int n)
{
	
	int m=2*(n)-1,i,j,min1,min2,k;
	(*T)=(HTree*)malloc(m*sizeof(HTree));
	for(i=0;i<n;i++)
	{
		(*T)[i].p=0;
		(*T)[i].l=0;
		(*T)[i].r=0;
		(*T)[i].w=rcd[i].w;
	}
	for(;i<m;i++)
	{
		(*T)[i].p=0;
		(*T)[i].l=0;
		(*T)[i].r=0;
		(*T)[i].w=0;
	}
	system("pause");
	for(i=0;i<m;i++)
		printf("%d %d %d %d\n",(*T)[i].w,(*T)[i].l,(*T)[i].r,(*T)[i].p);
	system("pause");
	for(i=n;i<m;i++)
	{
		Getmin(*T,i,&min1);
		(*T)[min1].p=i;
		Getmin(*T,i,&min2);
		(*T)[i].w=(*T)[min1].w+(*T)[min2].w;
		(*T)[i].l=min1;
		(*T)[i].r=min2;
		(*T)[min2].p=i;
	}
	for(i=0;i<m;i++)
		printf("%d %d %d %d\n",(*T)[i].w,(*T)[i].l,(*T)[i].r,(*T)[i].p);
	printf("开始编码\n");
	if(n==1)
	{
		rcd[0].code=(char *)malloc(2*sizeof(char));
		rcd[0].code="0";

	}
	else
		for(i=0;i<n;i++)
		{
			k=i;
			rcd[i].code=(char *)malloc(n*sizeof(char));
			for(j=0;(*T)[k].p!=0;j++,k=(*T)[k].p)
			{
				if(k==(*T)[(*T)[k].p].l)
				{
					printf("0\n");
					rcd[i].code[j]='0';
				}
				else
				{
					rcd[i].code[j]='1';
					printf("1\n");
				}
				
			}
			printf("----编码一次----\n");
			rcd[i].code[j]='\0';
		}
	return 1;
}
int Decode(datptr rcd,char **encode,int n,int len)
{
	int i,j;
	printf("密码解码为:\n");
	for(i=0;i<len;i++)
		for(j=0;j<n;j++)
			if(strcmp(encode[i],rcd[j].code)==0)
			{
				printf("%c",rcd[j].ch);
				break;
			}
			printf("\n解码完毕!");
			return 1;
}
int main()
{
	char a[100],tmp,**encode;
	HTree *T;
	int n,i,j,r,k;
	dat rcd[100];
	scanf("%s",a);
	strnum(a,&n,rcd);
	CreatHTree(&T,rcd,n);
	for(i=0;i<n;i++)
	{
		r=strlen(rcd[i].code);
		for(j=0,k=r;j<r/2;j++)
		{	
			tmp=rcd[i].code[j];
			rcd[i].code[j]=rcd[i].code[k-1];
			rcd[i].code[k-1]=tmp;
			k--;
		}
	}
	printf("字符串原码：%s\n",a);
	printf("权值： 字符：  编码：\n");
	for(i=0;i<n;i++)
	{
		printf("%5d %5c %5s\n",rcd[i].w,rcd[i].ch,rcd[i].code);
	}
	encode=(char **)malloc(strlen(a)*sizeof(char*));
	for(i=0,r=0;i<strlen(a);i++)
	{
		for(j=0;j<n;j++)
			if(a[i]==rcd[j].ch)
				break;
		encode[i]=(char*)malloc(strlen(rcd[j].code+1));
		strcpy(encode[i],rcd[j].code);
	}
	printf("字符串被编码为:\n");
	for(i=0;i<strlen(a);i++)
		printf("%s",encode[i]);
	printf("\n执行解码程序。。。\n");
	Decode(rcd,encode,n,strlen(a));
	return 1;
}
