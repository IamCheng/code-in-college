#include<stdio.h>
#include<string.h>
int main()
{
	char ch[27][27], c[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int m, n;
	scanf("%d%d", &m, &n);
	c[n] = 0;
	for(int i = 0; i < m; i++)
	{		
		strcpy(ch[i]+i, c);
		ch[i][n] = 0;
		for(int j = 0; j < i && j < n; j++)
			ch[i][j] = 'A' + i - j;
		printf("%s\n", ch[i]);
	}	
	return 0;
}