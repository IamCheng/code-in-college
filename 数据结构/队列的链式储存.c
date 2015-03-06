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
		printf("�����ڴ�ʧ��!\n");
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
		printf("�ö���û��Ԫ�أ�\n");
	else
		printf("�ö��е�Ԫ��Ϊ��\n");
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
		printf("*****��ѡ�����*****\n");
		printf("1�����  2������  3��ȡ��ͷԪ��  4����������  5���˳�\n");
		printf("ѡ��:\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:
			printf("����Ҫ��ӵĸ�����\n");
			scanf("%d",&m);
			printf("����%d��Ԫ�ص�ֵ��\n",m);
			for(i=0;i<m;i++)
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
				else
				{
					printf("�ö�û���㹻��Ԫ��\n");
					break;
				}
			}break;
		case 3:
			i=Getfront(&s);
			if(i!=0)
				printf("��ͷԪ��Ϊ%d\n",i);
			else
				printf("�ö���û��Ԫ�أ�\n");
			break;
		case 4:
			QueueTrav(s);
			break;
		case 5:break;
		default: printf("������������\n");
		}
		system("pause");
		system("cls");
	}

}
