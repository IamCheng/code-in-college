#include<stdio.h>
int tot;
void fill(int n)
{
	if(n == 0)	{tot++;return;};
	if(n < 0)	return;
	fill(n-1);
	fill(n-2);
}
int main()
{
	int N;
	scanf("%d", &N);
	fill(N);
	printf("%d\n", tot);
	return 0;
}
