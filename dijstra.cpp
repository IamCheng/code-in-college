#pragma warning (disable:4786)
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

set <int > refer;
const int maxn = 100;
int mp[maxn][maxn], N, M, nor;
int in[maxn], vis[maxn];

void out(int mp[maxn][maxn])
{
	int i, j;
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%3d ", mp[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
bool cmp(int a, int b)
{
	return in[a] > in[b];
}
void build()
{
	int i;
	scanf("%d%d", &N, &M);
	for(i = 0; i < M; i++)
	{
		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);
		in[u]++;
		in[v]++;
		mp[u][v] = val;
		mp[v][u] = val;
	}
	int order[maxn];
	for(int j = 0; j < N; j++)
		order[j] = j;
	sort(order, order+N, cmp);
	scanf("%d", &nor);
	for(i = 0; i < nor; i++)
		refer.insert(order[i]);
}
int djistra()
{
	set <int>::iterator it;
	int i, j;
	int tmp[maxn][maxn] = {0};
	for(it = refer.begin(); it != refer.end(); it++)
	{
		int x = *it, dist[maxn] = {0}, xx = *it;
		memset(vis, 0, sizeof(vis));
		vis[x] = true;
		int t = 1;
		while(t < N)
		{
			for(i = 0; i < N; i++)
			{
				if(!vis[i] && mp[x][i] != 0)
				{
					if(dist[i] == 0 || dist[i] < dist[x] + mp[x][i])
					{
						dist[i] = dist[x] + mp[x][i];
					}
				}
			}
			int min= 1000000000;
			for(i = 0; i < N; i++)
			{
				if(!vis[i] && dist[i] != 0 && dist[i] < min)
				{
					min = dist[i];
					x = i;
				}
			}
			vis[x] = true;
			t++;
		}
		for(i = 0; i < N; i++)
			tmp[xx][i] = dist[i];
	}
	for(i =0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			if(tmp[i][j] != 0)	mp[i][j] = tmp[i][j];
		}
	}
	out(tmp);
	return 0;
}
int cal_min()
{
	set <int>::iterator it;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(refer.count(i))	break;
			int f_min = 100000000, s_min = 100000000;
			for(it = refer.begin(); it != refer.end(); it++)
			{
				int k = *it;
				if(f_min > mp[k][i])	f_min = mp[k][i];
				if(s_min > mp[k][j])	s_min = mp[k][j];				
			}
			if(i != j)	mp[i][j] = f_min + s_min;
		}		
	}
	return 0;	
}

int main()
{
	build();
	djistra();
	cal_min();
	out(mp);
	return 0;
}