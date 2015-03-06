#include<stdio.h>
int main(void)
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		int tot = 0;
		for(int i = 0; i <= n / 3; i++)
			tot += (n - i * 3) / 2 + 1;
		printf("%d\n", tot);
	}
    return 0;
}