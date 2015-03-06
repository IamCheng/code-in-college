#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>
typedef struct userprocess
{
	char name[20];
	int num;
	int chart[100];
}user;
int flag[100], N,m = 100,f;
user u[100];
//初始化函数（删除时亦调用此函数）
int initial()
{	
	int i,j;
	memset(u,-1,sizeof(u));
	memset(flag,0,sizeof(flag));
	N = 0;
	m = 100;
	srand(time(NULL));
	i = rand() % 11 + 10;//模拟系统占用内存的数量
	m -= i;
	while(i--)
		while(1)
		{
			j = rand() % 100;
			if(0 == flag[j])
			{
				flag[j] = 1;
				break;
			}
		}
	if(0 == f)
		printf("系统程序占用%d,可用内存为%d\n系统启动中\n",100-m,m);
	else
		printf("正在清理全部全部内存\n");
	for(i = 0;i < 10;i++)
	{
		printf(".");
		Sleep(300);
	}
	return 1;
}
/*创建进程*/
int creat()
{
	int i = 0,j = 0;
	printf("输入进程的名称:\n");
	scanf("%s",u[N].name);
	printf("输入页数:\n");
	scanf("%d",&u[N].num);
	if(0 > m - u[N].num)
	{
		printf("分配失败，没有足够的内存!\n");
		return 0;
	}
	N++;
	//指定进程的块
	i = u[N-1].num;
	while(i > 0)
		if(0 == flag[j++])
		{
			flag[j-1] = 1;
			u[N-1].chart[u[N-1].num - i] = j-1; 
			i--;
		}
	m -= u[N-1].num;
	fflush(stdin);
	printf("是否继续添加进程(y|n)");
	if(getchar() == 'y')
		creat();
	return 1;
}
int show_procedure()
{
	int i,j ;
	printf("用户进程：  页表数：    对应块号: \n");
	for(i = 0; i < N; i++)
	{
		printf("%-10s  %-11d",u[i].name,u[i].num);
		for(j = 0; j < u[i].num; j++)
		{	
			printf(" %-2d",u[i].chart[j]);
			if( (j+1)%18 == 0)
				printf("\n\t\t       ");	
		}
		printf("\n");
	}
	return 1;
}
int show_memory()
{
	int i;
	for(i = 0; i < 100; i++)
	{
		printf("%4d",flag[i]);
		if( (i+1)%10 == 0)
			printf("\n");
	
	}
	return 1;
}
/*回收内存的函数*/
int recycle()
{
	int i;
	char name[20];
	printf(" 1、要回收全部进程 2、回收指定的用户程序的内存\n");
	while(1)
	{
		scanf("%d",&i);
		if(i>=1&&i<=2)
			break;
		else
			printf("输入有误!\n");
	}
	if(1 == i)
	{
		show_procedure();
		f = 1;
		initial();
	
	}
	if(2 == i)
	{
		printf("输入要回收内存的进程:\n");
		scanf("%s",name);
		for(i = 0;i < N; i++)
		{
			if(strcmp(name,u[i].name) == 0)//查找回收指定的用户进程
			{
				for(int j = 0; j < u[i].num; j++)
				{
					flag[u[i].chart[j]] = 0;
					m++;
				}
				for(j = i;j < N; j++)
					u[j] = u[j+1];
				N--; 
				break;
			}
		}
		for(i = 0;i < 5;i++)
		{
			printf(".");
			Sleep(200);
		}
	}
	printf("收回完毕！\n");
	return 1;
}
void manu()
{
	printf("\n");
	printf("\t     回回回回回回回回回回回回回回回回回回回回回回回回回回回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                   基本的分页算法                 回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    1、创建进程                   回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    2、回收进程                   回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    3、进程占用情况               回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    4、内存使用情况               回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    0、安全退出                   回\n");	
	printf("\t     回                                                  回\n");
	printf("\t     回            备注：输入对应序号进入选项            回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回回回回回回回回回回回回回回回回回回回回回回回回回回回\n");
	printf("                                        \n");
	printf("                                   \t\t\tⅤ⑤☆0.1版☆by程鑫\n");
	printf("                                        \n");
}
int main()
{
	int choice;
	initial();//初始化
	//以菜单的形式显示出来
	while(1)
	{	
		system("cls");//清屏	
		manu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:creat();break;
		case 2:recycle();break;
		case 3:show_procedure();break;
		case 4:show_memory();break;
		case 0:exit(0);
		default:printf("您的输入有误，请重新输入\n");
		}
		system("pause");
	
	}
	return 0;
}