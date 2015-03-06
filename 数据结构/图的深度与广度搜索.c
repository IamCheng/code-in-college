#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define Max 50
typedef struct Link1
{
	int num;
	struct Link1 *next;
}Link;//表结点结构
typedef struct Head1
{
	char ch;
	Link *next;
}Head;//顶点结点结构
typedef struct Graph
{
	Head *ptr;
	int lines;
	int nodes;
}Graphics;//图的结构
typedef struct queue
{
	int q[Max];
	int front;
	int rear;
}Queue;//队列的结构
int Same(Graphics gra,int i)//判断输入结点标志是否相同
{
	int j=0;
	while(j<i)
		if(gra.ptr[j++].ch==gra.ptr[i].ch)
			return 1;
	return 0;
		
}
/*创建图的邻接表储存*/
int CreatPtr(Graphics *gra)
{
	int i=0,num1,num2;char ch[3];
	Link *p=NULL;
	printf("输入结点的个数：\n");
	scanf("%d",&gra->nodes);
	printf("输入各个结点的标记:\n");
	gra->ptr=(Head*)malloc(gra->nodes*sizeof(Head));
	/*输入各个顶点的标志*/
	while(i<=gra->nodes-1)
	{
		(gra->ptr+i)->ch=getch();
		(gra->ptr+i)->next=NULL;
		/*判断输入标志的ASC码是不是在33~126之间，并且与已输入的字符是否相同*/
		while((gra->ptr+i)->ch>126||(gra->ptr+i)->ch<33||Same(*gra,i))
			(gra->ptr+i)->ch=getch();
		putch((gra->ptr+i)->ch);
		i++;
	}
	if(gra->nodes==1)
		gra->lines=0;//如果只有一个点，直接让边数为0
	else
	{
		printf("\n输入要输入的边数:\n");
		scanf("%d",&gra->lines);
		while(gra->lines<0||gra->lines>gra->nodes*(gra->nodes-1)/2)//判断边数是否在可行范围
		{
			printf("边数的范围为:%d~%d之间!",0,gra->nodes*(gra->nodes-1)/2);
			scanf("%d",&gra->lines);
		}
	}
	/*建立邻接表*/
	for(i=0;i<gra->lines;i++)
	{
		printf("输入第%d条边(a b)",i+1);
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
/*深度优先搜索*/
int Dsrch(Graphics gra,int *flag,int choice)
{
	Link *p;
	printf("%3c",gra.ptr[choice].ch);
	flag[choice]=1;//flag为标记数组，访问过的元素把对应下标的数组元素改为1
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
	int i=0,*flag,choice;//flag为标记数组
	printf("输入开始搜索的点的序号:\n");
	while(1)
	{
		scanf("%d",&choice);
		if(choice>=1&&choice<=gra.nodes)
			break;
		else
			printf("您的输入有误，请重新输入!\n");
	}
	flag=(int *)malloc(sizeof(int)*gra.nodes);//分配固定的内存给flag
	for(i=0;i<gra.nodes;i++)//初始化flag
		flag[i]=0;
	Dsrch(gra,flag,choice-1);
	for(i=0;i<gra.nodes;i++)
		if(flag[i]==0)//如果flag的元素值为0，则执行访问
			Dsrch(gra,flag,i);
		getch();
		system("cls");
		return 1;
}
/*广度优先搜索*/
int BFS(Graphics gra)
{
	int choice,*flag,out,i;
	Queue s;Link *p;
	s.front=s.rear=0;//初始化队列
	flag=(int *)malloc(sizeof(int)*gra.nodes);
	for(i=0;i<gra.nodes;i++)
		flag[i]=0;
	printf("输入开始搜索的点的序号:\n");
	/*保证在正确范围输入*/
	while(1)
	{
		scanf("%d",&choice);
		if(choice>=1&&choice<=gra.nodes)
			break;
		else
			printf("您的输入有误，请重新输入!\n");
	}
	s.q[s.rear]=choice-1;//入队
	s.rear++;
	while(s.front<s.rear)//当队不为空时，执行循环
	{
		out=s.q[s.front];flag[out]=1;//出队
		if(flag[out]==1)//此函数的数组flag标志顶结点是否已经入过队
			printf("%3c",gra.ptr[out].ch);
		p=gra.ptr[out].next;
		s.front++;
		/*表结点不为空，对应的flag的元素为0时，元素入队*/
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
	CreatPtr(&gra);//创建图
	system("cls");
	while(1)
	{
		printf("----------------------------\n1.深度优先搜索  2.广度优先搜索  3.退出\n----------------------------\n");
		printf("邻接表的存储结构为:\n");
		printf("****************************************");
		/*输出邻接表*/
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
			printf("您输入的不合法，请重新输入!\n");
			scanf("%d",&choice);
		}
		if(choice==1)
			DFS(gra);//深度搜索
		if(choice==2)
			BFS(gra);//广度搜索
		if(choice==3) break;
	}
	
}