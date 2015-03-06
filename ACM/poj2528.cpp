#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 10010;
int tr[maxn << 2];
int num[maxn], s[maxn], n, int vis[maxn];

map <int , int> mp;

int insert(int o, int L, int R, int l, int r, int x)
{
	if(L >= l && R <= r)
	{
		tr[o] = x;
		return 0;
	}
	if(tr[o] != 0)
	{
		tr[o<<1] = tr[(o<<1)+1] = tr[o];
		tr[o] = 0;
	}
	int m = L + (R - L) / 2;
	if(m >= l)	insert(o<<1, L, m, l, r, x);
	if(m < r)	insert((o<<1)+1, m+1, R, l, r, x);
	return 0;
}

int get_sum(int o, int L, int R)
{
	if(tr[o] > 0)
	{
		if(!vis[tr[o]])
		{
			vis[tr[o]] = true;
			return 1;
		}
		return 0;
	}
	if(L == R)	return 0;
	int m = L + (R - L) / 2, tot = 0;
	tot += get_sum(o<<1, L, m);
	tot += get_sum((o<<1)+1, m+1, R);
	return tot;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int i, j = 1, cnt = 1;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(i = 0; i < n<<1; i++)
		{
			scanf("%d", &num[i]);
			s[i] = num[i];
		}
		sort(s, s+n*2);
		mp[s[0]] = cnt++;
		for(i = 1; i < n << 1; i++)
		{
			if(s[i] != s[i-1])
			{
				mp[s[i]] = cnt++;
			}
		}
		for(i = 0; i < n << 1; )
		{
			int l = mp[num[i++]];
			int r = mp[num[i++]];
			insert(1, 1, (cnt-1), l, r, j++);
		}
		int ans = get_sum(1, 1, (cnt-1));
		printf("%d\n", ans);
	}
	return 0;
}