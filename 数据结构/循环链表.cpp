#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int Elem;
typedef struct LNode
{
	Elem dat;
	struct LNode *next;
	struct LNode *prior;
}Link;
int creatLink(Link **p)//创建双向链表
{
	Link *tmp,*pre;
	tmp=(Link*)malloc(sizeof(Link));
	(*p)=pre=tmp;
	while(scanf("%d",&tmp->dat)!=EOF&&tmp->dat!=0)
	{
		pre->next=tmp;
		tmp->prior=pre;
		pre=pre->next;
		tmp=(Link*)malloc(sizeof(Link));
	}
	if((*p)->dat==0)
		return 0;
	free(tmp);
	pre->next=*p;
	(*p)->prior=pre;
	return 1;

}
int del(Link **p,Elem t)//删除链表中元素为t的结点
{
	Link *tmp;
	if((*p)->dat==t&&(*p==(*p)->next))
	{free(*p);return 0;}
	while((*p)->dat!=t)
	{
		*p=(*p)->next;
	}
	tmp=(*p);
	tmp->prior->next=tmp->next;
	tmp->next->prior=tmp->prior;
	*p=tmp->next;
	free(tmp);
	return 1;
}
int traversal(Link *p)//遍历链表
{
	Link *tmp=p;
	printf("%d ",tmp->dat);
	while((tmp=tmp->next)!=p)
		printf("%d ",tmp->dat);
	printf("\n");
	return 1;
}
void main()
{
	Link *p;
	creatLink(&p);
	traversal(p);
	del(&p,3);
	traversal(p);
}

