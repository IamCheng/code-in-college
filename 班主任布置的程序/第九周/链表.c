#include<stdio.h>
#include<malloc.h>
void main()
{
	struct student
	{
		long num;
		char name[20];
		char sex;
		int age;
		struct student *next;
	}*head,*pre,*p,*r;
	long s;
	printf("输入学号、姓名、性别、年龄（0 0 0 0结束输入）：\n");
	pre=(struct student*)malloc(sizeof(struct student));
	scanf("%d%s %c%d",&pre->num,pre->name,&pre->sex,&pre->age);
    p=pre;
	head=pre;
	while(pre->age!=0)
	{
	    pre=(struct student*)malloc(sizeof(struct student));
		scanf("%d%s %c%d",&pre->num,pre->name,&pre->sex,&pre->age);
		p->next=pre;
		p=pre;
	}
	pre->next=0;
	printf("输入要删除的学号：\n");
	scanf("%d",&s);
	p=head;
	while(p->num!=s)
	{
	  r=p;
	  p=p->next;
	  if(p==0) {printf("无此学号：\n");break;}
	}
	if(p!=0)
	{ 
		r->next=p->next;free(p);
		printf("结点已删除！\n\n");
	}
	printf("输出链表：\n");
	p=head;
    while(p->num!=0)
	{
		printf("%d  %s  %c   %d\n",p->num,p->name,p->sex,p->age);
		p=p->next;
	}


	
}
