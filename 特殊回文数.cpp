#include<stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	for(i = 1; i <= 9; i++)
	{
		for(int j = 0; j <=9; j++)
		{
			int tmp = n - (i + j) * 2;
			if(tmp > 9 || tmp < 0)
				continue;
			printf("%d%d%d%d%d\n", i, j, tmp, j, i);
		}
	}
	for(i = 1; i <= 9; i++)
	{
		for(int j = 0; j <=9; j++)
		{
			int tmp = n - (i + j) * 2;
			if(tmp > 18 || tmp % 2 != 0 || tmp < 0)
				continue;
			printf("%d%d%d%d%d%d\n", i, j, tmp/2, tmp/2, j, i);
		}
	}
	return 0;
}