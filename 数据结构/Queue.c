#include<stdio.h>
#define Max 100
typedef struct Num
{
	int num[Max];
	int front;
	int rear;
}queue;
void QueueInit(queue*s)
{
	s->front=0;
	s->rear=0;
}
int QueuePush(queue *s,int x)
{
	if(s->rear<100)
	{
		s->num[s->rear]=x;
		s->rear++;
		return 1;
	}
	else
		printf("�ö�������!");
	return 0;
}
int QueuePop(queue *s,int *x)
{
	if(s->front<s->rear)
	{
		(*x)=s->num[s->front];
		s->front++;
		return 1;
	}
	else
		printf("�ö���û���㹻Ԫ�أ�\n");
	return 0;
}
int Getfront(queue *s)
{
	if(s->front<s->rear)
		return s->num[s->front];
	else
		return 0;
}
void QueueTran(queue s)
{
	if(s.front<s.rear)
	{
		printf("���е�����Ԫ��Ϊ��\n");
		while(s.front<s.rear)
		{
			printf("%d ",s.num[s.front]);
			s.front++;
		}
		printf("\n");
	}
	else
		printf("�ö���û��Ԫ�أ�\n");
}
void main()
{
	queue s;
	int i,j,k;
	QueueInit(&s);
	while(1)
	{
		printf("*****��ѡ�����*****\n");
		printf("1�����  2������  3��ȡ��ͷԪ��  4����������  5���˳�\n");
		printf("ѡ��:\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			printf("����10��Ԫ�ص�ֵ��\n");
			for(i=0;i<10;i++)
			{
				scanf("%d",&j);
				QueuePush(&s,j);
			}break;
		case 2:
			printf("����Ҫ���ӵĸ�����\n");
			scanf("%d",&i);
			printf("���ӵ�Ԫ��Ϊ��\n");
			for(;i>0;i--)
			{
				k=QueuePop(&s,&j);
				if(k)
					printf("%d ",j);
			}break;
		case 3:
			i=Getfront(&s);
			if(i!=0)
				printf("��ͷԪ��Ϊ%d\n",i);
			else
				printf("�ö���û��Ԫ�أ�\n");
			break;
		case 4:
			QueueTran(s);
			break;
		case 5:break;
		default: printf("������������\n");
		}
		getch();
		system("cls");
		
	}
}