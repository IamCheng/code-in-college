#include<stdio.h>
bool judge(__int64 t)
{
	
	__int64 sum = 0;
	bool f = false;
	do
	{
		if(f = !f)
			sum += t % 10;
		else
			sum -= t % 10;
	}while(t /= 10);
	return sum != 3;
	
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		__int64 l, r;
		scanf("%I64d%I64d", &l, &r);
		if(l % 11 <= 3)
			l = l / 11 * 11 + 3;
		else
			l = (l / 11 + 1) * 11 + 3;
		while(l < r && !judge(l))
			l += 11;
		printf("%I64d\n", l <= r && judge(l) ? l: (__int64)-1);
	}
	return 0;
}

