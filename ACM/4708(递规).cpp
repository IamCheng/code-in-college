#include<stdio.h>
int num[11][11], ans, times;
int min(int a, int b){return a > b ? b : a;}
int cal(int l_x, int l_y, int r_x, int r_y)
{
	if(l_x == r_x && l_y == r_y)
	{
		ans += num[r_x][r_y];
		return 0;
	}
	cal(l_x+1, l_y+1, r_x-1, r_y-1);
	int max = -1, t;
	for(int i = 0; i < r_x - l_x; i++)
	{
		int tmp = num[l_x][l_y+i] + num[l_x+i][r_y] + num[r_x][r_y-i] + num[r_x-i][l_y];
		if(max <= tmp)
		{
			if(max == tmp)
				t = min(t, min(r_x-l_x-i, i));
			else
			{
				max = tmp;
				t = min(i, r_x-l_x-i);
			}
		}
	}
	times += t;
	ans += max;
	return 0;
}
int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1 && n)
	{
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				scanf("%d", &num[i][j]);
		ans = times = 0;
		cal(1, 1, n, n);
		printf("%d %d\n", ans, times);
	}
	return 0;
}