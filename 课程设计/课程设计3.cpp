#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct student
{
	long num;
	int grade;
	struct student *next;
}*pre,*head,*p;int n=0;
void creat()
{
	printf("输入学生的学号和成绩\n");
    p=(struct student*)malloc(sizeof(struct student));
	scanf("%d%d",&p->num,&p->grade);
	if(n==0) {head=p;pre=p;}
	else pre->next=p;
	pre=p;
	p->next=0;
	n++;
	printf("添加成功！\n");
}

void del()
{
	long d;struct student *del,*before=0;
	del=head;
	printf("输入需要删除的学号：\n");
	scanf("%d",&d);
	while(del!=0)
	{
		if(del->num!=d) before=del;
		else break;
		del=del->next;
	}
	if(del==0) printf("无此人信息，删除失败！\n");
	else
	{
	if(before==0) 
	{
		head=del->next;
		free(del);
		n--;
	}
	else{
	before->next=del->next;
	free(del);
	n--;
	}
	}
}
void sort()
{
	int i,j;
	struct student *h,*d;
	h=(struct student*)malloc(sizeof(struct student ));
	h->next=head;
	head=h;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(h->next->grade>h->next->next->grade)
			{
				d=h->next->next;
				h->next->next=d->next;
				d->next=h->next;
				h->next=d;
			}
			h=h->next;
		}
		h=head;
	
	}
	h=head;
	head=head->next;
	free(h);

}
void Insert()
{
	struct student *insert,*m,*h;
	insert=(struct student*)malloc(sizeof(struct student));
	printf("输入插入人的信息:\n");
	scanf("%d%d",&insert->num,&insert->grade);
	sort();
	m=head;
	if(insert->grade<=m->grade)
	{
		insert->next=head;
		head=insert;
			n++;
			return;
	}
	while(m!=0)
	{
		if(insert->grade>m->grade)h=m;
		else
		{
			insert->next=h->next;
			h->next=insert;
			n++;
			return;
		}
		m=m->next;
	}
	if(m==0)
	{
		h->next=insert;
		insert->next=0;
	}

}
void main()
{
	int max=0,min=0,j;
	float ave=0;
	struct student *s;
	while(1)
	{
		creat();
		printf("是否继续添加？1、是；其它数字“否”\n");
		scanf("%d",&j);
		if(j!=1) break; 
	}
	system("cls");
	s=head;
	max=s->grade;min=s->grade;
	while(s!=0)
	{
		if(s->grade>max) max=s->grade;
		if(s->grade<min) min=s->grade;
		ave+=s->grade;
		s=s->next;
	}
	printf("\t    ------------------------------------------------------\n");
	printf("\t\t      【最高分为:%d 最低分:%d 平均分为:%.2f】\n",max,min,ave/n);
	printf("\t    ------------------------------------------------------\n");
	printf("是否对链表节点进行删除（1“是”；其它数字“否”）：\n");
	scanf("%d",&j);
	if(j==1)
		while(1)
		{
			del();
			printf("继续删除吗？1“是”；其它数字“否”：\n");
			scanf("%d",&j);
			if(j!=1) break; 
		}
	system("cls");
	sort();
	printf("是否对链表进行插入（1“是”；其它数字“否”）：\n");
	scanf("%d",&j);
	if(j==1)
		while(1)
		{
			Insert();
			printf("继续插入吗？1“是”；其它数字“否”：\n");
			scanf("%d",&j);
			if(j!=1) break; 
		}
	system("cls");
	s=head;
	printf("按成绩升序输出：\n\n");
	printf("学号        成绩\n");
	while(s!=0)
	{
		printf("%3d       %4d\n",s->num,s->grade);
		s=s->next;
	}

	
}