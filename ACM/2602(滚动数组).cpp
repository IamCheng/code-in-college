#include<stdio.h>
#include<string.h>
const int maxn = 1010;
int c[maxn], w[maxn], f[maxn];
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
			for(j = V; j >= c[i]; j--)
				f[j] = (f[j] > f[j-c[i]] + w[i]) ? f[j] : f[j-c[i]] + w[i];
		printf("%d\n", f[V]);
	}
	return 0;
}