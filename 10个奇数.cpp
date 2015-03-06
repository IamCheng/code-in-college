#include<stdio.h>
#include<string.h>
int num[101];
int main()
{
	int n, i;
	while(1)
	{
		memset(num, 0, sizeof(num));
		for(i = 0; i < 10; i++)
		{	
			if(scanf("%d", &n) != 1)
				return 0;
			num[n]++;		
		}
		bool flag = false;
		for(i = 99; i > 0; i -= 2)
		{
			if(num[i] != 0)
			{
				for(int j = 0; j < num[i]; j++)
				{
					if(!flag)
						printf("%d", i);
					else
						printf(" %d", i);
					flag = true;
				}
			}
		}
		for(i = 0; i <= 100; i += 2)
		{
			if(num[i] != 0)
			{
				for(int j = 0; j < num[i]; j++)
				{
					if(flag == true)
						printf(" %d", i);
					else
					{
						flag = true;
						printf("%d", i);
					}
				}
			}
		}
		printf("\n");	
	}
	return 0;
}