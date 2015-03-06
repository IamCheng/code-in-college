#include<stdio.h>
const int maxn = 110;
int dp[maxn][maxn] = {0};
int main()
{
	int k, l;
	scanf("%d%d", &k, &l);	
	__int64 sum = 0;
	for(int i = 1; i <= k; i++)
	{
		dp[0][i] = 1;
		sum++;
	}
	int rest = 1;
	if(k == 1 && l == 1)
		sum = 0;
	for(int j = 1; j < l; j++)
	{
		__int64 tmp = 0;
		for(int i = 1; i <= k; i++)
		{
			dp[j][i] = (sum - dp[j-1][i-1] - dp[j-1][i+1] - rest) % 1000000007;
			if(j == 1 && i == 2)	dp[j][i]++;
			tmp += dp[j][i];
		}
		rest = 0;
		sum = tmp;
	}
	printf("%d\n", sum%1000000007);
	return 0;
	
}