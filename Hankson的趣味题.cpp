#include<stdio.h>
#include<math.h>
const int maxn = 55000;
const int pmaxn = 5500;
int prime[pmaxn], p, ans = 1, tt;
bool vis[maxn];
int div(int & a, int b)
{
	int cnt = 0;
	while(a % b == 0)
	{
		a /= b;
		cnt++;
	}
	return cnt;
}
int main()
{
	int test = 50010;
	int t = 0, n, m = (int)sqrt(maxn+0.5);
	for(int i = 2; i <= m; i++)
	{
		if(vis[i])	continue;
		prime[t++] = i;
		for(int j = i * i; j < maxn; j += i)
			vis[j] = true;
	}
	for(; i < maxn; i++)
		if(!vis[i])
			prime[t++] = i;
		scanf("%d", &n);
	while(n--)
	{
		int a, aa, b, bb;
		ans = 1;
		tt = 0;
		scanf("%d%d%d%d", &a, &aa, &b, &bb);
		for(i = 0; bb != 1; i++)
		{
			if(i > 4950)
				prime[i] = bb;
			if(bb % prime[i] != 0)
				continue;
			int cnt, type, tot;
			int a1c = div(aa, prime[i]);
			int a0c = div(a, prime[i]);
			if(a1c > a0c)	continue;
			if(a1c == a0c)	
			{
				cnt = a1c;
				type = 1;
			}
			if(a1c < a0c)
			{
				type = 2;
				cnt = a1c;
			}
			
			int b0c = div(b, prime[i]);
			int b1c = div(bb, prime[i]);
			if(b1c == b0c)
			{
				if(type == 1)
					tot = b1c - cnt + 1;
				else
				{
					if(cnt > b1c)
						continue;
					tot = 1;
				}
				if(tot <= 0) continue;
			}
			if(b1c > b0c)
			{
				if(type == 2)
				{
					if(b1c != cnt)
					{
						ans = 0;
						break;
					}
					tot = 1;
				}
				else
				{
					if(cnt > b1c)
						continue;
					tot = 1;
				}				
			}
			ans *= tot;
		}
		printf("%d\n", ans);		
	}
	return 0;
}