#include<stdio.h>
#include<string.h>
const int maxn = 200010;
int ans[maxn], p[maxn];
bool sign[maxn];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int m, n, i, max = -1;
		memset(sign, false, sizeof(sign));
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if(tmp > max)
				max = tmp;
			sign[tmp] = true;
		}
		int crt = 0;
		for(i = 1; i < max+2; i++)
		{
			p[i] = crt;	
			if(sign[i] == 0)
				ans[crt++] = i;
		}
		for(i = 1; i <= m; i++)
		{
			scanf("%d", &n);
			if(n > max)
				printf("%d\n", n);
			else
				printf("%d\n", ans[p[n]]);
		}
	}
	return 0;
}