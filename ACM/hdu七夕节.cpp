#include<stdio.h>
int num[500005];
int cal(int n)
{
	int sum = 0, j;
	if(n <= 1)
		return 0;
	for(j = 2; j * j < n; j++)
		if(n % j == 0)
			sum += j + n / j;
	if(j * j == n)
		sum += j;
	return sum + 1;
}
int main()
{
	int i, T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &i);
		printf("%d\n", cal(i));
	}
	return 0;
}