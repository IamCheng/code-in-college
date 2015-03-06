#include<stdio.h>
#include<malloc.h>
#define elemtype int
typedef struct num1
{
	elemtype data;
	struct num1 *next;
}Node;
typedef struct num2
{
	Node *front,*rear;
	int num;
}queue;
void QueueInit(queue *s)
{
	s->rear=NULL;
	s->front=NULL;
	s->num=0;
}
int QueuePush(queue*s,int x)
{
	Node *p;
	p=(Node*)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("分配内存失败!\n");
		exit(0);
	}
	else
		p->data=x;
	p->next=NULL;
	if(s->rear!=NULL)
		s->rear->next=p;
	if(s->front==NULL)
		s->front=p;
	s->rear=p;
	s->num++;
	return 1;
}
int QueuePop(queue *s,int *x)
{
	Node *p;
	if(s->num>0)
	{
		p=s->front;
		*x=p->data;
		s->front=s->front->next;
		s->num--;
		return 1;
	}
	else
		return 0;
}
int Getfront(queue *s)
{
	if(s->num>0)
		return s->front->data;
	else
		return 0;
}
void QueueTrav(queue s)
{
	if(s.num==0)
		printf("该队列没有元素！\n");
	else
		printf("该队列的元素为：\n");
	while(s.num>0)
	{
		printf("%d ",s.front->data);
		s.front=s.front->next;
		s.num--;
	}
}
void main()
{
	queue s;
	int i,j,k,m;
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
			printf("输入要入队的个数：\n");
			scanf("%d",&m);
			printf("输入%d个元素的值：\n",m);
			for(i=0;i<m;i++)
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
				else
				{
					printf("该队没有足够的元素\n");
					break;
				}
			}break;
		case 3:
			i=Getfront(&s);
			if(i!=0)
				printf("队头元素为%d\n",i);
			else
				printf("该队列没有元素！\n");
			break;
		case 4:
			QueueTrav(s);
			break;
		case 5:break;
		default: printf("您的输入有误\n");
		}
		system("pause");
		system("cls");
	}

}
