#include<stdio.h>
#include<string.h>
int n, ans[21];
bool vis[20], prime[40];
void ini_prime()
{
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i * i < 40; i++)
	{
		if(!prime[i])
			continue;
		for(int j = i * i; j < 40; j += i)
			prime[j] = false;
	}
}
int DFS(int a, int b, int depth)
{
	if(!prime[a+b])
		return 0;
	ans[b] = a;
	if(depth == n - 1)
	{
		if(!prime[b+1])
			return 0;
		int tmp[20] = {0};
		int i = n;
		while(ans[b] != 0)
		{
			tmp[i--] = b;
			b = ans[b];
		}
		printf("1");
		for(i = 2; i <= n; i++)
			printf(" %d", tmp[i]);
		printf("\n");		
		return 0;
	}
	for(int i = 2; i < n + 1; i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			DFS(b, i, depth+1);
			vis[i] = false;
		}
	}
	return  0;
}
int main()
{
	int t = 1;
	ini_prime();
	while(scanf("%d", &n) == 1)
	{
		memset(vis, 0, sizeof(vis));
		printf("Case %d:\n", t++);
		if(n == 1)
			printf("1\n");
		for(int i = 2; i <= n; i += 2)
		{
			vis[i] = true;
			DFS(1, i, 1);
			vis[i] = false;
		}
		printf("\n");
	}
	return 0;
}