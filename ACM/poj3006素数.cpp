#include<stdio.h>
#define maxn 1000010
int prime[maxn] = {1, 1};
int main()
{
	int i, j, a, d, n;
	for(i = 2; i * i <= maxn; i++)
	{
		if(prime[i])
			continue;
		for(j = i * i; j <= maxn; j += i)
			prime[j] = 1;
	}
	while(scanf("%d%d%d", &a, &d, &n) == 3 && (a||d||n))
	{
		j = 1;
		for(i = a; j <= n; i += d)
			if(!prime[i])
				j++;
		printf("%d\n", i-d);
	}
	return 0;
}