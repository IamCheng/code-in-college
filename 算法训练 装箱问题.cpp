#include<stdio.h>
int v[33], dp[20010];
int main()
{
	int n, V, i, j;
	scanf("%d", &V);
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(i = 1; i <= n; i++)
	{
		int tmp = 0;
		for(j = V; j >= v[i]; j--)
			dp[j] = dp[j-v[i]] + v[i] > dp[j] ? dp[j-v[i]] + v[i] : dp[j];
	}
	printf("%d", V-dp[V]);
	return 0;
}