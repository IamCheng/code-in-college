#include<stdio.h>
#include<string.h>
int m, n, v[10][10], pow[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int dfs(int len, int * num, int s, int fa)
{
	int ans = 0, w[10] = {0};
	if(len == 0)	return 0;
	for(int i = num[len] - 1; i >= 0; i--)
	{
		if(i == 2 && fa == 6)
			ans += pow[len-1];
		else
		{
			ans += v[len][i];
		}
	}

	if(num[len] == 4 || (num[len] == 2 && fa == 6))
	{
		ans += (s % pow[len-1]) + 1;
	}
	else
		ans += dfs(len-1, num, s-pow[len-1]*num[len], num[len]);

	return ans;
}

int dfs(int len, int x)
{
	if(len == 1)
	{
		return v[len][x] = x == 4 ? 1 : 0;
	}
	if(v[len][x] != 0)
		return v[len][x];
	int ans = 0;
	for(int i = 0; i <= 9; i++)
	{
		if(x == 4)
		{
			ans = pow[len-1];
			break;
		}
		if(x == 6 && i == 2)
		{
			ans += pow[len-2];
			continue;
		}
		ans += dfs(len-1, i);
	}
	v[len][x] = ans;
	return ans;

}
int solve(int s)
{
	int len = 0, num[10], xx = s;
	while(s)	num[++len] = s % 10, s = s / 10;
	return dfs(len, num, xx, -1);
}
void out()
{
	for(int i = 1; i <= 7; i++)
	{
		for(int j = 0; j < 10; j++)
			printf("%d ", v[i][j]);
		putchar('\n');
	}
}
int main()
{
	dfs(8, 1);	
//	out();
	while(scanf("%d%d", &m, &n) == 2 && !(m == 0 && n == 0))
	{
		printf("%d\n", n-m+1-(solve(n)-solve(m-1)));

	}
	return 0;
}