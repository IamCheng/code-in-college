#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int map[9][9];
int n, tot = 0;
int W_srch(int row, int col)
{
	if(row + 1 == n)
	{
		tot++;
		return 0;
	}
	int tmp[9][9];
	memcpy(tmp, map, sizeof(map));
	for(int j = 0; j < n; j++)
		map[j][col] = 2;
	map[row][col] = 3;
	for(int lr = row + 1, lc = col - 1; lr < n && lc >= 0; lr++, lc--)//左下对角线
		map[lr][lc] = 2;
	for(int rr = row + 1, rc = col + 1; rr < n && rc < n; rr++, rc++)//右下对角线
		map[rr][rc] = 2;
	for(int c = 0; c < n; c++){
		if(map[row+1][c] == 1 || map[row+1][c] == -1)
			W_srch(row+1, c);
		else
			continue;
	}	
	memcpy(map, tmp, sizeof(tmp));
	return 0;
}
int B_srch(int row , int col)
{

	int tmp[9][9];
	memcpy(tmp, map, sizeof(map));
	for(int j = 0; j < n; j++)
		if(map[j][col]!=0)	map[j][col] = -1;
	map[row][col] = -2;
	for(int lr = row + 1, lc = col - 1; lc >= 0 && lr < n; lr++, lc--)//左下对角线
		if(map[lr][lc] != 0)	map[lr][lc] = -1;
	for(int rr = row + 1, rc = col + 1; rr < n && rc < n; rr++, rc++)//右下对角线
		if(map[rr][rc] != 0)	map[rr][rc] = -1;
	if(row + 1 == n)
	{
		int wmap[9][9];
		memcpy(wmap, map, sizeof(map));
		for(int c = 0; c < n; c++)
		{
			memcpy(map, wmap, sizeof(wmap));
			if(map[0][c] == -1 || map[0][c] == 1)
				W_srch(0,c);
		}
		memcpy(map, wmap, sizeof(wmap));
		return 0;
	}
	for(int c = 0; c < n; c++){
		if(map[row+1][c] < 1)
			continue;
		B_srch(row+1, c);
	}
	memcpy(map, tmp, sizeof(tmp));
	return 0;
}
int solve()
{	 
	int mm[9][9];
	memcpy(mm, map, sizeof(mm));
	for(int i = 0; i < n; i++)
	{
		memcpy(map, mm, sizeof(mm));
		if(map[0][i] < 1)
			continue;
		B_srch(0, i);
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	solve();
	printf("%d\n", tot);
	return 0;
}
	
