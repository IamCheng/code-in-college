#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define MAX_THREAD_COUNT 1000//最大进程数

HANDLE Mutex;
HANDLE feMutexp;
HANDLE feMutexc;
HANDLE full;
HANDLE empty;
HANDLE hThread[MAX_THREAD_COUNT];
int handle_count=0;//操作次数
int product_id=1;
int max_store=10;   //仓库最大量
int producer_count=10;  //生产数量
int consumer_count=10;  //消费数量
int producer_num=2;   //生产者数量
int consumer_num=2;  //消费者数量
long producer_wait_time=5;  //生产者等待时间
long consumer_wait_time=5;  //消费者等待的时间
struct timeb tp;
struct tm *ptr;
int store=0; //共享资源

struct Goods{
	int id;
	int producer_id;
}Goods[10];

long Rand()
{
	srand((int)time(NULL));
	return rand()%100;
}

void WINAPI producer(int id)
{
	int i;
	for(i=0;i<producer_count;i++)
	{
		WaitForSingleObject(full,INFINITE);
		Sleep(Rand()*producer_wait_time);
		WaitForSingleObject(Mutex,INFINITE);
		Goods[store].id=product_id;
		Goods[store].producer_id=id;
		store++;
		product_id++;
		handle_count++;
		ftime(&tp);
		ptr=localtime(&(tp.time));
		printf("操作次数：%d  ",handle_count);
        printf("生产者%d生产编号%d的产品，仓库产品数：%d\n\n",id,Goods[store-1].id,store);
		
		ReleaseMutex(Mutex);
		ReleaseSemaphore(empty,1,NULL);
		Sleep(500);
	}
	product_id=1;
}

void WINAPI Consumer(int id)
{
	int i;
	for(i=0;i<consumer_count;i++)
	{
		WaitForSingleObject(empty,INFINITE);
		
		Sleep(Rand()*consumer_wait_time);
		
		WaitForSingleObject(Mutex,INFINITE);
		store--;
		handle_count++;
		ftime(&tp);
		ptr=localtime(&(tp.time));
		printf("操作次数：%d  ",handle_count);
		printf("消费者%d消费编号%d的产品，仓库产品数：%d\n\n",id,Goods[store].id,store);
		
		ReleaseMutex(Mutex);
		ReleaseSemaphore(full,1,NULL);
		Sleep(800);
	}
}

void WINAPI run()
{
	int i;
	Mutex=CreateMutex(NULL,FALSE,NULL);
	full=CreateSemaphore(NULL,max_store,max_store,NULL);
	empty=CreateSemaphore(NULL,0,max_store,NULL);
	WaitForSingleObject(Mutex,INFINITE);
	printf("***创建生产者和消费者线程***\n");
	for(i=1;i<=producer_num;i++)
	{
		hThread[i-1]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,(void *)i,0,NULL);
		if(hThread[i-1]!=0)
		{
			ftime(&tp);
			ptr=localtime(&(tp.time));
			printf("%d号生产者线程已创建\n",i);
		}
	}
	for(i=1;i<=consumer_num;i++)
	{
		hThread[i-1+producer_num]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Consumer,(void *)i,0,NULL);
		if(hThread[i]!=0)
		{
			ftime(&tp);
			ptr=localtime(&(tp.time));
			printf("%d号消费者线程已创建\n",i);
		}
	}
	printf("\n");
	printf("*********生产和消费过程**********\n");
	
	ReleaseMutex(Mutex);
	//WaitForMultipleObjects(producer_num+producer_num,hThread,TRUE,INFINITE);
}
void menu()
{
	
	printf("\t     回回回回回回回回生产者与消费者进程调度回回回回回回回回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回      ------------选择菜单------------------      回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回      1、查看初始值             2、运      行     回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回      3、修改 参 数             4、退      出     回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回回回回回回回回回回回回回回回回回回回回回回回回回回回\n");
	
}
void show()
{
	printf("*****初始化信息******\n");
	printf("仓库最大量为：%d\n",max_store);
	printf("生产者数量为：%d\n",producer_num);
	printf("消费者数量:%d\n",consumer_num);
	printf("生产数量：%d\n",producer_count);
	printf("消费数量：%d\n",consumer_count);
	printf("生产等待时间基数：%d\n",producer_wait_time);
    printf("消费等待时间基数：%d\n",consumer_wait_time);
    printf("\n");
}

int valueChange()
{
	int choice;
	char ch;
	printf("\t-++++++++++************修改参数***********+++++++++++++-\n");
	printf("\t1.生产者数量   2.消费者数量   3.生产数量     4.消费数量\n\n");
	printf("\t5.生产等待时间基数    6.消费等待时间基数     7.仓库最大数 \n");
	printf("\t-++++++++++*********************************++++++++++++-\n");
	
	while(1)
	{
		printf("请选择修改对象：");
		scanf("%d",&choice);
		if( choice>7||choice < 1)
		{
			printf("输入有误!\n");
			return 0;
		}
		printf("输入修改后的值:\n");
		switch(choice)
		{
			case 1:
				scanf("%d",&producer_num);
				break;
			case 2:
				scanf("%d",&consumer_num);
				break;
			case 3:
				scanf("%d",&producer_count);
				break;
			case 4:
				scanf("%d",&consumer_count);
				break;
			case 5:
				scanf("%d",&producer_wait_time);
				break;
			case 6:
				scanf("%d",&consumer_wait_time);
				break;
			case 7:
				scanf("%d",&max_store);
				break;
		}
		fflush(stdin);
		printf("是否继续修改(Y|N)\n");
		ch = getch();
		if( 'y' != ch&&'Y' != ch)
			return 1;
	}
	
}
void main()
{
	int a;
	while(1)
	{
		menu();//菜单
		printf("请选择：");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("初始值为：\n");
				show();
				break;
			case 2:
				show();
				run();
				handle_count=0;
				break;
			case 3:
				valueChange();
				break;
			case 4:exit(0);
			default:printf("输入有误!\n");
		}
		system("pause");
		system("cls");
	}
}




