#include<stdio.h>
#include<string.h>
const int maxn = 1000010;
int num[maxn] = {0,1};
int extra(int n)
{
	for(int p = n % 10; (n = n / 10) > 0; p += n % 10);
	return p;	
}
int jd(int n)
{
	if(n == 1)	return 0;
	for(int j = 2; j * j <= n; j++)
		if(n % j == 0)	return 0;
	return 1;
}
int main()
{
	int i;
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
	for(i = 1; i < maxn; i++)
		if(num[i] == 0 && num[extra(i)] <= 0)
				num[i] = -1;
	int nt = 0;
	for(i = 1; i < maxn; i++)
		num[i] = (num[i] == -1) ? ++nt : nt;
	int T;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int tot = num[r] - num[l];
		if(jd(l) && jd(extra(l)))
			tot++;			
		printf("Case #%d: %d\n", i, tot);
	}
	return 0;
}