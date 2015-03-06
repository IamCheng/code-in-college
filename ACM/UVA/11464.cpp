#include<stdio.h>
#include<string.h>
const int maxn = 20;
int n, max = 10000000, ans = 0;
int a[maxn][maxn], b[maxn][maxn];

int judge(int num)
{
	int tot = 0, i, j;
	memset(b, 0, sizeof(b));
	for(i = 1; i <= n; i ++)
		if( a[0][i] && !((1 << (n-i)) & num))
			return (tot = max);
		else
		{
			b[0][i] = ((1 << (n-i)) & num) >> (n - i);
			if(!a[0][i]&b[0][i])
				tot++;
		}
		for(i = 1; i < n; i++)
			for(j = 1; j <= n; j++)
			{
				if(i == 1)
					b[i][j] = (4 - b[i-1][j-1] - b[i-1][j+1])%2;
				else
					b[i][j] = (4 - b[i-1][j-1] - b[i-1][j+1] -b[i-2][j])%2;
				if(a[i][j] == 1 && b[i][j] == 0)
					return (tot = max);
				if( !a[i][j] & b[i][j])
					tot++;
			}
			if(ans == -1 || tot < ans )
				ans = tot;
			return 0;
}


int main()
{
	int i, j, t,num;
	scanf("%d", &num);
	for(t = 1; t <= num; t++)
	{
		scanf("%d", &n);
		ans = -1;
		for(i = 0; i < n; i++)
			for(j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for(i = 0; i < (1 << n); i++)
			judge(i);
		printf("Case %d: %d\n", t, ans);			
	}
	return 0;
}
