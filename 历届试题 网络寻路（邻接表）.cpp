#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxN = 10010;
vector <int> Node[maxN];
int N, M;
bool vis[maxN];
int build()
{
	int u, v;
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d", &u, &v);
		Node[u].push_back(v);
		Node[v].push_back(u);
	}
	return 1;
}
int tot = 0;
int DFS(int n, int t)
{
	if(t == 2)
	{
		tot += Node[n].size() - 1;
		return 1;
	}
	vis[n] = 1;
	for(int i = 0; i < Node[n].size(); i++)
		if(!vis[Node[n][i]])
		{
			DFS(Node[n][i], t+1);
			vis[Node[n][i]] = 0;
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