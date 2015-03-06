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
	
}
void draw()
{
	printf("\t**********************欢迎进入学生成绩管理系统*******************\n");
	printf("\t*                                                               *\n");
	printf("\t*  1、添加      2、修改        3、删除     4、显示    5、保存   *\n");
	printf("\t*  6、成绩排序  7、查询并显示  8、统计     9、修改密码并退出    *\n");
	printf("\t*                                                               *\n");
	printf("\t*****************************************************************\n");

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
	system("pause");

}
void modify()
{
	char name[10];int j;
	stu *modify;
	modify=head;
	printf("输入要修改人的名字:\n");
	scanf("%s",name);
	for(j=1;j<=n;j++)
	{
		if(strcmp(name,modify->name)==0) 
		{
			printf("重新输入信息：\n");
			scanf("%d %s %s %s %d %d %d",&modify->num,modify->name,modify->grade,modify->major,&modify->score[0],&modify->score[1],&modify->score[2]);
			printf("修改成功！\n");system("pause");return;
		}
		else
	        modify=modify->next;
	}
	if(modify==0) printf("无此人信息！\n");
	system("pause");
}

void del()
{
	long d;stu *del,*before=0;
	del=head;
	printf("输入需要删除的学号：\n");
	scanf("%d",&d);
	while(del!=0)//遍历链表
	{
		if(del->num!=d) before=del;//记下删除节点的前一个节点
		else break;
		del=del->next;
	}
	if(del==0) printf("无此人信息，删除失败！\n");
	else
	{
		if(before==0) //要删除的节点为头结点
		{
			head=del->next;
			free(del);
			//n--;
		}
		else{
		before->next=del->next;
		free(del);
		//n--;
		}
		printf("该节点已删除！\n");
		n--;
	}
}
void print()
{
	stu *print;
	print=head;
	if(print==0) printf("链表没有数据！请先添加！\n");
	else
	{
		system("cls");
		draw();
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
				if(h->next->ave<h->next->next->ave)
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

void sortnprint()
{
	FILE *fp;stu *s,*q;
	if(n!=0)
	{
		system("cls");
		draw();
		if((fp=fopen("ave.dat","w"))==0) {printf("error!\n");return;}
		s=head;
		while(s!=0)
		{
			s->sum=s->score[0]+s->score[1]+s->score[2];
			s->ave=(float)s->sum/3;
			s=s->next;
		}
		printf("按平均分排序：\n");
		sort();
		s=head;
		while(s!=0)
		{
			fprintf(fp,"%d %s %s %s %d %d %d %f\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2],s->ave);
			printf("%d %s %s %s %d %d %d %.2f\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2],s->ave);
			s=s->next;
		}
		fclose(fp);
		if((fp=fopen("sum.dat","w"))==0) {printf("error!\n");return;}
		printf("按总分排序：\n");
		s=head;
		while(s!=0)
		{
			q=s;
			fprintf(fp,"%d %s %s %s %d %d %d %d\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2],s->sum);
			printf("%d %s %s %s %d %d %d %d\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2],s->sum);
			s=s->next;
		}
		pre=p=q;
		fclose(fp);
	}
	else printf("链表没有数据！\n");
}
void search()
{
	stu a[100],*s;FILE *fp;
	int i,j=0,m,r,low=0,high=n-1,mid,t=0,k;
	char name1[20];
	printf("1、查询人数 2、按学号查询 3、按姓名查询\n");
	scanf("%d",&m);
	if(m==1)
	{
		if((fp=fopen("sum.dat","r"))==0)
		{
			printf("打开总成绩文件失败!\n请先对数据进行排序！\n");
			return;
		}
		printf("输入要查询的总分:\n");
		scanf("%d",&r);
		for(i=0;i<n;i++)
			fscanf(fp,"%d %s %s %s %d %d %d %d\n",&a[i].num,a[i].name,a[i].grade,a[i].major,&a[i].score[0],&a[i].score[1],&a[i].score [2],&a[i].sum);
		if(r==a[low].sum) {while(r==a[low++].sum)t++;}
		else
		if(r==a[high].sum){while(r==a[high--].sum)t++;}
		else
		while(low<=high)
		{
			mid=low+(high-low)/2;
			if(a[mid].sum==r){k=mid-1;while(r==a[mid++].sum)t++;while(r==a[k--].sum) t++;break;}
			if(a[mid].sum>r) low=mid+1;
			else high=mid-1;
		}
		printf("%d分共有%d人！\n",r,t);
	}
	if(m==2)
	{
		printf("输入你要查询的学号：\n");
		scanf("%d",&r);
		s=head;
		while(s!=0)
		{
			if(s->num==r) 
			{
				printf("%d %s %s %s %d %d %d\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2]);
				break;
			}
			s=s->next;
		}
	
	
	}
	if(m==3)
	{
		printf("输入你要查询的姓名：\n");
		scanf("%s",name1);
		s=head;
		while(s!=0)
		{
			if(strcmp(name1,s->name)==0)
			{
				printf("%d %s %s %s %d %d %d\n",s->num,s->name,s->grade,s->major,s->score[0],s->score[1],s->score[2]);
			    break;
			}
			s=s->next;
		}
	}
}
void count()
{
	stu *s;float a[3]={0};int i,j,max[3],min[3],pass[3]={0},f[3][4]={0};
	for(j=0;j<3;j++)
	{
		s=head;
		for(i=0;i<n;i++)
		{
			if(i==0) {max[j]=s->score[j];min[j]=s->score[j];}
			else
			{
				if(max[j]<s->score[j])
					max[j]=s->score[j];
				if(min[j]>s->score[j])
					min[j]=s->score[j];
			}
			a[j]+=s->score[j];
			if(s->score[j]>=60) pass[j]++; 
			switch(s->score[j]/10)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:f[j][0]++;break;
			case 6:
			case 7:f[j][1]++;break;
			case 8:f[j][2]++;break;
			case 9:
			case 10:f[j][3]++;break;
			}

	        s=s->next;
		}
	}
	for(i=0;i<3;i++)
	{
		printf("第%d科成绩平均分：%f分、最高分：%d分、最低分：%d分、及格率：%.2f %%\n",i+1,a[i]/n,max[i],min[i],(float)pass[i]/n*100);
		printf("0-59分：%d人\n60-79分：%d人\n80-89分：%d人\n90-100分：%d人\n",f[i][0],f[i][1],f[i][2],f[i][3]);
	}


}
void login(char password[11],int *flag)
{
	int i;
	FILE *fp;
	char input[10];
	if((fp=fopen("password.dat","r"))!=0)
	{
		fscanf(fp,"%s\n",password);
		for(i=0;i<strlen(password);i++)
			password[i]=password[i]-'1';
	}		
	else
		strcpy(password,"123456");
	printf("请输入管理员密码:\n");
	for(i=3;i>0;i--)
	{
		gets(input);
		if(strcmp(password,input)==0)
		{	*flag=0;return;}
		if(i==1) {*flag=1;return ;}
		else printf(" 密码错误，您还有%d次输入机会!\n",i-1);
			
	}
}
void changepassword(char password[])
{
	char s[10];int flag,i;
	FILE *fp;
	printf("请输入管理员密码:\n");
	for(i=3;i>0;i--)
	{
		gets(s);
		if(strcmp(password,s)==0)
		{flag=0;break;}
		else printf(" 密码错误，您还有%d次输入机会!\n",i-1);
			
	}
	if(flag==0)
	{
		if((fp=fopen("password.dat","wb"))!=0)
		printf("输入10位内新密码:\n");
		gets(password);
		for(i=0;i<strlen(password);i++)
			password[i]=password[i]+'1';
		printf("修改成功！\n");
		fputs(password,fp);
		fclose(fp);
	}

}

void main()
{
	char password[11],c;int flag;
	login(password,&flag);
	if(flag!=1) 
	{
		system("cls");
		draw();
		check();
		while(1)
		{
			c=getch();
			switch(c)
			{
			case '1':add();system("cls");draw();break;
			case '2':modify();system("cls");draw();break;
			case '3':del();break;
			case '4':print();break;
			case '5':save();break;
			case '6':sortnprint();break;
			case '7':search();break;
			case '8':count();break;
			case '9':changepassword(password);break;
			default :printf("您输入有误，请重新输入！\n");
			}
			if(c=='9') break;			
		}
	}

}

