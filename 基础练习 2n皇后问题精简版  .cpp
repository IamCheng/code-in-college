#include<stdlib.h>
#include<stdio.h>
#include<string.h>
const int maxn = 9;
int map[maxn][maxn], n, tot = 0;
void sign(int row, int c)
{
	for(int j = row; j < n; j++)
		map[j][c] = -1;//当前坐标下面的列
	for(int lr = row, lc = c; lc >= 0 && lr < n; lr++, lc--)//左下对角线
		map[lr][lc] = -1;
	for(int rr = row + 1, rc = c + 1; rr < n && rc < n; rr++, rc++)//右下对角线
		map[rr][rc] = -1;
}
int B_srch(int row , int col)
{	
	if(row + 1 > n)
	{
		tot++;
		return 0;
	}
	int tmp[maxn][maxn];
	memcpy(tmp, map, sizeof(map));
	for(int c = 0; c < n; c++)
	{
		if(map[row][c] < 1)
			continue;
		sign(row, c);
		B_srch(row+1, c);
		memcpy(map, tmp, sizeof(tmp));
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	B_srch(0, 0);
	printf("%d\n", tot*(tot-1));
	return 0;
}
