#include<stdio.h>
int main()
{
	for(int i = 1; i <= 9; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			for(int k = 0; k <= 9; k++)
			{
				int l = i * j / 10;
				int r = i * j % 10;
				printf("%d%d%d%d%d\n", i, j, k, l, r);
			}
		}
	}
	return 0;
}
