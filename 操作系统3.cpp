#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int num[100],N,yk;//yk����ҳ�� N������� num���N����
char q[10],tmp[100][100];//tmp������ݵĻ�������q����	
int Produce_Num()//�������뺯������������Զ��壩
{
	int chs,i;
	printf("1��ʹ���������    2�� ʹ���Զ�������\n");
	scanf("%d",&chs);
	switch(chs)
	{
	case 1:
		N = 20;
		srand(time(NULL));
		for(i = 0; i < 20; i++)
			num[i] = rand() % 14 ;
		yk = 3;
		break;
	case 2:
		printf("����ҳ������\n");
		scanf("%d",&yk);
		printf("���������\n");
		scanf("%d", &N);
		printf("�����������:\n");
		for(i = 0; i < N; i++)
			scanf("%d", &num[i]);
		break;
	}
	for(i = 0;i < N;i++)
		printf("%d ",num[i]);
	for(i = 0;i < N;i++)
		if( num[i] == 0)//������Ϊ0��ҳ������Ϊ100�������ַ����ĸ�ֵ
			num[i] = 100;
	printf("\n\n");
	return 1;
}
/*�������*/
int print(int n)
{
	int i,j;
	for(i = 1 ;i <= yk; i++)
	{
		for(j = 0;j < n; j++)
		{
			if(tmp[j][i] == 0)
				printf("|   ");
			else
			{
				if(tmp[j][i] == 100)
					printf("|%3d",0);
				else
					printf("|%3d",tmp[j][i]);
			}
		}
		printf("|\n");
	}
	printf("ȱҳ�Ĵ���Ϊ��%d\nȱҳ��Ϊ:%.2f\n",n-yk,(float)(n-yk)/N);
	return 1;
}
/*�Ƚ��ȳ��㷨*/
int FIFO()
{
	int i,j,k,flag,n = 0;
	Produce_Num();
	memset(q, 0, sizeof(q));
	for(i = 0; i < N; )
	{
		for(j = 0; j < yk; )
		{
			flag = 0;
			for(k = 0; k < yk; k++)
				if(q[k] == num[i])
				{
					flag = 1;
					break;
				}
			if(flag != 1)
			{
				q[j] = num[i] ;
				j++;
				strcpy(tmp[n++]+1,q);
			}
			i++;
			if(i >= N)
				break;
		}
	}
	print(n);
	return 1;
}
int find_max(int qz[])//����ֵΪȨֵ�����������
{
	int i,max = -1,index;
	for(i = yk-1; i >=0; i--)
		if(qz[i] >= max)
		{
			max = qz[i];
			index = i;
		}
		return index;
}
int LRU()//�������ʹ���㷨
{
	int qz[10],n = 0,i,flag,k;
	memset(qz,3,sizeof(qz));
	memset(q, 0, sizeof(q));
	Produce_Num();
	for(i = 0; i<N; i++)
	{
		flag = -1;
		for(k = 0; k < yk; k++)
			if(q[k] == num[i])
			{
				flag = k;
				break;
			}	
			for(k = yk-1; k >= 0; k--)
			{
				if(k != flag)
					qz[k]++;
			}
			if(flag != -1)
				qz[flag] = 0;
			else
			{
				k = find_max(qz);
				q[k] = num[i];
				qz[k] = 0;
				strcpy(tmp[n++]+1, q);
			}
		
			
	}
	print(n);
	return 1;
}
int farest(int p)//������Զ����
{
	int i,j,max = -1,m;
	for(i = yk-1 ; i >= 0; i--)
	{
		for(j = p; j < N; j++)
		{
			if( q[i] == num[j])
			{
				if(j > max)
				{
					max = j;
					m = i;
				}
				break;
			}
		}
		if( j == N ) { m = i;max = 10000;}
	}
	return m;
}
int copy(int n)
{
	for(int i = 1; i <= tmp[n-1][0]; i++)
		tmp[n-1][i] = q[i-1];
	return 1;
}
//���ת���㷨
int Optimal()
{
	int n = 0,i,k,flag,count = 0;
	memset(q, 0, sizeof(q));
	Produce_Num();
	for(i = 0; i < N; )
	{
		flag = 0;
		for(k = 0; k < yk; k++)
			if(q[k] == num[i])
			{
				flag = 1;
				break;
			}
		if(flag !=1 && count >= yk)
		{
			flag = farest(i);	//����Ҫ�滻�����������±�	
			q[flag] = num[i];	//�滻�����е�����
			tmp[n++][0] = yk;	//tmp[i][0]��Ÿ���
			strcpy(tmp[n-1]+1, q);
		}	
		if(flag != 1 && count < yk)
		{
			q[count++] = num[i];
			tmp[n++][0] =count;
			strcpy(tmp[n-1]+1, q);
		}
		i++;
	}	
	print(n);
	return 1;
	
}
void manu()
{
	printf("\n");
	printf("\t     �ػػػػػػػػػػػػػػػػػػػػػػػػػػ�\n");
	printf("\t     ��             ��                        ��         ��\n");
	printf("\t     ��             ��      ҳ���û��㷨      ��         ��\n");
	printf("\t     ��             ��                        ��         ��\n");
	printf("\t     ��             ���������������         ��\n");		
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    1��FIFO�㷨                   ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    2��LRU�㷨                    ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    3��Optimal�㷨                ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     ��                    0����ȫ�˳�                   ��\n");	
	printf("\t     ��                                                  ��\n");
	printf("\t     ��            ��ע�������Ӧ��Ž���ѡ��            ��\n");
	printf("\t     ��                                                  ��\n");
	printf("\t     �ػػػػػػػػػػػػػػػػػػػػػػػػػػ�\n");
	printf("                                        \n");
	printf("                                   \t\t\t���ݡ�1.0���by����\n");
	printf("                                        \n");
}
int main()
{	
	int choice;
	//�Բ˵�����ʽ��ʾ����
	while(1)
	{	
		system("cls");//����	
		manu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:FIFO();break;
		case 2:LRU();break;
		case 3:Optimal();break;
		case 0:exit(0);
		default:printf("����������������������\n");
		}
		system("pause");	
	}
	return 0;
}
