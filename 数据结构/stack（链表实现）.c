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
		printf("��ջû���㹻Ԫ��!\n������ջ!\n");
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
		printf("ջ������Ԫ��Ϊ��\n");
	else
		printf("��ջ��Ԫ��!");
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
	printf("*****����*****\n");
	StackInit(&s);
	while(1)
	{
		printf("1����ջ  2����ջ 3��ȡջ��Ԫ��  4������ջ  5���˳�\n");
		scanf("%d",&t);
		switch(t)
		{
		case 1:
			printf("����10������\n");
			for(i=10;i>0;i--)
			{
				scanf("%d",&t);
				StackPush(&s,t);
			}
			break;
		case 2:
			printf("�����ջ��������\n");
			scanf("%d",&t);
			while(t-->0)
				StackPop(&s);
			system("pause");
			system("cls");
			break;
		case 3:
			if(GetTop(&s)!=0)
				   printf("ջ����Ԫ��Ϊ��%d\n",GetTop(&s));
			else
				printf("��ջû��Ԫ��!\n");
			break;
		case 4:StackTranverse(&s);break;
		case 5:break;
		default:printf("���������������������룡\n");
		}
		if(t==5) break;
	}
	
}