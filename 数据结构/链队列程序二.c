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
void queueinitiate(LQueue *Q)//��ʼ��
{
	Q->front=NULL;
	Q->rear=NULL;
}
int queuenotempty(LQueue Q)//���Ƿ��
{
	if(Q.front==NULL)
		return 0;
	else
		return 1;
}
void queueappend(LQueue *Q,Datatype x)//����Ԫ�����
{
	queuenode *p;
	p=NULL;
	p=(queuenode *)malloc(sizeof(queuenode));
	if(!p)
	{
		printf("�ڴ����ʧ��!\n");
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
int queuedelete(LQueue *Q,Datatype *y)//����Ԫ�س���
{
	queuenode *p;
	if(Q->front==NULL)
	{
		printf("�ӿ���Ԫ��!");
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
int queueget(LQueue Q,Datatype *y)//ȡ��ͷ����Ԫ��
{
	if(Q.front==NULL)
	{
		printf("�ӿ������ݣ�\n");
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
	printf("\n��ǰ��ͷԪ��%d: ",x);
	printf("\n���γ��ӵ�����Ԫ������: ");
	while(queuenotempty(L))
	{
		queuedelete(&L,&x);
		printf("%d ",x);
	}
	destroy(L);
	printf("\n");
}