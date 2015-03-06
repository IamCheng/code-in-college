#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		int sum = 1;
		while(n/=2)
			sum++;
		printf("%d\n", sum);
	}
	return 0;
}