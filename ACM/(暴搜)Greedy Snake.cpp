#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int map[10][10], xx[4] = {-1, 0, 1, 0}, yy[4] = {0, -1, 0, 1};
int vis[10][10];
int n, m, ans, ex, ey;

int DFS(int x, int y)
{
	if(x == ex && y == ey)
	{
		if(ans < vis[x][y] + 2)
			ans = vis[x][y] + 2;
		return 0;
	}
	for(int i = 0; i < 4; i++)
	{
		if(map[x+xx[i]][y+yy[i]] != 0 && vis[x+xx[i]][y+yy[i]] < 0)
		{
			vis[x+xx[i]][y+yy[i]] = vis[x][y] + map[x+xx[i]][y+yy[i]];
			DFS(x+xx[i], y+yy[i]);
			vis[x+xx[i]][y+yy[i]] = -1;
		}
	}
	return 0;
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		memset(vis, -1, sizeof(vis));
		memset(map, 0, sizeof(map));
		ans = -1;
		int r, c;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j] == -2)
				{
					ex = i; ey = j;
				}
				if(map[i][j] == -1)
				{
					r = i;
					c = j;
				}
			}	
		vis[r][c] = 0;
		DFS(r, c);
		printf("%d\n", ans);
	}
	return 0;
}
