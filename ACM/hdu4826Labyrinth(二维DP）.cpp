#include<stdio.h>
const int maxn = 101;
int map[maxn][maxn], dp[maxn][maxn];
int sum[maxn][maxn];
int max(int a, int b)
{
	return a > b ? a : b;
} 
int main()
{
	int m, n, i, j, k, t, T;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{		
		scanf("%d%d", &m, &n);
		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
			{			
				scanf("%d", &map[i][j]);
				sum[i][j] = sum[i-1][j] + map[i][j];
			}
		dp[1][1] = map[1][1];
		for(i = 1; i <= m; i++)
			dp[i][1] = sum[i][1];
		for(j = 2; j <= n; j++)
			for(i = 1; i <= m; i++)
			{
				dp[i][j] = dp[i][j-1] + map[i][j];
				for(k = m; k > i; k--)
				{
					int tmp = sum[k][j] - sum[i-1][j] + dp[k][j-1];					
					dp[i][j] = max(dp[i][j], tmp);
				}
				for(k = 1; k < i; k++)
				{
					int tmp = sum[i][j] - sum[k-1][j] + dp[k][j-1];
					dp[i][j] = max(dp[i][j], tmp);
				}
			}
		printf("Case #%d:\n%d\n", t, dp[1][n]);//Case #2
	}
	return 0;
}
/*
3 4
1 2 3 4
5 6 7 -100
8 9 10 -1000
*/