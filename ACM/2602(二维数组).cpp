#include<stdio.h>
#include<string.h>
const int maxn = 1010;
int c[maxn], w[maxn], f[maxn][maxn];
int main()
{
	int T, i, j;
	scanf("%d", &T);
	while(T--)
	{
		int N, V;
		memset(f, 0, sizeof(f));
		scanf("%d%d", &N, &V);
		for(i = 1; i <= N; i++)
			scanf("%d", &w[i]);
		for(i = 1; i <= N; i++)
			scanf("%d", &c[i]);
		for(i = 1; i <= N; i++)
			for(j = 0; j <= V; j++)
			{
				if(j >= c[i])
					f[i][j] = (f[i-1][j] > f[i-1][j-c[i]] + w[i]) ? f[i-1][j] : f[i-1][j-c[i]] + w[i];
				else
					f[i][j] = f[i-1][j];
			}
		printf("%d\n", f[N][V]);
	}
	return 0;
}