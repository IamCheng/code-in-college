#pragma comment(linker,"/STACK:102400000,1024000")
#include<stdio.h>
#include<bitset>
#include<string.h>
using namespace std;
const int maxn = 500010;
const int maxm = 20010;
struct Edge
{
	int u, v, next;
}edge[maxn];
bool vis[maxm];
int Node[maxm], value[maxm];
int N, M;

bitset <maxm> bit[maxm];
void DFS(int u)
{
	vis[u] = true;
	for(int v = Node[u]; v != 0; v = edge[v].next)
	{	
		int t = edge[v].v;
		if(!vis[t])
			DFS(t);
		bit[u] = bit[u] | bit[t];
		//tot[u] += tot[t];
	}
}
int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int i;
		scanf("%d%d", &N, &M);
		memset(Node, 0, sizeof(Node));
		memset(vis, 0, sizeof(vis));
		for(i = 1; i <= N; i++)
		{
			scanf("%d", &value[i]);
			bit[i].reset();
			bit[i][i] = 1;
		}
		for(i = 1; i <= M; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			edge[i].u = u;
			edge[i].v = v;	
			edge[i].next = Node[u];
			Node[u] = i;
		}		
		for(i = 1; i <= N; i++)
		{
			if(!vis[i])	DFS(i);
		}

		for(i = 1; i <= N; i++)
		{
			int ans = 0;
			for(int j = 1; j <= N; j++)
			{
				if(bit[i].test(j))
				{
					ans += value[j];
				}
			}
			if(i == 1)
				printf("%d", ans);
			else
				printf(" %d", ans);
		}
		printf("\n");
	}
	return 0;
}
