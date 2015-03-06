#include<stdio.h>
const int maxn = 10010;
int num[maxn];
bool first = true;;
int depart(int x, int ss[])
{
	if(x == 1)
		return 0;
	int t = 0;
	while(1)
	{
		if(x % ss[t] == 0)
		{
			if(first)
			{
				first = false;
				printf("%d", ss[t]);
			}
			else
				printf("*%d", ss[t]);
			depart(x/ss[t], ss);
			return 0;
		}
		t++;
	}
}

int main()
{
	int a, b, i;
	scanf("%d%d", &a, &b);
	num[1] = 1;
	for(i = 2; i * i < b; i++)
	{
		if(num[i] == 1)
			continue;
		for(int j = i; i * j < maxn; j++)
			if(num[i*j] != 1)
				num[i*j] = 1;
			else				
				continue;			
	}
	int ss[2000], t = 0;
	for(i = 2; i <= b; i++)
		if(num[i] == 0)	ss[t++] = i;

	for(i = a; i <= b; i++)
	{
		first = true;
		if(num[i] == 0)
			printf("%d=%d\n", i, i);
		else
		{
			printf("%d=", i);
			depart(i, ss);
			printf("\n");
		}
	}
	return 0;
}