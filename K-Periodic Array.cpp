#include<stdio.h>
int array[105];
int min(int a, int b)
{
	return a > b ? b : a;
}
int main()
{
	int n, k, i, j;
	while(scanf("%d%d", &n, &k) == 2)
	{	
		for(i = 0; i < n; i++)
			scanf("%d", &array[i]);
		int ans = 0;
		for(j = 1; j <= k; j++)
		{
			int num[3] = {0};
			for(i = j - 1; i < n; i += k)
				num[array[i]]++;
			ans += min(num[1], num[2]);
		}
		printf("%d\n", ans);

	}
}