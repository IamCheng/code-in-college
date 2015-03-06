#include<stdio.h>
char map[10][10];
int N, M, T;
struct Queue
{
	int r, c;
}node[100], crt;
int BFS()
{
	int front = 0, rear = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
			if(map[i][j] == 'S'){node[rear].r =i; 	node[rear++].c = j;map[i][j] = 0;break;}
		if(map[i][j] == 'S')	break;
	}
	while(front != rear)
	{
		crt = node[front++];

		if(crt.r > 1)
		{	
			if(map[crt.r-1][crt.c] == 'D' && T >= map[crt.r][crt.c] + 1)
				return 1;
			if(map[crt.r-1][crt.c] == '.')
			{	
				node[rear].r = crt.r - 1;
				node[rear++].c = crt.c;
				map[crt.r - 1][crt.c] = map[crt.r][crt.c] + 1;
			}
		}
		if(crt.r < N)
		{
			if(map[crt.r+1][crt.c] == 'D' && T >= map[crt.r][crt.c] + 1)
				return 1;
			if(map[crt.r+1][crt.c] == '.')
			{	
				node[rear].r = crt.r + 1;
				node[rear++].c = crt.c;
				map[crt.r+1][crt.c] = map[crt.r][crt.c] + 1;
			}
		}
		if(crt.c > 1)
		{
			if(map[crt.r][crt.c-1] == 'D' && T >= map[crt.r][crt.c] + 1)
				return 1;
			if(map[crt.r][crt.c-1] == '.')
			{	
				node[rear].r = crt.r;
				node[rear++].c = crt.c - 1;
				map[crt.r][crt.c-1] = map[crt.r][crt.c] + 1;
			}
		}
		if(crt.c < M)
		{
			if(map[crt.r][crt.c+1] == 'D' && T >= map[crt.r][crt.c] + 1)
				return 1;
			if(map[crt.r][crt.c+1] == '.')
			{	
				node[rear].r = crt.r;
				node[rear++].c = crt.c + 1;
				map[crt.r][crt.c+1] = map[crt.r][crt.c] + 1;
			}
		}
	}
	return 0;

}
int main()
{
	while(scanf("%d%d%d", &N, &M, &T) == 3 && N && M && T)
	{	
		for(int i = 1; i <= N; i++)
			scanf("%s", map[i]+1);
		if(BFS())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
