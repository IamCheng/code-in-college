#include<stdio.h>
#include<string.h>

typedef struct
{
	int r,c;
}cdt;

int c[4][4], tmp[4][4], max = 10000000;
int ans = max;
cdt print[16];

int check(int n)
{
	int a[4][4], bt = 0;
	cdt s[16]; 
	memcpy(tmp, c, sizeof(int)*4*4);
	int i, j, l =0;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
		{
			a[i][j] = (n & (1<<bt))>>bt;
			if(a[i][j] == 1){s[l].r = i;s[l].c = j;l++;}
			bt++;
		}
	if(l > ans && ans < max)
		return max;

	for(i = 0; i < l; i++)
	{
		for(j = 0; j < 4; j++)
			tmp[s[i].r][j] = ~tmp[s[i].r][j];
		for(j = 0; j < 4; j++)
			tmp[j][s[i].c] = ~tmp[j][s[i].c];
		tmp[s[i].r][s[i].c] = ~tmp[s[i].r][s[i].c];		
	}
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)			
				if(1 != tmp[i][j])	return (l = max);
	memcpy(print, s, sizeof(cdt)*16);
	return l;	
}
int output()
{
	printf("%d\n", ans);
	for(int i = 0; i < ans; i++)
		printf("%d %d\n", print[i].r+1, print[i].c+1);
	return 0;
}
int main()
{
	int i, j;

	char t[5];
	for(i = 0; i < 4; i++)
	{
		scanf("%s", t);
		for(j = 0; j < 4; j++)
			c[i][j] = t[j]=='-' ? 1 : ~1;
	}
	for(i = 1; i < (1<<16); i++)
	{
		j = check(i);
		ans = ans > j ? j : ans;
	}
	output();
	return 0;
}
