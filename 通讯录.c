#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct stu
{
	long num;
	char name[10];
	int dom;
	int tel;
	struct stu *next;
}*pre,*p,*head;int n=0;
void creat()
{
	char a;
	printf("����ѧ����ѧ�š�����������š��绰��\n");
    pre=(struct stu*)malloc(sizeof(struct stu));
	scanf("%d%s%d%d",&pre->num,pre->name,&pre->dom,&pre->tel);
	if(n==0) {head=pre;p=pre;}
	else p->next=pre;
	p=pre;
	pre->next=0;
	n++;
	printf("Ҫ���������Y|N\n");
	a=getch();
	if(a=='Y'||a=='y')   creat();
}
void search()
{
   	long j,k,m;char na[10];
	printf("������ҷ�ʽ��1����ѧ��   2��������   3��������   4�����绰:\n");
	scanf("%d",&m);
	p=head;
	if(m==1||m==4)
	{
    if(m==1)printf("����ѧ����ѧ�ţ�\n");
	else printf("����ѧ���ĵ绰��\n");
	scanf("%d",&k);
	for(j=1;j<=n;j++)
	{
		
		if(p->num==k||p->tel==k)
		{printf("ѧ����Ϣ��%d %s %d %d\n",p->num,p->name,p->dom,p->tel);break;}
		if(j==n) printf("�޴�ѧ����Ϣ\n");
		p=p->next;
	}
	}
	if(m==2)
	{
		printf("����ѧ��������\n");
		scanf("%s",na);
		for(j=1;j<=n;j++)
		{
           if(strcmp(na,p->name)==0) printf("ѧ����Ϣ��%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
		   if(j==n) printf("�޴�ѧ����Ϣ\n");
			p=p->next;
			if(p==0) break;
		}
	}
	if(m==3)
	{
		printf("����ѧ��������\n");
	    scanf("%d",&k);
	for(j=1;j<=n;j++)
	{
		
		if(p->dom==k&&j<=n)
		printf("ѧ����Ϣ��%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
		if(j==n) break;
		p=p->next;
	}
	}
}
void check()
{
	FILE *fp;int a2=1;
    if((fp=fopen("ͨѶ¼.dat","r"))!=0) 
	{
	do
	{
		pre=(struct stu*)malloc(sizeof(struct stu));
		fscanf(fp,"%d%s%d%d\n",&pre->num,pre->name,&pre->dom,&pre->tel);
		if(a2==1){head=pre;}else p->next=pre;
		p=pre;
		n++;
		a2++;
     	pre->next=0;
	}while(!feof(fp));

	}
	else
	{if((fp=fopen("ͨѶ¼.dat","w+"))!=0) {printf("�ļ��ѱ�������\n");n=0;}}
	fclose(fp);
}
void correct()
{
	char na[10];int j;
	printf("����Ҫ�޸��˵�����:\n");
	scanf("%s",na);
	for(j=1;j<=n;j++)
	{
		if(strcmp(na,p->name)==0) 
		{
			printf("����������Ϣ��\n");
			scanf("%d%s%d%d",&p->num,p->name,&p->dom,&p->tel);
		}
		else
	        p=p->next;

	   if(p==0) break;
	}
}
void del()
{
    char na[10];struct stu *p1;int j;
	printf("����Ҫɾ��ѧ�������֣�\n");
		p=head;p1=p;
	scanf("%s",na);
	for(j=1;j<=n;j++)
	{
	    if(strcmp(na,p->name)==0) 
		{
			if(j==1) {head=p->next;n--;break;}
			p1->next=p->next;
			n--;
			break;
		}
		else
		{   p1=p;
	        p=p->next;
		}
		if(p==0) {printf("�޴�����Ϣ��\n");break;}
	}
}
void esc()
{
	FILE *fp;
	if((fp=fopen("ͨѶ¼.dat","w"))==0) {printf("error!\n");}
	p=head;
	while(p!=0)
	{
		fprintf(fp,"%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
		p=p->next;
	}
	fclose(fp);
}


			
void main()
{
	int i;
	printf("      ��ӭ�����������Ϣ����ѧԺ2011�����2��ͨѶ¼ϵͳ\n");
	printf("1�����     2������       3���޸�     4��ɾ��     5��ͳ��     6���˳�\n");
    check();
	scanf("%d",&i);
	
	while(1)
	{
		switch(i)
		{
		case 1:creat();break;
		case 2:search();break;
		case 3:correct();break;
		case 4:del();break;
		case 5:printf("ͨѶ¼����%d�ˣ�\n",n);	break;	
		case 6:esc();break;
		default: printf("����������������������\n");
		}
		if(i==6) break;
		printf("1�����     2������       3���޸�     4��ɾ��     5��ͳ��     6���˳�\n");
		scanf("%d",&i);
	}
	



}