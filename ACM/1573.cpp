#include<stdio.h>
#include<string.h>
int main()
{
	char map[11][11],m[11][11];
	int row,col,f,i,flag,rr,cc;
	while(1)
	{		
		flag = 0;
		scanf("%d%d%d",&row, &col, &f);
		int r = 0,c = f - 1;
		if(0 == row && 0 == col)
			break;
		for(i = 0; i < row; i++)
			scanf("%s",map[i]);
		memset(m,0,sizeof(m));	
		i = 1;
		while(flag == 0)
		{	
			rr = r;
			cc = c;
			switch(map[r][c])
			{
			case 'E':				
				if( c + 1 >= col)
					flag = 1;
				else
				{
					m[r][c] = i++;
					if(m[r][++c] > 0)
						flag = 2;
				}
				break;
			case 'N':
				if( r - 1 < 0 )
					flag = 1;
				else
				{
					m[r][c] = i++;
					if(m[--r][c] > 0)
						flag = 2;
				}
				break;
			case 'W':
				if( c - 1 < 0)
					flag = 1;
				else
				{
					m[r][c] = i++;
					if(m[r][--c] > 0)
						flag = 2;
				}break;
			case 'S':
				if( r + 1 >= row)
					flag = 1;
				else
				{
					m[r][c] = i++;
					if(m[++r][c] > 0)
						flag = 2;
				}break;
			}
		}
		if(1 == flag)
			printf("%d step(s) to exit\n",i);
		else
			printf("%d step(s) before a loop of %d step(s)\n",m[r][c] - 1,m[rr][cc] - m[r][c] + 1 );

	}
	return 0;
}