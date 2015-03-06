#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 100010;
int value[maxn], ans[maxn][2];
vector <int> node[maxn];
bool vis[maxn];

int DFS(int n)
{
	if(!vis[n])
	{
		vis[n] = true;
		int sum = 0;	
		for(int i = 0; i < node[n].size(); i++)
		{
			if(vis[node[n][i]])
				continue;
			sum += DFS(node[n][i]);	
			ans[n][1] += ans[node[n][i]][0];
		}
		ans[n][0] = sum;
		ans[n][1] += value[n];	
		return (ans[n][0] > ans[n][1]) ? ans[n][0] : ans[n][1];
		
	}
	return 0;
}
int main()
{
	int n, i, u, v;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &value[i]);
	for(i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		node[u].push_back(v);
		node[v].push_back(u);
	}
	printf("%d\n", DFS(1));
	return 0;
}