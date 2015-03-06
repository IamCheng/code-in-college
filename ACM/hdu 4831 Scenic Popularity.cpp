#pragma warning (disable: 4786)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
using namespace std;
const int maxn = 100100;
int d[maxn], p[maxn] = {-10000000}, h[maxn], N, l[maxn], r[maxn];
bool vis[maxn];
set <int> mp[maxn];
int max(int a, int b)
{
	return a > b ? a : b;
}
int lowbit(int x)
{
    return x&(-x);
}
void update(int x, int num)
{
    while(x<=maxn)
     {
         d[x]+=num;
         x+=lowbit(x);
     }
}
int getSum(int x)
{
    int s=0;
    while(x>0)
    {
         s += d[x];
         x -= lowbit(x);
    }
    return s;
}
int main()
{
	int t, T, i, j, k;
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));

		j = 1;
		scanf("%d", &N);
		for(i = 1; i <= N; i++)
		{
			mp[i].clear();
			scanf("%d%d", &p[i], &h[i]);
		}
		k = 0;
		for(i = 1; i <= N; i++)
		{
			if(h[i] == 0)	l[i] = k;
			else	k = i;
		}
		for(i = N; i >= 1; i--)
		{
			if(h[i] == 0)	
			{
				r[i] = k;
				if(p[r[i]] - p[i] >= p[i] - p[l[i]])
				{
					mp[l[i]].insert(i);
					if(p[r[i]] - p[i] == p[i] - p[l[i]])
					{
						vis[i] = true;
						h[i] = max(h[l[i]], h[r[i]]);
						mp[r[i]].insert(i);
					}
					else
					{
						h[i] = h[l[i]];			
					}
				}
				else
				{
					h[i] = h[r[i]];
					mp[r[i]].insert(i);
				}
			}
			else	
				k = i;
			update(h[i], 1);
		}

		printf("Case #%d:\n", t);
		int K;//ָ�
		scanf("%d", &K);
		while(K--)
		{
			int a, b;
			char cmd[10];
			scanf("%s %d", cmd, &a);
			if(cmd[0] == 'U')
			{
				update(h[a+1], -1);
				scanf("%d", &b);
				update(b, 1);
				h[a+1] = b;
				set<int>::iterator it;
				for(it = mp[a+1].begin(); it != mp[a+1].end(); it++)
				{
					update(h[*it], -1);
					if(!vis[*it])
					{					
						h[*it] = h[a+1];
						update(h[*it], 1);
					}
					else
					{
						h[*it] = max(h[l[*it]], h[r[*it]]);
						update(h[*it], 1);
					}
				}
			}
			else
			{
				int ans = getSum(a);
				printf("%d\n", ans);
			}

		}
	}
	return 0;
}
