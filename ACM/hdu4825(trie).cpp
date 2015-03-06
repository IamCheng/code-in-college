#include<stdio.h>
#include<string.h>

const int maxnode = 3200100;
int trie[maxnode][2], sz = 1;
unsigned int value[maxnode];
void insert(unsigned int s)
{
	int u = 0;
	for(int i = 31; i >= 0; i--)
	{
		int v = (s & (1 << i)) ? 1 : 0;
		if(!trie[u][v])
		{
			value[u] = 0;
			trie[u][v] = sz++;
		}
		u = trie[u][v];
	}
	value[u] = s;
}
unsigned query(unsigned x)
{
	int u = 0;
	for(int i = 31; i >= 0; i--)
	{
		int v = (x & (1 << i)) ? 0 : 1;
		if(trie[u][v])
			u = trie[u][v];
		else
			u = trie[u][1^v];
	}
	return value[u];
}
int main()
{
	int T;
	scanf("%d", &T);
	int i, t, n, m;
	for(t = 1; t <= T; t++)
	{
		memset(trie, 0, sizeof(trie));
		sz = 1;
		printf("Case #%d:\n", t);
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++)
		{
			unsigned int x;
			scanf("%u", &x);
			insert(x);
		}
		for(i = 1; i <= m; i++)
		{
			unsigned int x;
			scanf("%u", &x);
			printf("%u\n", query(x));
		}
	}
	return 0;
}
