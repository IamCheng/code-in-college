#include<stdio.h>
#include<string.h>
const int maxN = 10010;
int degree[maxN], N, M;
bool vis[maxN];
char map[maxN][maxN];	
int build()
{
	int u, v;
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		map[u][v] = map[v][u] = 1;
		degree[u]++;
		degree[v]++;
	}
	return 1;
}
int tot = 0;
int DFS(int n, int t)
{
	if(t == 2)
	{
		tot += degree[n] - 1;
		return 1;
	}
	vis[n] = 1;
	for(int i = 1; i <= N; i++)
		if(map[n][i] == 1 && !vis[i])
		{
			DFS(i, t+1);
			vis[i] = 0;
		}
	return 0;
}
int main()
{
	scanf("%d%d", &N, &M);
	build();
	for(int i = 1; i <= N; i++)
	{
		DFS(i, 0);
		vis[i] = 0;
	}
	printf("%d\n", tot);
	return 0;
}