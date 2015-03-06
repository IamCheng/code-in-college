#include<stdio.h>
int gcd(int x, int y)
{
	if(x < y)
		return gcd(y, x);
	if(x == y)
		return y;
	if(x % 2 == 0)
	{
		if(y % 2 == 0)
			return gcd(x >> 1, y >> 1) << 1;
		else
			return gcd(x >> 1, y);
	}
	else
	{
		if(y % 2 == 0)
		{
			return gcd(x, y >> 1);
		}
		else
		{
			return gcd(y, x-y);
		}
	}
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int tmp = a / gcd(a, b) * b;
	int ans = c / gcd(tmp, c) * tmp;
	printf("%d\n", ans);
	return 0;
}