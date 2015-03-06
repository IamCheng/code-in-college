#include<stdio.h>
#include<string.h>
int mp[10][10], pos[10] = {0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
bool r[10][11], c[10][11], k[4][14][14];

int DFS(int r_crt, int c_crt)
{
	if(r_crt == 10)
	{
		for(int i = 1; i <= 9; i++)
		{
			for(int j = 1; j <= 9; j++)
				printf("%d", mp[i][j]);
			printf("\n");
		}
		return 1;//返回1代表结束
	}
	for(int i = c_crt; i <= 9; i++)
	{
		if(mp[r_crt][i] != 0)	continue;
		for(int j = 1; j <= 9; j++)
		{
			int rr = pos[r_crt], cc = pos[i];
			if(!r[r_crt][j] && !c[i][j] && !k[rr][cc][j])
			{
				mp[r_crt][i] = j;
				r[r_crt][j] = c[i][j] = k[rr][cc][j] = true;
				if(DFS(r_crt, i+1) != 0)
					return 1;
				mp[r_crt][i] = 0;
				r[r_crt][j] = c[i][j] = k[rr][cc][j] = false;
			}
			if(j == 9)	return 0;
		}
	}
	DFS(r_crt+1, 1);	
	return 0;
}
int main()
{
	char ch[12];
	for(int i = 1; i <= 9; i++)
	{
		scanf("%s", ch);
		for(int j = 1; j <= 9; j++)
		{
			int p = mp[i][j] = ch[j-1] - '0';
			k[pos[i]][pos[j]][p] = r[i][p] = c[j][p] = true;
		}
	}
	DFS(1, 1);
	return 0;
}
