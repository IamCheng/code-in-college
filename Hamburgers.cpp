#include<stdio.h>
#include<string.h>
__int64 max = 10000000000000000;
__int64 a[3], N[3], p[3], rr; 
__int64 min(__int64 a, __int64 b)
{
	return a > b ? b : a;
}
__int64 cal(int n)
{
	if(a[n] == 0)
	{
		p[n] = 0;
		return max;
	}
	return N[n]/a[n]; 
}
__int64 solve()
{
	__int64 l = 0, r = rr, sum;
	__int64 mid = r/2;
	while(l < r)
	{
		sum = 0;
		for(int i = 0; i < 3; i++)
			if(mid*a[i]-N[i] >= 0)
				sum += (mid*a[i]-N[i])*p[i];
		if(sum <= rr)
			l = mid + 1;
		else
			r = mid ;
		mid = (l + r) / 2;
	}
	sum = 0;
	for(int i = 0; i < 3; i++)
		if(l*a[i]-N[i] >= 0)
				sum += (l*a[i]-N[i])*p[i];
	if(sum <= rr)
		return l;
	return l-1;
}
int main()
{
	__int64 i;
	char ham[110];
	scanf("%s", ham);
	for(i = 0; i < strlen(ham); i++)
	{
		switch(ham[i])
		{
		case 'B':a[0]++;break;
		case 'S':a[1]++;break;
		case 'C':a[2]++;break;
		}
	}

	for(i = 0; i < 3; i++)
		scanf("%d", &N[i]);
	for(i = 0; i < 3; i++)
		scanf("%d", &p[i]);
	scanf("%I64d", &rr);

	__int64 ans = min(cal(0), min(cal(1), cal(2)));
	for(i = 0; i < 3; i++)
		N[i] -= ans * a[i];	
	
	ans += solve();
	printf("%I64d\n", ans);
	return 0;
}