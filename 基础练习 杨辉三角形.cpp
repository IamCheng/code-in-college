#include<stdio.h>
int tb[35][35];
int main()
{
	int n;
	tb[1][1] = 1;
	scanf("%d", &n);
	printf("%d\n", tb[1][1]);
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(j == 1 || i == j)
				tb[i][j] = 1;
			else
				tb[i][j] = tb[i-1][j] + tb[i-1][j-1];
			if(j == 1) 
				printf("%d", tb[i][j]);
			else
				printf(" %d", tb[i][j]);
		
		}
		printf("\n");
	}
	return 0;
}
