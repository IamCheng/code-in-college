#pragma comment(linker,"/STACK:102400000,1024000")
#include<stdio.h>
#include<string.h>
const int maxn = 500010;
const int maxm = 20010;
struct Edge
{
	int u, v, next;
}edge[maxn];
bool vis[maxm];
int Node[maxm], value[maxm];
int N, M;

struct bitset
{
	unsigned int b[628];
	int n;
	bitset operator | (bitset a)
	{
		int len = n / 32;
		bitset c;
		c.n = n;
		c.reset();	
		for(int i = 1; i <= len+1; i++)
			c.b[i] = a.b[i] | b[i];
		return c;
	}
	void set(int pos)
	{
		int len = pos / 32;
		int t;
		if(pos % 32 == 0)
		{
			t = 32;
			len--;
		}
		else
			t = pos % 32;
		b[len+1] |= (1 << (t-1));
	}
	void reset()
	{
		memset(b, 0, sizeof(int)*n);
	}
	bool test(int pos)
	{
		int len = pos / 32;
		int t;
		if(pos % 32 == 0)
		{
			t = 32;
			len--;
		}
		else
			t = pos % 32;
		unsigned int tt = 1;
		return	b[len+1]&(tt << (t-1));
	}
}bit[maxm];

void DFS(int u)
{
	vis[u] = true;
	for(int v = Node[u]; v != 0; v = edge[v].next)
	{	
		int t = edge[v].v;
		if(!vis[t])
			DFS(t);
		bit[u] = bit[u] | bit[t];
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
			bit[i].n = N;
			bit[i].reset();
			bit[i].set(i);
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

