#include<stdio.h>
int num[201][201];
int ans[40010];
int m, n;
int output()
{
	int t = 0, r = 0, c = 0, len, rr = m - 1, cc = n - 1, tmp1, tmp2, tmp;
	int x = r, y = c;
	while(t < m * n)
	{
		if(r == rr && c == cc)
			break;
		len = rr - r;
		for(int i = 1; i <= 4; i++)
		{
			if(i == 1)
			{
				tmp1 = len;
				tmp = r;
				for(;r < tmp + len && t < m * n; r++)
					ans[t++] = num[r][c]; 
				len = cc - c;
			}
			if(i == 2)
			{
				tmp2 = len;
				tmp = c;
				for(; c < tmp + len && t < m * n; c++)
					ans[t++] = num[r][c];
			}
			if(i == 3)
			{
				len = tmp1;
				tmp = r;
				for(; r > tmp - len && t < m * n; r--)
					ans[t++] = num[r][c];
			}
			if(i == 4)
			{
				len = tmp2;
				tmp = c;
				for(; c > tmp - len && t < m * n; c--)
					ans[t++] = num[r][c];
			}
		}
		r++;
		c++;
		rr--;
		cc--;

	}
	if(r == rr && c == cc)
		ans[t++] = num[r][c];
	printf("%d", ans[0]);
	for(int i = 1; i < t; i++)
		printf(" %d", ans[i]);
	printf("\n");
	return 0;
}
int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &num[i][j]);
	output();
	return 0;
}