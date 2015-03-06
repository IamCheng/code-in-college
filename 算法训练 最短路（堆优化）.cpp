#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 20010;
const int inif = 1000000000;
struct P
{
	int vex, w;
	P(int v, int ww):vex(v),w(ww){};
};
bool operator < (P a, P b)
{
    return a.w > b.w; 
};
vector <P> node[maxn];
int dis[maxn];
bool vis[maxn];
int Djistra(int n)
{
	int i, j;

	priority_queue <P> q;
	for(i = 1; i <= n; i++)
		dis[i] = inif;
	dis[1] = 0;
	P pre_node(1, dis[1]); 
	q.push(pre_node);
	while(!q.empty())
	{
		pre_node = q.top();
		q.pop();	
		if(vis[pre_node.vex])	continue;
		int u = pre_node.vex;
		for(j = 1; j <= node[u].size(); j++)
		{
			int & v = node[u][j-1].vex;
			if(!vis[v] && (node[u][j-1].w + dis[u] < dis[v]))
			{
				dis[v] = node[u][j-1].w + dis[u];
				P tmp(v, dis[v]);
				q.push(tmp);
			}
		}
		vis[u] = true;		
	}
	for(i = 2; i <= n; i++)
		printf("%d\n", dis[i]);
	return 1;
}
int main()
{
	int n, m, u;
	scanf("%d%d", &n, &m);
	P a(0, 0);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &u, &a.vex, &a.w);
		node[u].push_back(a);
	}
	Djistra(n);
	return 0;
}