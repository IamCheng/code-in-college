#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node *next;
}queuenode;
typedef struct
{
	queuenode *front;
	queuenode *rear;
}LQueue;
void queueinitiate(LQueue *Q)//初始化
{
	Q->front=NULL;
	Q->rear=NULL;
}
int queuenotempty(LQueue Q)//队是否空
{
	if(Q.front==NULL)
		return 0;
	else
		return 1;
}
void queueappend(LQueue *Q,Datatype x)//数据元素入队
{
	queuenode *p;
	p=NULL;
	p=(queuenode *)malloc(sizeof(queuenode));
	if(!p)
	{
		printf("内存分配失败!\n");
		return ;
	}
	p->data=x;
	p->next=p;
	if(Q->rear!=NULL)
		Q->rear->next=p;
	Q->rear=p;
	if(Q->front==NULL)
		Q->front=p;
}
int queuedelete(LQueue *Q,Datatype *y)//数据元素出队
{
	queuenode *p;
	if(Q->front==NULL)
	{
		printf("队空无元素!");
		return 0;
	}
	else
	{
		*y=Q->front->data;
		p=Q->front;
		
		if(Q->front->next==Q->front)
			Q->front=NULL;
		else
		Q->front=Q->front->next;
		free(p);
		return 1;
	}
}
int queueget(LQueue Q,Datatype *y)//取队头数据元素
{
	if(Q.front==NULL)
	{
		printf("队空无数据！\n");
		return 0;
	}
	else
	{
		*y=Q.front->data;
		return 1;
	}
}
void destroy(LQueue Q)
{
	queuenode *p,*p1;
	p=Q.front;
	while(p!=NULL)
	{
		p1=p;
		p=p->next;
		free(p1);
	}
}
void main()
{
	LQueue L;
	int i,x;
	queueinitiate(&L);
	for(i=0;i<10;i++)
		queueappend(&L,i+1);
	queueget(L,&x);
	printf("\n当前队头元素%d: ",x);
	printf("\n依次出队的数据元素序列: ");
	while(queuenotempty(L))
	{
		queuedelete(&L,&x);
		printf("%d ",x);
	}
	destroy(L);
	printf("\n");
}