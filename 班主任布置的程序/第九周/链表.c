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
	printf("����ѧ�š��������Ա����䣨0 0 0 0�������룩��\n");
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
	printf("����Ҫɾ����ѧ�ţ�\n");
	scanf("%d",&s);
	p=head;
	while(p->num!=s)
	{
	  r=p;
	  p=p->next;
	  if(p==0) {printf("�޴�ѧ�ţ�\n");break;}
	}
	if(p!=0)
	{ 
		r->next=p->next;free(p);
		printf("�����ɾ����\n\n");
	}
	printf("�������\n");
	p=head;
    while(p->num!=0)
	{
		printf("%d  %s  %c   %d\n",p->num,p->name,p->sex,p->age);
		p=p->next;
	}


	
}
