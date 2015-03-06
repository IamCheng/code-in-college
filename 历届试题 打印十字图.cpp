#include<stdio.h>
const int maxn = 50;
char map[maxn][maxn];
int main()
{
	int n, mid;
	scanf("%d", &n);
	mid = 3 + n * 2;
	int x = 1, y = 3, xx, yy;
	for(int i = 1; i <= n + 1; i++)
	{	
		for(yy = y; yy <= mid; yy++)
		{
			map[x][yy] = 1;
		}
		map[x][y] = 1;
		map[x+1][y] = 1;
		map[x+2][y] = 1;
		map[x+2][y-1] = 1;
		map[x+2][y-2] = 1;
		for(xx = x + 2; xx <= mid; xx++)
			map[xx][y-2] = 1;
		x += 2;
		y += 2;
	}
	for(x = 1; x <= mid; x++)
	{
		for(y = 1; y <= mid; y++)
			printf("%c", map[x][y] == 1 ? '$' : '.');
		for(y = mid - 1; y > 0; y--)
			printf("%c", map[x][y] == 1 ? '$' : '.');
		printf("\n");
	}
	for(x = mid - 1; x >= 1; x--)
	{
		for(y = 1; y <= mid; y++)
			printf("%c", map[x][y] == 1 ? '$' : '.');
		for(y = mid - 1; y > 0; y--)
			printf("%c", map[x][y] == 1 ? '$' : '.');
		printf("\n");
	}
	printf("\n");
	return 0;
}
