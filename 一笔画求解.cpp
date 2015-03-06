#include<stdio.h>
const int maxn = 100;
int map[maxn][maxn], m, n, road[maxn];
bool vis[maxn][maxn];
bool DFS(int s, int depth)
{
	if(depth - 1 == m)
	{
		for(int i = 1; i <= m; i++)
			printf("%d ", road[i]);
		printf("%d\n", s);
		return true;

	}
	for(int i = 1; i <= n; i++)
	{
		if(map[s][i] && !vis[s][i])
		{
			road[depth] = s;
			vis[s][i] = vis[i][s] = 1;
			if(DFS(i, depth+1))
				return true;
			vis[s][i] = vis[i][s] = 0;
		}

	}
	return false;
}
int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		map[u][v] = 1;
		map[v][u] = 1;
	}
	for(i = 1; i <= n; i++)
		if(DFS(i, 1))	return 0;
	return 0;
}
