#include<stdio.h>
int dp[210][8];
int main()
{
	int n, i, j, k;
	scanf("%d%d", &n, &k);
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= k && i >= j; j++)
		{
			if(j == 1)
			{
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
		}
	}
	printf("%d", dp[n][k]);
	
	return 0;
}
