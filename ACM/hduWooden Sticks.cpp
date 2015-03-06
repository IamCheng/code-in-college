#include<stdio.h>
#include<algorithm>
using namespace std;
struct stick
{
	int l, w;
};
const int maxn = 5010;
stick s[maxn];
bool v[maxn];
int cmp(stick a, stick b)
{
	if(a.l < b.l)
		return 1;
	if(a.l == b.l)
		return a.w < b.w;
	return 0;
}
int print(int n)
{
	for(int i = 0; i < n; i++)
		printf("%d %d\n", s[i].l, s[i].w);
	return 0;
}
int main()
{
	int T;
 	scanf("%d", &T);
	while(T--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d%d", &s[i].l, &s[i].w);
		sort(s, s+n, cmp);
		int t = 0, ans = n, num = 0;
		memset(v, 0, sizeof(v));
		while(t < n)
		{
			stick tmp = s[num];
			bool flag = false;
			t++;
			for(int i = num + 1; i < n; i++)
			{
				if(v[i] == 0 && tmp.l <= s[i].l && tmp.w <= s[i].w)
				{
					v[i] = 1;
					t++;
					ans--;
					tmp = s[i];
				}
				else
				{
					if(!flag && !v[i])
					{
						flag = true;
						num = i;
					}
				}
			}
		}
		printf("%d\n", ans);
		
	}
	return 0;
}