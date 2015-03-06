#include<stdio.h>
int P[30010];
int main()
{
	int v[25], w[25], N, num;
	scanf("%d%d", &N, &num);
	for(int i = 0; i < num; i++)
		scanf("%d%d", &v[i], &w[i]);
	for(int j = 0; j < num; j++)
	{
		for(int i = N; i >= v[j]; i--)
		{
			P[i] = P[i] > P[i-v[j]] + v[j] * w[j] ? P[i] : P[i-v[j]] + v[j] * w[j];
		}
	}
	printf("%d\n", P[N]);

	return 0;
}