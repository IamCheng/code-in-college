#include<stdio.h>
int start[61],finish[61];
long long f(int *p, int i, int other)
{
	if(0 == i)	
		return 0;
	if(p[i] == other)	return f(p, i-1, other);
	return f(p, i-1, 6 - p[i] - other) + ((long long)1<<(i-1));
}
int main()
{
	int N, T = 1;
	while(scanf("%d", &N) == 1 && N != 0)
	{
		for(int i = 1; i <= N; i++)	scanf("%d", &start[i]);
		for(int j = 1; j <= N; j++)	scanf("%d", &finish[j]);
		while(N >= 1 && start[N] == finish[N])	N--;
		long long ans = 0;
		if(N >= 1)
		{
			int other;
			other = 6 - start[N] - finish[N];
			ans = f(start, N-1, other) + f(finish, N-1, other) + 1;
		}
		printf("Case %d: %lld\n", T++, ans);
	}
	return 0;
}