#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct student
	{
	   long num;
	   char name[20];
	   int age;
	   struct student *next;
	}*head,*pre,*p;
void main()
{
	void creat();
	void insert_by_head();
	void insert_by_end();
	void search_n_ele();
	void search_num();
	void serch_both();
	void del();
	void print();

	creat();
	insert_by_head();
	insert_by_end();
	search_n_ele();
    search_num();
	serch_both();
	del();
    print();
	free(head);

}
void creat()
{
	
	printf("��������:\n");
    printf("����ѧ����ѧ�š�����������(����0 0 0��������)��\n");
    pre=(struct student*)malloc(sizeof(struct student));
	scanf("%d%s%d",&pre->num,pre->name,&pre->age);
	head=pre;
	p=pre;
	while(pre->num!=0)
	{

		pre=(struct student*)malloc(sizeof(struct student));
		printf("����ѧ����ѧ�š�����������(����0 0 0��������)��\n");
		p->next=pre;
		p=pre;
		scanf("%d%s%d",&pre->num,pre->name,&pre->age);
	}
	pre->next=0;
}
void insert_by_head()
{
	struct student *nod,*element;
	nod=(struct student*)malloc(sizeof(struct student));
	element=(struct student*)malloc(sizeof(struct student));
	printf("�ڸ�����ͷ��������Ԫ�أ�\n\n");
	printf("����ѧ����ѧ�š����������䣺\n");
	scanf("%d%s%d",&nod->num,nod->name,&nod->age);
	printf("����ѧ����ѧ�š����������䣺\n");
	scanf("%d%s%d",&element->num,element->name,&element->age);
	nod->next=element;
	element->next=head;
	head=nod;
}
void insert_by_end()
{
	struct student *c,*d,*e;
	printf("�ڸ�����β��������Ԫ�أ�\n\n");
	c=(struct student*)malloc(sizeof(struct student));
	d=(struct student*)malloc(sizeof(struct student));
	e=(struct student*)malloc(sizeof(struct student));
	
	printf("����ѧ����ѧ�š����������䣺\n");
	scanf("%d%s%d",&c->num,c->name,&c->age);
	printf("����ѧ����ѧ�š����������䣺\n");
	scanf("%d%s%d",&d->num,d->name,&d->age);
	printf("����ѧ����ѧ�š����������䣺\n");
	scanf("%d%s%d",&e->num,e->name,&e->age);
	
	pre->num=c->num;
	strcpy(pre->name,c->name);
	pre->age=c->age;
	pre->next=d;
	
	d->next=e;
	e->next=0;
}
void search_n_ele()
{
	int i,n=3;
	p=head;
	printf("���ҵ�����Ԫ�ز������\n");
	for(i=1;i<3;i++)
	{
		p=p->next;
		if(i==2)
			printf("%d %s %d\n",p->num,p->name,p->age);
	}
}
void search_num()
{
	int i=1;long n;
	p=head;
	printf("����Ԫ�ص�ѧ�ţ�\n");
	scanf("%d",&n);
	while(p->num!=n)
	{
		p=p->next;
		i=i+1;
		if(p==0) break;
	}
	if(p!=0)
	printf("��Ԫ�����ڽ�����ţ�%d\n",i);
	else printf("�޴�Ԫ��\n");
}
void serch_both()
{
	struct student *before,*after;
	long n;
	p=head;
	printf("����Ԫ�ص�ѧ�ţ�\n");
	scanf("%d",&n);
	while(p->num!=n)
	{
		before=p;
		p=p->next;
		if(p==0) 
		{
			printf("�޴�Ԫ��\n");
			break;
		}
	}
	if(p!=0)
	{
	after=p->next;
    printf("%d %s %d\n",before->num,before->name,before->age);
	printf("%d %s %d\n",after->num,after->name,after->age);
	}
}
void del()
{
	printf("ɾ����\n\n");
	long n;struct student *r;
	p=head;
	printf("����Ҫɾ����ѧ�ţ�");
	scanf("%d",&n);
	while(p->num!=n)
	{
		r=p;
		p=p->next;
		if(p==0) 
		{
			printf("�޴�Ԫ��\n");
			break;
		}
	}
	if(p!=0)
	{
    r->next=p->next;
	free(p);
    printf("ѧ����ɾ����\n");
	}
}
void print()
{
	p=head;
	printf("���������\n");
    while(p->num!=0)
	{
		printf("%d  %s  %d",p->num,p->name,p->age);
		printf("\n");
        p=p->next;
		if(p==0) 
			break;
	}
}
	

	
