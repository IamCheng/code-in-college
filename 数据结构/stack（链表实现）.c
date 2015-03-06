#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct num1
{
	int num;
	struct num1 *next;
}stack;
void StackInit(stack **s)
{
	(*s)=NULL;
}
int StackPush(stack **s,int e)
{ 
	stack *p;
	p=(stack *)malloc(sizeof(stack));
	if(p==0)
		exit(0);
	p->num=e;
	p->next=(*s);
	(*s)=p;
	return 1;
}  

int StackPop(stack **s)
{
    stack *p;
    if((*s)==NULL)
	{
		printf("该栈没有足够元素!\n请先入栈!\n");
		return 0;
	}
    p=(*s);
    (*s)=(*s)->next;
    free(p);
    return 1;
}
int GetTop(stack**s)
{
	if((*s)!=NULL)
		return (*s)->num;
	else
		return 0;
}
void StackTranverse(stack**s)
{
	stack *p;
	p=(*s);
	if(p!=0)
		printf("栈的所有元素为：\n");
	else
		printf("该栈无元素!");
	while(p!=0)
	{
		printf("%d ",p->num);
		p=p->next;
	}
	printf("\n");
	system("pause");
	system("cls");
}

void main()
{
	int i,t;
	stack *s;
	printf("*****操作*****\n");
	StackInit(&s);
	while(1)
	{
		printf("1、入栈  2、出栈 3、取栈顶元素  4、遍历栈  5、退出\n");
		scanf("%d",&t);
		switch(t)
		{
		case 1:
			printf("输入10个数：\n");
			for(i=10;i>0;i--)
			{
				scanf("%d",&t);
				StackPush(&s,t);
			}
			break;
		case 2:
			printf("输入出栈个个数：\n");
			scanf("%d",&t);
			while(t-->0)
				StackPop(&s);
			system("pause");
			system("cls");
			break;
		case 3:
			if(GetTop(&s)!=0)
				   printf("栈顶的元素为：%d\n",GetTop(&s));
			else
				printf("该栈没有元素!\n");
			break;
		case 4:StackTranverse(&s);break;
		case 5:break;
		default:printf("您的输入有误！请重新输入！\n");
		}
		if(t==5) break;
	}
	
}