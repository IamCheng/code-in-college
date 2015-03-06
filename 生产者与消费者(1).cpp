#include<stdlib.h>
#include<time.h>
#include<sys/timeb.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

#define MAX_THREAD_COUNT 1000//��������

HANDLE Mutex;
HANDLE feMutexp;
HANDLE feMutexc;
HANDLE full;
HANDLE empty;
HANDLE hThread[MAX_THREAD_COUNT];
int handle_count=0;//��������
int product_id=1;
int max_store=10;   //�ֿ������

int producer_num = 1;   //����������
int consumer_num = 1;  //����������
int sum_count = 4;//��������
long producer_wait_time=5;  //�����ߵȴ�ʱ��
long consumer_wait_time=5;  //�����ߵȴ���ʱ��
struct timeb tp;
struct tm *ptr;
int store=0; //������Դ
volatile int tmp = 0;
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
	printf("����������%d  ",handle_count);
	printf("������%d�������%d�Ĳ�Ʒ���ֿ��Ʒ����%d\n\n",id,Goods[store-1].id,store);
	
	ReleaseMutex(Mutex);
	ReleaseSemaphore(empty,1,NULL);
	Sleep(500);
	product_id=1;
	tmp++;
	if(tmp <  sum_count*2)
		producer(id);
	
}

void WINAPI Consumer(int id)
{
	WaitForSingleObject(empty,INFINITE);
	
	Sleep(Rand()*consumer_wait_time);
	
	WaitForSingleObject(Mutex,INFINITE);
	store--;
	handle_count++;
	ftime(&tp);
	ptr=localtime(&(tp.time));
	printf("����������%d  ",handle_count);
	printf("������%d���ѱ��%d�Ĳ�Ʒ���ֿ��Ʒ����%d\n\n",id,Goods[store].id,store);
	
	ReleaseMutex(Mutex);
	ReleaseSemaphore(full,1,NULL);
	Sleep(800);
	tmp ++ ;
	if(tmp < 2*sum_count )
		Consumer(id) ;
	
}

void WINAPI run()
{
	int i;
	Mutex=CreateMutex(NULL,FALSE,NULL);
	full=CreateSemaphore(NULL,max_store,max_store,NULL);
	empty=CreateSemaphore(NULL,0,max_store,NULL);
	WaitForSingleObject(Mutex,INFINITE);
	printf("***���������ߺ��������߳�***\n");
	for(i=1;i<=producer_num;i++)
	{
		hThread[i-1]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)producer,(void *)i,0,NULL);
		if(hThread[i-1]!=0)
		{
			ftime(&tp);
			ptr=localtime(&(tp.time));
			printf("%d���������߳��Ѵ���\n",i);
		}
	}
	for(i=1;i<=consumer_num;i++)
	{
		hThread[i-1+producer_num]=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)Consumer,(void *)i,0,NULL);
		if(hThread[i]!=0)
		{
			ftime(&tp);
			ptr=localtime(&(tp.time));
			printf("%d���������߳��Ѵ���\n",i);
		}
	}
	printf("\n");
	printf("*********���������ѹ���**********\n");
	ReleaseMutex(Mutex);
	//WaitForMultipleObjects(producer_num+producer_num,hThread,TRUE,INFINITE);
}
void menu()
{
	
	printf("\t     �ػػػػػػػ��������������߽��̵��Ȼػػػػػػػ�\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��      ------------ѡ��˵�------------------      ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��      1���鿴��ʼֵ             2����      ��     ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��      3���޸� �� ��             4����      ��     ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     �ػػػػػػػػػػػػػػػػػػػػػػػػػػ�\n");
	
}
void show()
{
	printf("*****��ʼ����Ϣ******\n");
	printf("�ֿ������Ϊ��%d\n",max_store);
	printf("��������Ϊ:%d\n",consumer_num);
	printf("����������Ϊ��%d\n",producer_num);
	printf("����������%d\n",sum_count);
	printf("�����ȴ�ʱ�������%d\n",producer_wait_time);
    printf("���ѵȴ�ʱ�������%d\n",consumer_wait_time);
    printf("\n");
}

int valueChange()
{
	int choice;
	char ch;
	printf("\t-++++++++++************�޸Ĳ���***********+++++++++++++-\n");
	printf("\t1.����������   2.����������   3.����������     \n");
	printf("\t5.�����ȴ�ʱ�����    6.���ѵȴ�ʱ�����     7.�ֿ������ \n");
	printf("\t-++++++++++*********************************++++++++++++-\n");
	
	while(1)
	{
		printf("��ѡ���޸Ķ���");
		scanf("%d",&choice);
		if( choice>7||choice < 1)
		{
			printf("��������!\n");
			return 0;
		}
		printf("�����޸ĺ��ֵ:\n");
		switch(choice)
		{
		case 1:
			scanf("%d",&producer_num);
			break;
		case 2:
			scanf("%d",&consumer_num);
			break;
		case 3:
			scanf("%d",&sum_count);
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
		printf("�Ƿ�����޸�(Y|N)\n");
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
		menu();//�˵�
		printf("��ѡ��");
		scanf("%d",&a);
		switch(a)
		{
		case 1:
			printf("��ʼֵΪ��\n");
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
		default:printf("��������!\n");
		}
		system("pause");
		system("cls");
	}
}




