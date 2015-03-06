#include<stdio.h>
#include<string.h>
#define max(a, b) (a > b ? a : b)
const int maxn = 110;
int v[maxn], w[maxn], q[maxn];
int dp[maxn][maxn], h[maxn];
int main()
{
	int V, n, i, j, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &V, &n);
		memset(h, 0, sizeof(h));
		memset(dp, 0, sizeof(dp));
		for(i = 1; i <= n; i++)
			scanf("%d%d%d", &v[i], &w[i], &q[i]);
		for(i = 1; i <= n; i++)
		{
			memset(h, 0, sizeof(h));
			for(j = 1; j <= V; j++)
			{
				if(j < v[i])
				{
					dp[i][j] = dp[i-1][j];
					continue;
				}
				if(dp[i-1][j] < dp[i][j-v[i]] + w[i])
				{
					if(h[j-v[i]] + 1 <= q[i])
					{
						dp[i][j] = dp[i][j-v[i]] + w[i];
						h[j] = h[j-v[i]] + 1;
					}
					else
					{
						dp[i][j] = dp[i-1][j];
						for(int k = 1; k <= q[i]; k++)
							dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]] + k * w[i]);
						h[j] = k;			
					}
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		printf("%d\n", dp[n][V]);
	}
	return 0;
}
