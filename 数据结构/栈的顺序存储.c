#include<stdio.h>
#include<malloc.h>
#define max 5
typedef struct num1
{
	int data;
	int next;
}stack;
int N=1;
void StackInit(stack s[])//ջ�ĳ�ʼ��
{
	int i=0;
	for(i=0;i<max;i++)
	{
		s[i].data=0;
		s[i].next=i-1;
	}
}
int StackPush(stack s[],int x,int *n)//��ջ������nΪ��¼��ǰջ���е�Ԫ�ظ���
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
		printf("��ջ��Ԫ��Ϊ��\n");
		while(i!=-1)
		{
			printf("%d ",s[i].data);
			i=s[i].next;
		}
	}
	else
		printf("��ջû��Ԫ�أ�");
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
		printf("******����******\n");
		printf("1����ջ  2����ջ  3��ȡջ��Ԫ��  4������ջ  5���˳�\n");
		printf("ѡ��\n");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			printf("����Ҫ��ջ�ĸ�����\n");
			scanf("%d",&m);
			printf("����%d������\n",m);
			for(i=0;i<m;i++)
			{
				scanf("%d",&x);
				StackPush(a,x,&n);
				if(n>=max*N)
					realloc1(&a);
			}
			break;
		case 2:
			printf("�������ջ�ĸ�����\n");
			scanf("%d",&m);
			for(i=0;i<m;i++)
			{
				if(StackPop(a,&x,&n))
					printf("%d ",x);
				else
				{
					printf("��ջû���㹻��Ԫ��!\n");
					break;
				}
			}
			printf("\n");
			break;
		case 3:
			if(!Gettop(a,n))
				printf("��ջ��Ԫ��!\n");
			else
				printf("ջ��Ԫ��Ϊ��%d\n",Gettop(a,n));
			break;
		case 4:StackTra(a,n);break;
		case 5:break;	
		default:printf("�����������������롣\n");
		}

		if(k==5) break;
		system("pause");
		system("cls");
	}
}


