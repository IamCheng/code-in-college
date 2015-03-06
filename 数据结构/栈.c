#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *next;
};
struct LinkStack
{
	struct Node *top;
};
struct Node* StackPush(struct Node *p,int x)
{
	struct Node *tmp;
	tmp=(struct Node *)malloc(sizeof(struct Node));
	tmp->data=x;
	tmp->next=p;
	p=tmp;
	return p;
}
struct Node* StackPop(struct Node *p)
{
	int x;struct Node *tmp;
	tmp=p;
	x=p->data;
	p=p->next;
	return p;
}
int Gettop(struct Node *p)
{
	if(p!=NULL)
		return p->data;
	else return 0;
}
void StackTranverse(struct Node *p)
{
	struct Node *tmp;
	tmp=p;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
	printf("\n");
}
void main()
{
	int m,t;
	struct LinkStack s;
	printf("1、入栈  2、出栈  3、取栈顶元素  4、遍历栈\n");
	s.top=NULL;
	scanf("%d",&m);
	while(m)
	{
		switch(m)
		{
		case 1:
			scanf("%d",&t);
			s.top=StackPush(s.top,t);break;
		case 2:s.top=StackPop(s.top);break;
		case 3:t=Gettop(s.top);printf("%d\n",t);break;
		case 4:StackTranverse(s.top);break;
		}
		printf("1、入栈  2、出栈  3、取栈顶元素  4、遍历栈\n");
		scanf("%d",&m);
	}
}

