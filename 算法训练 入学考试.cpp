#include<stdio.h>
const int maxn = 1010;
int dp[maxn];
int main()
{
	int V, M, w[100], v[100], i, j;
	scanf("%d%d", &V, &M);
	for(i = 0; i < M; i++)
	{
		scanf("%d%d", &v[i], &w[i]);
	}
	for(i = 0; i < M; i++)
		for(j = V; j >= v[i]; j--)
			dp[j] = dp[j] > dp[j-v[i]] + w[i] ? dp[j] : dp[j-v[i]] + w[i];
	printf("%d\n", dp[V]);
	return 0;
}