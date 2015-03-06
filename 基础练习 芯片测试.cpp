#include<stdio.h>

int main()
{
	int n, num[21][21], i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &num[i][j]);
	for(i = 0; i < n; i++)
	{
		int t = 0;
		for(int j = 0; j < n; j++)
		{
			if(num[i][j] == 1)
				t++;
		}
		if(t <= n / 2)
			continue;
		else
		{
			int tt = 0;
			for(int k = 0; k < n; k++)
				if(num[k][i] == 1) tt++;
			if(tt > n / 2)
				printf("%d ", i+1);
		}
	}
	return 0;
}