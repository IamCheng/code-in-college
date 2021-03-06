#include<stdio.h>
const int maxn = 10;
int map[maxn][maxn], dp[maxn][maxn][maxn][maxn];
#define max(a, b) (a > b ? a : b)
int main()
{
	int n, x, y, w;
	scanf("%d", &n);
	while(scanf("%d%d%d", &x, &y, &w) == 3 && x && y && w)
	{
		map[x][y] = w;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				for(int l = 1; l <= n; l++)
				{
					int & tmp = dp[i][j][k][l];
					int p = max(max(dp[i-1][j][k-1][l], dp[i-1][j][k][l-1]), max(dp[i][j-1][k-1][l], dp[i][j-1][k][l-1]));
					tmp += (i == k && j == l) ? (p + map[i][j]) : (p + map[i][j] + map[k][l]);
				}
			}
		}
	}
	printf("%d\n", dp[n][n][n][n]);
	return 0;
}