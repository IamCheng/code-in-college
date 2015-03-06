#include<stdio.h>
int main()
{
	int n, c, x;
	scanf("%d%d", &n, &c);
	scanf("%d", &x);
	int tmp = x, max = 0;
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &x);
		if(tmp - x - c > max)
			max = tmp - x - c;
		tmp = x;
	}
	if(max >= 0)
		printf("%d\n", max);
	return 0;
}