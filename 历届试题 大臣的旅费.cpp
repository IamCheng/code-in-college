#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 11000;
struct node
{
	int u, w;
};
bool vis[maxn];
vector <node> map[maxn];
int n, max_v = -1, v;
int DFS(int s, int value)
{
	vis[s] = true;
	for(int i = 0; i < map[s].size(); i++)
	{
		if(!vis[map[s][i].u])
			DFS(map[s][i].u, value+map[s][i].w);
	}
	if(map[s].size() == 1)
	{
		if(max_v < value)
		{
			max_v = value;
			v = s;
		}	
	}
	vis[s] = false;
	return 0;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n-1; i++)
	{
		node tmp;
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		tmp.u = v;
		tmp.w = w;
		map[u].push_back(tmp);
		tmp.u = u;
		map[v].push_back(tmp);
	}
	int ans = 0;
	DFS(1, 0);
	DFS(v, 0);
	ans = max_v;
	printf("%d", (1+ans)*ans/2+ans*10);
	return 0;
}
