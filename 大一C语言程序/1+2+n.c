#include<stdio.h>
int f(int n)
{
	if(n == 1)
		return 1;
	else
	return n + f(n-1);
}
void main()
{
	int n;
	scanf("%d", &n);
	printf("1+2+..+n=%d\n",f(n));
	return 0;
}
