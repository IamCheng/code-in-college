#include<stdio.h>
#include<string.h>
const int maxn = 11000;
int vis[maxn];
int num[210];
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		int n, j;
		printf("Case #%d:\n", i);
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		for(j = 1; j <= n; j++)
		{
			int r;
			scanf("%d", &r);
			num[r]++;
		}
		int max = -1;
		for(j = 1; j < 100; j++)
		{
			if(num[j] + num[200-j] > max)
				max = num[j] + num[200-j];
		}
		if(num[100] > max)	max = num[100];
		int flag = 0, f = 0;
		for(j = 1; j < 100; j++)
		{
			if(num[j] + num[200-j] != max && num[j] + num[200-j] != 0)
				f = 1;
			if(num[j] + num[200-j] == max)	flag++;
		}
		if(num[100] == max)	flag++;
		if(num[100] != max && num[100] != 0)	f = 1;;
		if(f == 0 && flag != 1)
		{
			printf("Bad Mushroom\n");
			continue;
		}
		f = 0;
		for(j = 1; j < 100; j++)
		{
			if(num[j] + num[200-j] == max)
			{
				if(f == 0)
				{
					printf("%d", 10000 - (100 - j) * (100 - j));
					f = 1;
				}
				else
				{
					printf(" %d", 10000 - (100 - j) * (100 - j));
				}
			}
		}
		if(num[100] == max)	
		{
			if(f == 0)
				printf("%d", 10000 - (100 - j) * (100 - j));
			else
				printf(" %d", 10000 - (100 - j) * (100 - j));
		}
		printf("\n");
	}
	return 0;
}