#include<stdio.h>
int num[110];
int main()
{
	int n, m, min = 100000000, w, crt = 0, ans = 0, t = 0;
	scanf("%d%d", &n, &m);
	t = m;
	for(int i = 0; i < n + m; i++)
	{
		if(i < n)
		{
			scanf("%d", &w);
			if(min > w || min == 0)	min = w;
			if(t-- > 0)
			{
				for(int i = 0; i < m; i++)
				{
					if(num[i] == 0)
					{
						num[i] = w;
						break;
					}
				}
				if(t > 0)	continue;
			}
		}
		ans += min;
		for(int j = 0; j < m; j++)
			if((num[j] -= min)== 0)
				t++;
		min = 1000000;
		for(int k = 0; k < m; k++)
			if(min > num[k] && num[k] > 0)
				min = num[k];
		if(min == 1000000)
			min = 0;
	}
	printf("%d", ans);
	return 0;
}