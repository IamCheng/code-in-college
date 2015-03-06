#include<stdio.h>
#include<string.h>
int main()
{
	int c[101], n, i, j;
	while(scanf("%d", &n) == 1 && n)
	{
		int flag = 0;
		memset(c , 0, sizeof(c));
		for(i = 0; i < n; i++) 
		{
			scanf("%d", &j);
			c[j]++;
		}
		for(i = 0; i <= 100; i++)
			for(j = 0; j < c[i]; j++)
				if(flag)
					printf(" %d", i);
				else
				{	
					flag = 1;
					printf("%d", i);
				}
		printf("\n");
	}
	return 0;
}