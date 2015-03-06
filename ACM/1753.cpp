#include<stdio.h>
#include<string.h>
int c[4][4], tmp[4][4], max = 10000000;
int check(int n)
{
	int a[4][4];
	memcpy(tmp, c, sizeof(int)*4*4);
	int i, j, l =0;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
		{
			a[i][j] = (n & (1<<l))>>l;
			l++;
		}
	l = 0;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
		{
			if(a[i][j] == 1)
			{	
				l++;
				tmp[i][j] = -tmp[i][j];
				if(0 < j)	tmp[i][j-1] = -tmp[i][j-1];
				if(0 < i)	tmp[i-1][j] = -tmp[i-1][j];
				if(3 > j)	tmp[i][j+1] = -tmp[i][j+1];
				if(3 > i)	tmp[i+1][j] = -tmp[i+1][j];				
			}
		}
		int harsh[3] = {0};
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
			{
				harsh[tmp[i][j]+1]++;
				if(harsh[0] && harsh[2])
					return (l = max);
			}
		return l;
	
}
int main()
{
	int i, j;
	int ans = max;
	char t[5];
	for(i = 0; i < 4; i++)
	{
		scanf("%s", t);
		for(j = 0; j < 4; j++)
			c[i][j] = t[j]=='w' ? 1 : -1;
	}
	for(i = 0; i < (1<<16); i++)
	{
		j = check(i);
		ans = ans > j ? j : ans;
	}
	if(ans == max)
		printf("Impossible\n");
	else
		printf("%d\n", ans);
	return 0;
}