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
		printf("该队列已满!");
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
		printf("该队列没有足够元素！\n");
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
		printf("队列的所有元素为：\n");
		while(s.front<s.rear)
		{
			printf("%d ",s.num[s.front]);
			s.front++;
		}
		printf("\n");
	}
	else
		printf("该队列没有元素！\n");
}
void main()
{
	queue s;
	int i,j,k;
	QueueInit(&s);
	while(1)
	{
		printf("*****请选择操作*****\n");
		printf("1、入队  2、出队  3、取队头元素  4、遍历队列  5、退出\n");
		printf("选择:\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			printf("输入10个元素的值：\n");
			for(i=0;i<10;i++)
			{
				scanf("%d",&j);
				QueuePush(&s,j);
			}break;
		case 2:
			printf("输入要出队的个数：\n");
			scanf("%d",&i);
			printf("出队的元素为：\n");
			for(;i>0;i--)
			{
				k=QueuePop(&s,&j);
				if(k)
					printf("%d ",j);
			}break;
		case 3:
			i=Getfront(&s);
			if(i!=0)
				printf("队头元素为%d\n",i);
			else
				printf("该队列没有元素！\n");
			break;
		case 4:
			QueueTran(s);
			break;
		case 5:break;
		default: printf("您的输入有误\n");
		}
		getch();
		system("cls");
		
	}
}