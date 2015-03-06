#include<stdio.h>
#include<string.h>
struct table
{
	int tb[31][31];
};
int n;
table multiply(table a, table b)
{
	table ans;
	for(int r = 0; r < n; r++)
	{
		for(int c = 0; c < n; c++)
		{
			int tot = 0;
			for(int k = 0; k < n; k++)
			{
				tot += a.tb[r][k] * b.tb[k][c];
			}
			ans.tb[r][c] = tot;
		}
	}
	return ans;
	
}
int main()
{
	int m, i;
	table a, b, c;
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &a.tb[i][j]);
	b = a;
	for(i = 1; i < m; i++)
	{
		c = multiply(a, b);
		a = c;			
	}
	if(m == 0)
	{
		memset(a.tb, 0, sizeof(a.tb));
		for(i = 0; i < n; i++)
			a.tb[i][i] = 1;
	}
	for(i = 0; i < n; i++)
	{
		printf("%d", a.tb[i][0]);
		for(int j = 1; j < n; j++)
			printf(" %d", a.tb[i][j]);
		printf("\n");
	}
	return 0;
}