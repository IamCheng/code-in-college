#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int num[100],N,yk;//yk代表页块 N代表个数 num存放N个数
char q[10],tmp[100][100];//tmp输出数据的缓冲区，q队列	
int Produce_Num()//数字输入函数（随机或者自定义）
{
	int chs,i;
	printf("1、使用随机数字    2、 使用自定义数字\n");
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
		printf("输入页块数：\n");
		scanf("%d",&yk);
		printf("输入个数：\n");
		scanf("%d", &N);
		printf("输入各个数字:\n");
		for(i = 0; i < N; i++)
			scanf("%d", &num[i]);
		break;
	}
	for(i = 0;i < N;i++)
		printf("%d ",num[i]);
	for(i = 0;i < N;i++)
		if( num[i] == 0)//把所有为0的页块数改为100，方面字符串的赋值
			num[i] = 100;
	printf("\n\n");
	return 1;
}
/*输出函数*/
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
	printf("缺页的次数为：%d\n缺页率为:%.2f\n",n-yk,(float)(n-yk)/N);
	return 1;
}
/*先进先出算法*/
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
int find_max(int qz[])//返回值为权值最大数的索引
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
int LRU()//最近最少使用算法
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
int farest(int p)//查找最远的数
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
//最佳转换算法
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
			flag = farest(i);	//返回要替换的数的索引下标	
			q[flag] = num[i];	//替换队列中的数字
			tmp[n++][0] = yk;	//tmp[i][0]存放个数
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
	printf("\t     回回回回回回回回回回回回回回回回回回回回回回回回回回回\n");
	printf("\t     回             ☆                        ☆         回\n");
	printf("\t     回             ☆      页面置换算法      ☆         回\n");
	printf("\t     回             ☆                        ☆         回\n");
	printf("\t     回             ☆☆☆☆☆☆☆☆☆☆☆☆☆☆         回\n");		
	printf("\t     回                                                  回\n");
	printf("\t     回                    1、FIFO算法                   回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    2、LRU算法                    回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    3、Optimal算法                回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回                    0、安全退出                   回\n");	
	printf("\t     回                                                  回\n");
	printf("\t     回            备注：输入对应序号进入选项            回\n");
	printf("\t     回                                                  回\n");
	printf("\t     回回回回回回回回回回回回回回回回回回回回回回回回回回回\n");
	printf("                                        \n");
	printf("                                   \t\t\tⅤ⑤☆1.0版☆by程鑫\n");
	printf("                                        \n");
}
int main()
{	
	int choice;
	//以菜单的形式显示出来
	while(1)
	{	
		system("cls");//清屏	
		manu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:FIFO();break;
		case 2:LRU();break;
		case 3:Optimal();break;
		case 0:exit(0);
		default:printf("您的输入有误，请重新输入\n");
		}
		system("pause");	
	}
	return 0;
}
