#include<stdio.h>
#include<malloc.h>
#define max 5
typedef struct num1
{
	int data;
	int next;
}stack;
int N=1;
void StackInit(stack s[])//栈的初始化
{
	int i=0;
	for(i=0;i<max;i++)
	{
		s[i].data=0;
		s[i].next=i-1;
	}
}
int StackPush(stack s[],int x,int *n)//入栈操作，n为记录当前栈含有的元素个数
{
	s[*n].data=x;
	(*n)++;
	return 1;
}
int StackPop(stack s[],int *x,int *n)
{
	if(s[*n].next!=-1)
	{
		*x=s[*n-1].data;
		s[*n-1].data=0;
		(*n)--;
		return 1;
	}
	return 0;
}
int Gettop(stack s[],int n)
{
	if(s[n].next!=-1)
		return s[n-1].data;
	else
		return 0;
}
void StackTra(stack s[],int n)
{
	int i=0;
	i=s[n].next;
	if(i!=-1)
	{
		printf("该栈的元素为：\n");
		while(i!=-1)
		{
			printf("%d ",s[i].data);
			i=s[i].next;
		}
	}
	else
		printf("该栈没有元素！");
	printf("\n");
}
int realloc1(stack **s)
{
	int i;
	N++;
	*s=(stack*)realloc(*s,max*N*sizeof(stack));
	for(i=max*(N-1);i<max*N;i++)
	{
		(*s)[i].data=0;
		(*s)[i].next=i-1;
	}
	return 1;
}
void main()
{
	int i,k,m,n=0,x;
	stack *a;
	a=(stack*)malloc(max*N*sizeof(stack));
	StackInit(a);
	while(1)
	{
		printf("******操作******\n");
		printf("1、入栈  2、出栈  3、取栈顶元素  4、遍历栈  5、退出\n");
		printf("选择：\n");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			printf("输入要入栈的个数：\n");
			scanf("%d",&m);
			printf("输入%d个数：\n",m);
			for(i=0;i<m;i++)
			{
				scanf("%d",&x);
				StackPush(a,x,&n);
				if(n>=max*N)
					realloc1(&a);
			}
			break;
		case 2:
			printf("请输入出栈的个数：\n");
			scanf("%d",&m);
			for(i=0;i<m;i++)
			{
				if(StackPop(a,&x,&n))
					printf("%d ",x);
				else
				{
					printf("该栈没有足够的元素!\n");
					break;
				}
			}
			printf("\n");
			break;
		case 3:
			if(!Gettop(a,n))
				printf("该栈无元素!\n");
			else
				printf("栈顶元素为：%d\n",Gettop(a,n));
			break;
		case 4:StackTra(a,n);break;
		case 5:break;	
		default:printf("输入有误！请重新输入。\n");
		}

		if(k==5) break;
		system("pause");
		system("cls");
	}
}


