#include<stdio.h>
#include<string.h>
const int maxn = 100100;
int v[110], q[110];
int dp[2][maxn],h[maxn];
int main()
{
	int V, n, i;
	while(scanf("%d%d", &n, &V) == 2 && (n || V))
	{
		memset(dp, 0, sizeof(dp));
		for(i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for(i = 1; i <= n; i++)
			scanf("%d", &q[i]);
		for(i = 1; i <= n; i++)
		{
			int next = i % 2, before = (i + 1) % 2;
			memset(h, 0, sizeof(h));
			for(int j = 1; j <= V; j++)
			{				
				if(j < v[i])
				{
					dp[next][j] = dp[before][j];
					continue;
				}
				if(j - v[i] < 0)
				{
					printf("yuejie!\ni = %d j = %d\n");
					return 0;
				}
				if(dp[before][j] < dp[next][j-v[i]] + v[i])
				{
					if(h[j-v[i]] + 1 <= q[i])
					{
						dp[next][j] = dp[next][j-v[i]] + v[i];
						h[j] = h[j-v[i]] + 1;
					}
					else
					{
						int  k, tmp = 0;
						dp[next][j] = dp[before][j];
						for(k = 1; k <= q[i]; k++)
						{
							if(dp[next][j] < dp[before][j-k*v[i]] + k * v[i])
							{
								tmp = k;
								dp[next][j] = dp[before][j-k*v[i]] + k * v[i];
							}
						}
						h[j] = tmp;			
					}
				}
				else
					dp[next][j] = dp[before][j];
			}
		}
		int ans = 0;
		for(i = 1; i <= V; i++)
			if(dp[1][i] == i)	ans++;
		printf("%d\n", ans);
	}
	return 0;
}
