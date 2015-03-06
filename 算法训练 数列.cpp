#include<stdio.h>
#define f(a)(b) 
int main()
{
	int k, n;
	scanf("%d%d", &k, &n);
	int i = 31, ans = 0;
	while(i--)
	{
		if(n&(1<<i))
		{
			int tmp = 1;
			for(int j = 1; j <= i; j++) 
				tmp *= k;
			ans += tmp;
		}
	}
	printf("%d\n", ans);
	return 0;
}