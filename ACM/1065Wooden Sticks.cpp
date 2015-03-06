#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 5010;
struct node
{
	int l, r;
}p[maxn];
bool vis[maxn];
int cmp(node a, node b)
{
	return a.l == b.l ? a.r < b.r : a.l < b.l;
}
int main()
{
	int T, n, i, j;
	scanf("%d", &T);
	while(T--)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%d%d", &p[i].l, &p[i].r);
		sort(p, p+n, cmp);
		/*
			for(i = 0; i < n; i++)
				printf("%d %d\n", p[i].l, p[i].r);
		*/
		int ans = 0;
		for(i = n - 1; i >= 0; i--)
		{
			if(vis[i])	continue;
			for(j = i - 1; j >= 0; j--)
			{
				if(!vis[j] && p[i].l >= p[j].l && p[i].r >= p[j].r)
				{
					vis[j] = true;
					p[i].l = p[j].l;
					p[i].r = p[j].r;
				}
			}
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}