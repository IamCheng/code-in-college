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
	printf("����ѧ����ѧ�źͳɼ�\n");
    p=(struct student*)malloc(sizeof(struct student));
	scanf("%d%d",&p->num,&p->grade);
	if(n==0) {head=p;pre=p;}
	else pre->next=p;
	pre=p;
	p->next=0;
	n++;
	printf("��ӳɹ���\n");
}

void del()
{
	long d;struct student *del,*before=0;
	del=head;
	printf("������Ҫɾ����ѧ�ţ�\n");
	scanf("%d",&d);
	while(del!=0)
	{
		if(del->num!=d) before=del;
		else break;
		del=del->next;
	}
	if(del==0) printf("�޴�����Ϣ��ɾ��ʧ�ܣ�\n");
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
	printf("��������˵���Ϣ:\n");
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
		printf("�Ƿ������ӣ�1���ǣ��������֡���\n");
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
	printf("\t\t      ����߷�Ϊ:%d ��ͷ�:%d ƽ����Ϊ:%.2f��\n",max,min,ave/n);
	printf("\t    ------------------------------------------------------\n");
	printf("�Ƿ������ڵ����ɾ����1���ǡ����������֡��񡱣���\n");
	scanf("%d",&j);
	if(j==1)
		while(1)
		{
			del();
			printf("����ɾ����1���ǡ����������֡��񡱣�\n");
			scanf("%d",&j);
			if(j!=1) break; 
		}
	system("cls");
	sort();
	printf("�Ƿ��������в��루1���ǡ����������֡��񡱣���\n");
	scanf("%d",&j);
	if(j==1)
		while(1)
		{
			Insert();
			printf("����������1���ǡ����������֡��񡱣�\n");
			scanf("%d",&j);
			if(j!=1) break; 
		}
	system("cls");
	s=head;
	printf("���ɼ����������\n\n");
	printf("ѧ��        �ɼ�\n");
	while(s!=0)
	{
		printf("%3d       %4d\n",s->num,s->grade);
		s=s->next;
	}

	
}