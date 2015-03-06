#include<stdio.h>
int ans = 0, k;
int srch(int num, int crt, int depth)
{
	if((num - crt) < crt * (k - depth))
		return 0;
	else
	{
		if(k == depth + 1)
		{
			ans++;
			return 1;
		}
	}
	for(int i = crt; i <= num; i++)
		srch(num-crt, i, depth+1);
}
int main()
{
	int n, i;
	scanf("%d%d", &n, &k);
	if(k == 1)
		ans = 1;
	for(i = 1; (n - i) >= i * (k - i); i++)
		srch(n, i, 1);
	printf("%d\n", ans);
	return 0;
}
