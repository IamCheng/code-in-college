#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define max 10000
typedef struct
{
	int num;
	char dr;
	int flag;
}ant;
ant a[max];
int L,t,n;
int turn()
{
	int i;
	for(i = 0; i < n; i++)
		if(a[i].flag == 1)
			a[i].flag = 0;
	for(i = 0; i < n; i++)
		switch(a[i].dr)
		{
			case 'R':a[i].num++;break;
			case 'L':a[i].num--;break;
		}
	for(i = 0; i < n; i++)
	{
		if((a[i].num > L || a[i].num < 0))
			a[i].flag = -1;
		else
		{
			for(int j = i + 1; j < n; j++)
			{
				if(a[j].num == a[i].num && a[i].flag == 0 )
				{
					a[i].flag = 1;
					a[j].flag = 1;
					char tmp = a[i].dr;
					a[i].dr = a[j].dr;
					a[j].dr = tmp;
					break;
				}
			}
		
			
		}

	}
	return 1;
}
int main()
{
	int T,i;
	scanf("%d", &T);
	int m = T;
	while(T--)
	{
		memset(a, 0, sizeof(ant)*max);
		scanf("%d%d%d", &L, &t, &n);
		L = 2 * L;
		t = 2 * t;
		for(i = 0; i < n; i++)
		{
			scanf("%d %c", &a[i].num, &a[i].dr);
			a[i].num = a[i].num * 2;
		}
		for(i = 0; i < t; i++)
			turn();
		printf("Case #%d:\n", m-T);
		for(i = 0; i < n; i++)
			switch(a[i].flag)
			{
				case -1:printf("Fell off\n");break;
				case 1:printf("%d Turning\n", a[i].num/2);break;
				case 0:printf("%d %c\n", a[i].num/2, a[i].dr);
			}
		printf("\n");
	}

	return 0;
}