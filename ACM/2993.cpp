#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,x,y;
	char c[100],ch;
	char m[][34]=
	{
		"+---+---+---+---+---+---+---+---+",
		"|...|:::|...|:::|...|:::|...|:::|",
		"+---+---+---+---+---+---+---+---+",
		"|:::|...|:::|...|:::|...|:::|...|",
		"+---+---+---+---+---+---+---+---+",
		"|...|:::|...|:::|...|:::|...|:::|",
		"+---+---+---+---+---+---+---+---+",
		"|:::|...|:::|...|:::|...|:::|...|",
		"+---+---+---+---+---+---+---+---+",
		"|...|:::|...|:::|...|:::|...|:::|",
		"+---+---+---+---+---+---+---+---+",
		"|:::|...|:::|...|:::|...|:::|...|",
		"+---+---+---+---+---+---+---+---+",
		"|...|:::|...|:::|...|:::|...|:::|",
		"+---+---+---+---+---+---+---+---+",
		"|:::|...|:::|...|:::|...|:::|...|",
		"+---+---+---+---+---+---+---+---+"
	};
	for(i = 1; i <= 2; i++)
	{
		gets(c);
		for(j = 7;j <=strlen(c); j += 4)
		{
			ch = c[j];
			if(c[j] >= 'a')
				break;
			y = c[j+1] - 96;
			x = 9 - ( c[j+2] - '0');
			if( 2 == i)
				ch = ch + 32;
			x = 2 * x - 1;
			y = 4 * y -2;
			m[x][y] = ch;
		}
		for(;j<=strlen(c); j += 3)
		{
			y = c[j] - 96;
			x = 9 - ( c[j+1] - '0');
			x = 2 * x - 1;
			y = 4 * y -2;
			if(2 == i)
				m[x][y] = 'p';
			else
				m[x][y] = 'P';
		}
	}
	for(i = 0; i < 17 ;i++)
		printf("%s\n",m[i]);
	return 0;
}