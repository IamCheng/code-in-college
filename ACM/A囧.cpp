#include<stdio.h>
#include<string.h>
char map[1000][512];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, cnt = 0, i, j;
		scanf("%d", &n);
		int r = 0, c = 0, len = 2 << n;
		memset(map, 0, sizeof(map));
		for(i = n; i >= 0; i--)
		{
			r += cnt;
			c += (cnt>>1);
			map[r][c] = '+';
			for(int j = c+1; j < len+1; j++)
				map[r][j] = '-';
			for(j = r+1; j < len << 1; j++)
				map[j][c] = '|';
			map[(len<<1)-1][c] = '+';
			cnt = 2 << i;

			int rr, cc;
			for(rr = r + (cnt >> 1), cc = c + (cnt >> 1); map[rr][cc] != '|'; rr++, cc--)
				map[rr][cc] = '/';
			map[rr-1][cc+1] = 0;
			for(rr = r + (cnt >> 1), cc = c + (cnt >> 1); map[rr][cc] != '-'; rr--, cc++)
				map[rr][cc] = '/';
			map[rr+1][cc-1] = 0;
		}
		for(i = 0; i <= len; i++)
			map[(len<<1)-1][i] = map[(len<<1)-1][i] == '+' ? '+' : '-';
		for(j = 0; j < (len << 1); j++)
		{
			for(i = 0; i < len; i++)
				printf("%c", map[j][i] ? map[j][i] : ' ');
			for(i = len-1; i >= 0; i--)
				printf("%c", map[j][i] ? (map[j][i] == '/') ? '\\' : map[j][i] : ' ');
			printf("\n");
		}
	}
	return 0;
}