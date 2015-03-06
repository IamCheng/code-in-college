#include<stdio.h>
int print(int n)
{
	bool f = false;
	for(int i = 30; i >= 0; i--)
	{
		if(n & (1 << i))
		{
			if(!f)
			{
				if(i == 1)
				{
					printf("2");
					f = true;
					continue;
				}
				printf("2(");
				if(i == 0 || i == 2)
					printf("%d", i);
				else
					print(i);
				printf(")");
				f = true;
			}
			else
			{
				if(i == 1)
				{
					printf("+2");
					continue;
				}
				printf("+2(");
				if(i == 0 || i == 2)
					printf("%d", i);
				else
					print(i);
				printf(")");
			}
		}
	}
		return 0;
}
int main()
{
	int N;
	scanf("%d", &N);
	print(N);
	return 0;
}