#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m, n, v[12][10], irr[11];
int dfs(int len, int * num, int fa)
{
	if(len == 0)	return 1;
	int ans = 0;
	for(int i = num[len] - 1; i >= 0; i--)
	{
		if(abs(i-fa) >= 2)
			ans += v[len][i];
	}
	if(abs(fa-num[len]) < 2)
		return ans;
	ans += dfs(len-1, num, num[len]);	
	return ans;
}
int dfs(int len, int x)
{
	if(len == 1)	return v[len][x] = 1;
	if(v[len][x] != 0)	return v[len][x];
	int ans = 0;
	for(int i = 0; i <= 9; i++)
		if(abs(x-i) >= 2)	ans += dfs(len-1, i);		
	v[len][x] = ans;
	return ans;

}
int solve(int s)
{
	if(s <= 0)	return 0;
	int len = 0, num[11];
	while(s)	num[++len] = s % 10, s = s / 10;
	return dfs(len, num, -2)+irr[len]-v[len][0];
}

int main()
{
	irr[2] = 9;
	dfs(11, 11);	
	for(int j = 3; j <= 10; j++)
	{
		for(int i = 1; i <= 9; i++)
			irr[j] += v[j-1][i];
		irr[j] += irr[j-1];
	}
	while(scanf("%d%d", &m, &n) == 2 && !(m == 0 && n == 0))
	{
		printf("%d\n", (solve(n)-solve(m-1)));
	}
	return 0;
}