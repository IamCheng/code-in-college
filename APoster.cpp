#include<stdio.h>
char action[][10] = {"LEFT\n", "RIGHT\n", "PRINT %c\n"};
int main()
{
	int n, cnt, end, st, out, flag;
	char ch[110];
	scanf("%d%d", &n, &cnt);
	scanf("%s", ch+1);
	if(cnt - 1 < n - cnt)
	{
		st = 1;
		end = cnt;	
		out = 0;
		flag = 0;
	}
	else
	{
		st = cnt;
		end = n;
		out = 1;
		flag = 1;
	}
	while(st++ < end)	printf(action[out]);
	if(flag == 1)
	{
		for(int i = n; i > 1; i--){		
			printf(action[2], ch[i]);
			printf(action[0]);
		}
		printf(action[2], ch[1]);

	}
	if(flag == 0)
	{
		for(int i = 1; i < n; i++)
		{		
			printf(action[2], ch[i]);
			printf(action[1]);
		}
		printf(action[2], ch[n]);
	}
	return 0;
}