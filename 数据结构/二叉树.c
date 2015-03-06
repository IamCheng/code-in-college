#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *l,*r;
}tree,*treeptr;
typedef struct node
{
	treeptr data;
	struct node *next;
}node2;
typedef struct node3//���е����ݽṹ
{
	node2 *front,*rear;
}queue;
void QueueInit(queue *s)//���г�ʼ��
{
	s->rear=NULL;
	s->front=NULL;
}
int QueuePush(queue *s,treeptr x)//��Ӳ���
{
	node2 *p;
	p=(node2*)malloc(sizeof(node2));
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
	return 1;
}
int QueuePop(queue *s,treeptr *x)//���Ӳ���
{
	node2 *p;
	if(s->front!=0)
	{
		p=s->front;
		*x=p->data;
		s->front=s->front->next;
		free(p);
		return 1;
	}
	else
		return 0;
}
void CreatBTree(treeptr *T)
{
	int x,k=1;
	queue s;
	treeptr p;
	scanf("%d",&x);
	QueueInit(&s);
	if(x)
	{
		if((*T=(treeptr)malloc(sizeof(tree)))==NULL)
		{
			printf("���ڷ���ʧ��\n!\n");
			exit(0);
		}
		(*T)->data=x;
		QueuePush(&s,*T);
	}
	while(s.front!=NULL)
	{
		QueuePop(&s,&p);
		if(x!=9999&&k==1)	
			scanf("%d",&x);
		else
			x=k=0;
		if(x==9999)
			x=k=0;
		if(x)
		{
			if((p->l=(treeptr)malloc(sizeof(tree)))==NULL)
			{
				printf("���ڷ���ʧ��\n!\n");
				exit(0);
			}
			p->l->data=x;
			QueuePush(&s,p->l);
		}
		else
			p->l=NULL;
		if(x!=9999&&k==1)	
			scanf("%d",&x);
		else
			x=k=0;
		if(x==9999)
			x=k=0;
		if(x)
		{
			if((p->r=(treeptr)malloc(sizeof(tree)))==NULL)
			{
				printf("���ڷ���ʧ��\n!\n");
				exit(0);
			}
			p->r->data=x;
			QueuePush(&s,p->r);
		}
		else
			p->r=NULL;
	}
}
void print(treeptr s)
{
	if(s!=NULL)
	{
		print(s->l);
		printf("%d ",s->data);
		print(s->r);
	}
}
void main()
{

	tree *T;
	printf("����һ�ö�����:\n�����������һ��Ԫ��ֵ��Ϊ0�Ľ�㣬������9999����\n");
	CreatBTree(&T);
	printf("�����������ɹ�!\n");
	printf("���������\n");
	print(T);
	printf("\n");
	
}

