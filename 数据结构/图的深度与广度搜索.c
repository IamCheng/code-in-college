#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 50
typedef struct Link1
{
	int num;
	struct Link1 *next;
}Link;//����ṹ
typedef struct Head1
{
	char ch;
	Link *next;
}Head;//������ṹ
typedef struct Graph
{
	Head *ptr;
	int lines;
	int nodes;
}Graphics;//ͼ�Ľṹ
typedef struct queue
{
	int q[Max];
	int front;
	int rear;
}Queue;//���еĽṹ
int Same(Graphics gra,int i)//�ж��������־�Ƿ���ͬ
{
	int j=0;
	while(j<i)
		if(gra.ptr[j++].ch==gra.ptr[i].ch)
			return 1;
	return 0;
		
}
/*����ͼ���ڽӱ���*/
int CreatPtr(Graphics *gra)
{
	int i=0,num1,num2;char ch[3];
	Link *p=NULL;
	printf("������ĸ�����\n");
	scanf("%d",&gra->nodes);
	printf("����������ı��:\n");
	gra->ptr=(Head*)malloc(gra->nodes*sizeof(Head));
	/*�����������ı�־*/
	while(i<=gra->nodes-1)
	{
		(gra->ptr+i)->ch=getch();
		(gra->ptr+i)->next=NULL;
		/*�ж������־��ASC���ǲ�����33~126֮�䣬��������������ַ��Ƿ���ͬ*/
		while((gra->ptr+i)->ch>126||(gra->ptr+i)->ch<33||Same(*gra,i))
			(gra->ptr+i)->ch=getch();
		putch((gra->ptr+i)->ch);
		i++;
	}
	if(gra->nodes==1)
		gra->lines=0;//���ֻ��һ���㣬ֱ���ñ���Ϊ0
	else
	{
		printf("\n����Ҫ����ı���:\n");
		scanf("%d",&gra->lines);
		while(gra->lines<0||gra->lines>gra->nodes*(gra->nodes-1)/2)//�жϱ����Ƿ��ڿ��з�Χ
		{
			printf("�����ķ�ΧΪ:%d~%d֮��!",0,gra->nodes*(gra->nodes-1)/2);
			scanf("%d",&gra->lines);
		}
	}
	/*�����ڽӱ�*/
	for(i=0;i<gra->lines;i++)
	{
		printf("�����%d����(a b)",i+1);
		scanf("%d%d",&num1,&num2);
		p=(Link*)malloc(sizeof(Link));
		p->num=num2-1;
		p->next=(gra->ptr)[num1-1].next;
		(gra->ptr)[num1-1].next=p;
		p=(Link*)malloc(sizeof(Link));
		p->num=num1-1;
		p->next=(gra->ptr)[num2-1].next;
		(gra->ptr)[num2-1].next=p;
	}
	return 1;
}
/*�����������*/
int Dsrch(Graphics gra,int *flag,int choice)
{
	Link *p;
	printf("%3c",gra.ptr[choice].ch);
	flag[choice]=1;//flagΪ������飬���ʹ���Ԫ�ذѶ�Ӧ�±������Ԫ�ظ�Ϊ1
	p=gra.ptr[choice].next;
	while(p!=0)
	{
		if(flag[p->num]==0)
			Dsrch(gra,flag,p->num);
		p=p->next;
	}
	return 1;
}
int DFS(Graphics gra)
{
	int i=0,*flag,choice;//flagΪ�������
	printf("���뿪ʼ�����ĵ�����:\n");
	while(1)
	{
		scanf("%d",&choice);
		if(choice>=1&&choice<=gra.nodes)
			break;
		else
			printf("����������������������!\n");
	}
	flag=(int *)malloc(sizeof(int)*gra.nodes);//����̶����ڴ��flag
	for(i=0;i<gra.nodes;i++)//��ʼ��flag
		flag[i]=0;
	Dsrch(gra,flag,choice-1);
	for(i=0;i<gra.nodes;i++)
		if(flag[i]==0)//���flag��Ԫ��ֵΪ0����ִ�з���
			Dsrch(gra,flag,i);
		getch();
		system("cls");
		return 1;
}
/*�����������*/
int BFS(Graphics gra)
{
	int choice,*flag,out,i;
	Queue s;Link *p;
	s.front=s.rear=0;//��ʼ������
	flag=(int *)malloc(sizeof(int)*gra.nodes);
	for(i=0;i<gra.nodes;i++)
		flag[i]=0;
	printf("���뿪ʼ�����ĵ�����:\n");
	/*��֤����ȷ��Χ����*/
	while(1)
	{
		scanf("%d",&choice);
		if(choice>=1&&choice<=gra.nodes)
			break;
		else
			printf("����������������������!\n");
	}
	s.q[s.rear]=choice-1;//���
	s.rear++;
	while(s.front<s.rear)//���Ӳ�Ϊ��ʱ��ִ��ѭ��
	{
		out=s.q[s.front];flag[out]=1;//����
		if(flag[out]==1)//�˺���������flag��־������Ƿ��Ѿ������
			printf("%3c",gra.ptr[out].ch);
		p=gra.ptr[out].next;
		s.front++;
		/*���㲻Ϊ�գ���Ӧ��flag��Ԫ��Ϊ0ʱ��Ԫ�����*/
		while(p!=NULL)
		{
			if(flag[p->num]==0)
			{
				s.q[s.rear]=p->num;
				s.rear++;
				flag[p->num]=1;
			}
			p=p->next;
		}	
	}
	for(i=0;i<gra.nodes;i++)
		if(flag[i]==0)
			printf("%3c",gra.ptr[i].ch);
	getch();	
	system("cls");
	return 1;
}
void main()
{
	Graphics gra;
	Link *p;
	int i,choice;
	CreatPtr(&gra);//����ͼ
	system("cls");
	while(1)
	{
		printf("----------------------------\n1.�����������  2.�����������  3.�˳�\n----------------------------\n");
		printf("�ڽӱ�Ĵ洢�ṹΪ:\n");
		printf("****************************************");
		/*����ڽӱ�*/
		for(i=0;i<gra.nodes;i++)
		{
			printf("\n%c",(gra.ptr+i)->ch);
			p=(gra.ptr+i)->next;
			while(p!=0)
			{
				printf("->%d",p->num+1);
				p=p->next;
			}
		}
		printf("\n****************************************\n");
		scanf("%d",&choice);
		while(choice>3||choice<1)
		{
			printf("������Ĳ��Ϸ�������������!\n");
			scanf("%d",&choice);
		}
		if(choice==1)
			DFS(gra);//�������
		if(choice==2)
			BFS(gra);//�������
		if(choice==3) break;
	}
	
}