#include<stdio.h>
int num[100010];
int main()
{
	int x, t = 0, n, min = 10000000;;
	scanf("%d", &n);
	while(scanf("%d", &x) == 1)
	{
		if(x < min)	min = x;
		num[x]++;
		t++;
	}
	int q, c;
	for(int i = min; i < min + t; i++)
	{
		if(num[i] == 2)	c = i;
		if(num[i] == 0) q = i;
	}
	printf("%d %d\n", q, c);
	return 0;
}