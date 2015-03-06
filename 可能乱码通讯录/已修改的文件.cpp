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
    if((fp=fopen("通讯录.dat","r"))!=0){ 
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
	{if((fp=fopen("通讯录.dat","w"))!=0) printf("文件已被建立！\n");}
	fclose(fp);
}
void creat()
{
	printf("输入学生的学号、姓名、宿舍号、电话：\n");
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
	printf("输入查找方式：1、按学号   2、按姓名   3、按宿舍   4、按电话:\n");
	scanf("%d",&m);
	p=head;
	if(m==1||m==4)          //按学号或宿舍查询
	{
		if(m==1)printf("输入学生的学号：\n");
	    else printf("输入学生的电话：\n");
	    scanf("%d",&k);
	    for(j=1;j<=n;j++)
		{
		    if(p->num==k||p->tel==k)
			{printf("学生信息：%d %s %d %d\n",p->num,p->name,p->dom,p->tel);break;}
		    if(j==n) printf("无此学生信息\n");
	 	    p=p->next;
		}
	}
	if(m==2)
	{
		printf("输入学生姓名：\n");
		scanf("%s",na);
		while(strcmp(na,p->name)!=0)
		{
			p=p->next;
			if(p==0) {printf("无此学生信息\n");break;};
		}
		if(p!=0) printf("学生信息：%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
	}
	if(m==3)
	{
		printf("输入学生的宿舍\n");
	    scanf("%d",&k);
	    for(j=1;j<=n;j++)
		{
	     	if(p->dom==k)
		    printf("学生信息：%d %s %d %d\n",p->num,p->name,p->dom,p->tel);
	     	p=p->next;
		}
	}
}

void correct()
{
	char na[10];int j;
	p=head;
	printf("输入要修改人的名字:\n");
	scanf("%s",na);
	for(j=1;j<=n;j++)
	{
		if(strcmp(na,p->name)==0) 
		{
			printf("重新输入信息：\n");
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
	printf("输入要删除学生的名字：\n");
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
		if(p==0) {printf("无此人信息！\n");break;}
	}
}
void esc()
{
	FILE *fp;
	fp=fopen("通讯录.dat","w");
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
	printf("输出学生信息：\n");
    while(p!=0)
	{
		printf("%d  %s  %d  %d\n",p->num,p->name,p->dom,p->tel);
        p=p->next;
	}
}

void main()
{
	int i;
	printf("      欢迎进入通讯录系统\n");
	printf("1：添加     2：查找       3：修改     4：删除     5：统计     6：退出   7：打印\n");
    check();
	scanf("%d",&i);
	while(i)
	{
		if(i==1) creat();
		if(i==2) search();
	    if(i==3) correct();
	    if(i==4) del();
	    if(i==5) printf("通讯录共有%d人！\n",n);
		if(i==6) {esc();break;};
		if(i==7) print();
		printf("1：添加     2：查找       3：修改     4：删除     5：统计     6：退出   7：打印\n");
		scanf("%d",&i);
	}
	



}