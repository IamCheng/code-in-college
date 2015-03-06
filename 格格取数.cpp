#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int vis[110], q[110];
int map[110][110];
int n, m;
int min_value(int r, int c, int flag)
{
	int min_v = 10000000, tmp;
	if(flag == 1)
		tmp = m;
	else
		tmp = n;
	if(r == tmp)
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < tmp; i++)
		{
			vis[q[i]] = 1;
		}
		for(int j = 1; j <= m+n-tmp; j++)
			if(!vis[j])	return min_v;	
		int tmp = flag == 1 ? map[r][c] : map[c][r];
		return tmp;
	}
	
	for(int j = 1; j <= m+n-tmp; j++)
	{
		q[r] = j;
		int t;
		if(flag == 1)
			t = map[r][c]+min_value(r+1, j, flag);
		else
		{
			t = map[c][r]+min_value(r+1, j, flag);
		}
		if(t < min_v)	min_v = t;
	}
	return min_v;
}
int main()
{
	int t, cnt = 0, flag;
	scanf("%d", &t);
	while(t--)
	{
		cnt++;
		scanf("%d%d", &m, &n);
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);
		flag = m > n ? 1 : 0;
		cout << "Case "<< cnt << ": " << min_value(0, 0, flag) << endl;

	}
	return 0;
}
