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
void check()
{
	FILE *fp;
    if((fp=fopen("ͨѶ¼.dat","r"))!=0){ 
	while(1)
	{
		pre=(struct stu*)malloc(sizeof(struct stu));
		fread(pre,sizeof(struct stu),1,fp);
		if(!feof(fp)){
			if(n==0){
			head=pre; 
			p=pre;
			}
			else{ p->next=pre; p=pre;}
			n++;
		}
		else break;
     }
	}
	else
	{if((fp=fopen("ͨѶ¼.dat","w"))!=0) printf("�ļ��ѱ�������\n");}
	fclose(fp);
}
void creat()
{
	printf("����ѧ����ѧ�š�����������š��绰��\n");
    pre=(struct stu*)malloc(sizeof(struct stu));
	scanf("%d %s %d %d",&pre->num,pre->name,&pre->dom,&pre->tel);
	if(n==0) {head=pre;p=pre;}
	else p->next=pre;
	p=pre;
	pre->next=0;
	n++;	
}
void search()
{
   	long j,k,m;char na[10];
	printf("������ҷ�ʽ��1����ѧ��   2��������   3��������   4�����绰:\n");
	scanf("%d",&m);
	p=head;
	if(m==1||m==4)          //��ѧ�Ż������ѯ
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
		while(strcmp(na,p->name)!=0)
		{
			p=p->next;
			if(p==0) {printf("�޴�ѧ����Ϣ\n");break;};
		}
		if(p!=0) printf("ѧ����Ϣ��%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
	}
	if(m==3)
	{
		printf("����ѧ��������\n");
	    scanf("%d",&k);
	    for(j=1;j<=n;j++)
		{
	     	if(p->dom==k)
		    printf("ѧ����Ϣ��%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
	     	p=p->next;
		}
	}
}

void correct()
{
	char na[10];int j;
	p=head;
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
	fp=fopen("ͨѶ¼.dat","w");
	if(fp==0) {printf("error!\n");}
	p=head;
	while(p!=0)
	{
		fwrite(p,sizeof(struct stu),1,fp);
		p=p->next;
	}
	fclose(fp);
}
void print()
{
	p=head;
	printf("���ѧ����Ϣ��\n");
    while(p!=0)
	{
		printf("%d  %s  %d  %d\n",p->num,p->name,p->dom,p->tel);
        p=p->next;
	}
}

void main()
{
	int i;
	printf("      ��ӭ����ͨѶ¼ϵͳ\n");
	printf("1�����     2������       3���޸�     4��ɾ��     5��ͳ��     6���˳�   7����ӡ\n");
    check();
	scanf("%d",&i);
	while(i)
	{
		if(i==1) creat();
		if(i==2) search();
	    if(i==3) correct();
	    if(i==4) del();
	    if(i==5) printf("ͨѶ¼����%d�ˣ�\n",n);
		if(i==6) {esc();break;};
		if(i==7) print();
		printf("1�����     2������       3���޸�     4��ɾ��     5��ͳ��     6���˳�   7����ӡ\n");
		scanf("%d",&i);
	}
	



}