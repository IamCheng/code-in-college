#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
typedef struct student
{
	long num;
	char name[20],grade[10],major[20];
	int score[3];
	int sum;
	float ave;
	struct student *next;
}stu;stu *head,*pre,*p;
int n=0;
void check()
{
	FILE *fp;int a2=1;
    if((fp=fopen("data.dat","r"))!=0) 
		while(!feof(fp))
		{
			p=(stu*)malloc(sizeof(stu));
			fscanf(fp,"%d %s %s %s %d %d %d\n",&p->num,p->name,p->grade,p->major,&p->score[0],&p->score[1],&p->score[2]);
			if(a2==1){head=p;}else pre->next=p;
			pre=p;
			n++;
			a2++;
     		p->next=0;
		}
		else return;
		printf("%d",n);
}
void add()
{
	char c;
	while(1)
	{
		printf("输入学生的学号、名字、班级、专业、成绩一、成绩二、成绩三：\n");
		p=(stu*)malloc(sizeof(stu));
		scanf("%d %s %s %s %d %d %d",&p->num,p->name,p->grade,p->major,&p->score[0],&p->score[1],&p->score[2]);
		if(n==0) head=p;
			else pre->next=p;
		pre=p;
		p->next=0;
		n++;
		printf("添加成功！\n是否继续添加？（y|n）\n");
		c=getch();
		while(c!='y'&&c!='Y'&&c!='n'&&c!='N')
		{
			printf("你没有按规则输入，请重新输入！\n");
			c=getch();
		}
		if(c=='n'||c=='N') {printf("本次添加结束，请继续操作.\n");break;}
		
	}
	printf("%d",n);
	system("pause");
}
void print()
{
	stu *print;
	print=head;
	if(print==0) printf("链表没有数据！请先添加！\n");
	else
	{
	
		printf("%d\n",n);
		while(print!=0)
		{
			printf("%d %s %s %s %d %d %d\n",print->num,print->name,print->grade,print->major,print->score[0],print->score[1],print->score[2]);
			print=print->next;
		}
	}
}
void save()
{
	FILE *fp;stu *s;
	if(n!=0)
	{
		s=head;
		if((fp=fopen("data.dat","w"))==0) {printf("error!\n");return;}
		while(s!=0)
		{
			fprintf(fp,"%d %s %s %s %d %d %d\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2]);
			s=s->next;
		}
		fclose(fp);
		printf("保存成功，请继续操作\n");
	}
	else printf("没有信息保存，请添加信息后再保存\n");
}
void sort()
{
	int i,j;
	stu *h,*d;
	h=(stu*)malloc(sizeof(stu));
	h->next=head;
	head=h;
	for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(h->next->sum<h->next->next->sum)
				{
					d=h->next->next;
					(h->next)->next=d->next;
					d->next=h->next;
					h->next=d;
				}
				h=h->next;
			}
			h=head;
		
		}
	//h=head;
	head=head->next;
	//free(h);print();
}
void sortnprint()
{
	FILE *fp;stu *s,*q;
	if(n!=0)
	{

		if((fp=fopen("ave.dat","w"))==0) {printf("error!\n");return;}
		s=head;
		while(s!=0)
		{
			s->sum=s->score[0]+s->score[1]+s->score[2];
			s->ave=(float)s->sum/3;
			s=s->next;
		}
	
		sort();
		printf("按平均分排序：\n");
		s=head;
		while(s!=0)
		{
			q=s;
			fprintf(fp,"%d %s %s %s %d %d %d %f\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2],s->ave);
			printf("%d %s %s %s %d %d %d %.2f\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2],s->ave);
			s=s->next;
		}
	    pre=p=q;
		fclose(fp);
	}
	else printf("链表没有数据！\n");
}
void main()
{
	check();
	print();
	sortnprint();
	add();
	print();
	//printf("%d %s %s %s %d %d %d\n",p->num,p->name,p->grade,p->major,p->score[0],p->score[1],p->score[2]);
	//printf("%d %s %s %s %d %d %d\n",pre->num,pre->name,pre->grade,pre->major,pre->score[0],pre->score[1],pre->score[2]);		
	//save();
}
