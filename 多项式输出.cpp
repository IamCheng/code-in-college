#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int flag = 1;
	for(int i = n; i > 0; i--)
	{
		int x;
		scanf("%d", &x);
		if(x == 0) continue;
		if(flag == 0 && x > 0)
			printf("+");
		if(!((x != 1) ^ (x != -1)))
			printf("%d", x);
		if(x == -1)
			printf("-");
		printf("x");
		if(i != 1)
			printf("^%d", i);
		flag = 0;
	}
	scanf("%d", &n);
	if(n > 0 && flag == 0)
		printf("+");
	if(n == 0 && flag == 1)
		printf("0");
	if(n != 0)
		printf("%d", n);
	return 0;
}