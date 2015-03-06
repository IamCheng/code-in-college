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
//��ʼ��������ɾ��ʱ����ô˺�����
int initial()
{	
	int i,j;
	memset(u,-1,sizeof(u));
	memset(flag,0,sizeof(flag));
	N = 0;
	m = 100;
	srand(time(NULL));
	i = rand() % 11 + 10;//ģ��ϵͳռ���ڴ������
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
		printf("ϵͳ����ռ��%d,�����ڴ�Ϊ%d\nϵͳ������\n",100-m,m);
	else
		printf("��������ȫ��ȫ���ڴ�\n");
	for(i = 0;i < 10;i++)
	{
		printf(".");
		Sleep(300);
	}
	return 1;
}
/*��������*/
int creat()
{
	int i = 0,j = 0;
	printf("������̵�����:\n");
	scanf("%s",u[N].name);
	printf("����ҳ��:\n");
	scanf("%d",&u[N].num);
	if(0 > m - u[N].num)
	{
		printf("����ʧ�ܣ�û���㹻���ڴ�!\n");
		return 0;
	}
	N++;
	//ָ�����̵Ŀ�
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
	printf("�Ƿ������ӽ���(y|n)");
	if(getchar() == 'y')
		creat();
	return 1;
}
int show_procedure()
{
	int i,j ;
	printf("�û����̣�  ҳ������    ��Ӧ���: \n");
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
/*�����ڴ�ĺ���*/
int recycle()
{
	int i;
	char name[20];
	printf(" 1��Ҫ����ȫ������ 2������ָ�����û�������ڴ�\n");
	while(1)
	{
		scanf("%d",&i);
		if(i>=1&&i<=2)
			break;
		else
			printf("��������!\n");
	}
	if(1 == i)
	{
		show_procedure();
		f = 1;
		initial();
	
	}
	if(2 == i)
	{
		printf("����Ҫ�����ڴ�Ľ���:\n");
		scanf("%s",name);
		for(i = 0;i < N; i++)
		{
			if(strcmp(name,u[i].name) == 0)//���һ���ָ�����û�����
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
	printf("�ջ���ϣ�\n");
	return 1;
}
void manu()
{
	printf("\n");
	printf("\t     �ػػػػػػػػػػػػػػػػػػػػػػػػػػ�\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                   �����ķ�ҳ�㷨                 ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    1����������                   ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    2�����ս���                   ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    3������ռ�����               ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    4���ڴ�ʹ�����               ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    0����ȫ�˳�                   ��\n");	
	printf("\t     ��                                                  ��\n");
	printf("\t     ��            ��ע�������Ӧ��Ž���ѡ��            ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     �ػػػػػػػػػػػػػػػػػػػػػػػػػػ�\n");
	printf("                                        \n");
	printf("                                   \t\t\t���ݡ�0.1���by����\n");
	printf("                                        \n");
}
int main()
{
	int choice;
	initial();//��ʼ��
	//�Բ˵�����ʽ��ʾ����
	while(1)
	{	
		system("cls");//����	
		manu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:creat();break;
		case 2:recycle();break;
		case 3:show_procedure();break;
		case 4:show_memory();break;
		case 0:exit(0);
		default:printf("����������������������\n");
		}
		system("pause");
	
	}
	return 0;
}