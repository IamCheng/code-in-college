// 1000000
#include<stdio.h>
#include<string.h>
const int maxn = 1000010;
int num[maxn], nn[maxn];
int jd(const int & n, int & next)
{
	int tmp = n, p = 0;
	while(tmp / 10 > 0)
	{
		p += tmp % 10;
		tmp /= 10;
	}
	p += tmp;
	if(nn[p] <= 0)
	{
		num[n] = ++next;
		nn[n] = -1;
	}
	else
		num[n] = next;
	return 0;

}
int main()
{
	int i;
	num[1] = 1;
	for(i = 2; i * i < maxn; i++)
	{
		if(num[i] == 1)
			continue;
		for(int j = i; i * j < maxn; j++)
			if(num[i*j] != 1)
				num[i*j] = 1;
			else
				continue;
	}
	int next = 0;
	memcpy(nn, num, sizeof(num));
	for(i = 1; i < maxn; i++)
	{
		if(num[i] == 0)
			jd(i, next);
		else
			num[i] = next;
	}
	int T;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		int l, r, tot = 0;
		scanf("%d%d", &l, &r);
		if(nn[l] == -1)
			tot = num[r] - num[l] + 1;
		else
			tot = num[r] - num[l];
		printf("Case #%d: %d\n", i, tot);
	}
	return 0;
}