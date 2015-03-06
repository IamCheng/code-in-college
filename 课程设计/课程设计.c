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
	printf("\t**********************��ӭ����ѧ���ɼ�����ϵͳ*******************\n");
	printf("\t*                                                               *\n");
	printf("\t*  1�����      2���޸�        3��ɾ��     4����ʾ    5������   *\n");
	printf("\t*  6���ɼ�����  7����ѯ����ʾ  8��ͳ��     9���޸����벢�˳�    *\n");
	printf("\t*                                                               *\n");
	printf("\t*****************************************************************\n");

}
void add()
{
	char c;
	while(1)
	{
		printf("����ѧ����ѧ�š����֡��༶��רҵ���ɼ�һ���ɼ������ɼ�����\n");
		p=(stu*)malloc(sizeof(stu));
		scanf("%d %s %s %s %d %d %d",&p->num,p->name,p->grade,p->major,&p->score[0],&p->score[1],&p->score[2]);
		if(n==0) head=p;
			else pre->next=p;
		pre=p;
		p->next=0;
		n++;
		printf("��ӳɹ���\n�Ƿ������ӣ���y|n��\n");
		c=getch();
		while(c!='y'&&c!='Y'&&c!='n'&&c!='N')
		{
			printf("��û�а��������룬���������룡\n");
			c=getch();
		}
		if(c=='n'||c=='N') {printf("������ӽ��������������.\n");break;}
		
	}
	system("pause");

}
void modify()
{
	char name[10];int j;
	stu *modify;
	modify=head;
	printf("����Ҫ�޸��˵�����:\n");
	scanf("%s",name);
	for(j=1;j<=n;j++)
	{
		if(strcmp(name,modify->name)==0) 
		{
			printf("����������Ϣ��\n");
			scanf("%d %s %s %s %d %d %d",&modify->num,modify->name,modify->grade,modify->major,&modify->score[0],&modify->score[1],&modify->score[2]);
			printf("�޸ĳɹ���\n");system("pause");return;
		}
		else
	        modify=modify->next;
	}
	if(modify==0) printf("�޴�����Ϣ��\n");
	system("pause");
}

void del()
{
	long d;stu *del,*before=0;
	del=head;
	printf("������Ҫɾ����ѧ�ţ�\n");
	scanf("%d",&d);
	while(del!=0)//��������
	{
		if(del->num!=d) before=del;//����ɾ���ڵ��ǰһ���ڵ�
		else break;
		del=del->next;
	}
	if(del==0) printf("�޴�����Ϣ��ɾ��ʧ�ܣ�\n");
	else
	{
		if(before==0) //Ҫɾ���Ľڵ�Ϊͷ���
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
		printf("�ýڵ���ɾ����\n");
		n--;
	}
}
void print()
{
	stu *print;
	print=head;
	if(print==0) printf("����û�����ݣ�������ӣ�\n");
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
		printf("����ɹ������������\n");
	}
	else printf("û����Ϣ���棬�������Ϣ���ٱ���\n");
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
		printf("��ƽ��������\n");
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
		printf("���ܷ�����\n");
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
	else printf("����û�����ݣ�\n");
}
void search()
{
	stu a[100],*s;FILE *fp;
	int i,j=0,m,r,low=0,high=n-1,mid,t=0,k;
	char name1[20];
	printf("1����ѯ���� 2����ѧ�Ų�ѯ 3����������ѯ\n");
	scanf("%d",&m);
	if(m==1)
	{
		if((fp=fopen("sum.dat","r"))==0)
		{
			printf("���ܳɼ��ļ�ʧ��!\n���ȶ����ݽ�������\n");
			return;
		}
		printf("����Ҫ��ѯ���ܷ�:\n");
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
		printf("%d�ֹ���%d�ˣ�\n",r,t);
	}
	if(m==2)
	{
		printf("������Ҫ��ѯ��ѧ�ţ�\n");
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
		printf("������Ҫ��ѯ��������\n");
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
		printf("��%d�Ƴɼ�ƽ���֣�%f�֡���߷֣�%d�֡���ͷ֣�%d�֡������ʣ�%.2f %%\n",i+1,a[i]/n,max[i],min[i],(float)pass[i]/n*100);
		printf("0-59�֣�%d��\n60-79�֣�%d��\n80-89�֣�%d��\n90-100�֣�%d��\n",f[i][0],f[i][1],f[i][2],f[i][3]);
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
	printf("���������Ա����:\n");
	for(i=3;i>0;i--)
	{
		gets(input);
		if(strcmp(password,input)==0)
		{	*flag=0;return;}
		if(i==1) {*flag=1;return ;}
		else printf(" �������������%d���������!\n",i-1);
			
	}
}
void changepassword(char password[])
{
	char s[10];int flag,i;
	FILE *fp;
	printf("���������Ա����:\n");
	for(i=3;i>0;i--)
	{
		gets(s);
		if(strcmp(password,s)==0)
		{flag=0;break;}
		else printf(" �������������%d���������!\n",i-1);
			
	}
	if(flag==0)
	{
		if((fp=fopen("password.dat","wb"))!=0)
		printf("����10λ��������:\n");
		gets(password);
		for(i=0;i<strlen(password);i++)
			password[i]=password[i]+'1';
		printf("�޸ĳɹ���\n");
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
			default :printf("�������������������룡\n");
			}
			if(c=='9') break;			
		}
	}

}

