#include<stdio.h>
void An_Output(int n, int t)
{
	if(n == t)
	{
		printf("sin(%d)", t);
		return ;
	}
	char c;
	c = t % 2 == 1 ? '+' : '-';
	printf("sin(%d%c", t, c);
	An_Output(n, ++t);
	printf(")");
}
void Sn_Output(int n, int t)
{
	if(n == t)
	{
		An_Output(1, 1);
		printf("+%d", t);
		return ;
	}
	printf("(");
	Sn_Output(n, t+1);
	printf(")");
	An_Output(n - t + 1, 1);
	printf("+%d", t);
}
int main()
{
	int n;
	scanf("%d", &n);
	Sn_Output(n, 1);
	return 0;
}