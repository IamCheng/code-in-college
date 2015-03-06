#include<stdio.h>
#include<string.h>
typedef struct
{
	int x,y;
}crd;	
crd w[9][9],b[9][9];
char map[9][9],ww[9] = {' ','K','Q','R','B','N','P'};
int num[10],num1[10];
int srch()
{
	int i,tmp,j,tmp1;
	for(i = 1; i <= 8; i++)
		for(j = 1; j<=8; j++)
		{
			tmp = 0;
			tmp1 = 0;
			switch(map[i][j])
			{
				case 'k':tmp1 = 1;num1[1]++;break;
				case 'q':tmp1 = 2;num1[2]++;break;
				case 'r':tmp1 = 3;num1[3]++;break;
				case 'b':tmp1 = 4;num1[4]++;break;
				case 'n':tmp1 = 5;num1[5]++;break;
				case 'p':tmp1 = 6;num1[6]++;break;
			}					
			if( tmp1 > 0 )
			{
				b[tmp1][num1[tmp1]].x = i;
				b[tmp1][num1[tmp1]].y = j;
			}
			switch(map[9-i][j])
			{
				case 'K':tmp = 1;num[1]++;break;
				case 'Q':tmp = 2;num[2]++;break;
				case 'R':tmp = 3;num[3]++;break;
				case 'B':tmp = 4;num[4]++;break;
				case 'N':tmp = 5;num[5]++;break;
				case 'P':tmp = 6;num[6]++;break;
			}
			if(tmp > 0)
			{
				w[tmp][num[tmp]].x = 9 - i;
				w[tmp][num[tmp]].y = j;
			}
		}
		return 1;
}
int print()
{
	int i,j;
	printf("White: ");
	for(i = 1; i < 6; i++)
		if(num[i] > 0)
			for(j = 1; j <= num[i]; j++)
				printf("%c%c%d,",ww[i],96+w[i][j].y,9-w[i][j].x);
	for(i = 1;i < num[6]; i++)
		printf("%c%d,",96+w[6][i].y,9-w[6][i].x);
	printf("%c%d\n",96+w[6][i].y,9-w[6][i].x);
	printf("\n");
	printf("Black: ");
	for(i = 1; i < 6; i++)
		if(num1[i] > 0)
			for(j = 1; j <= num1[i]; j++)
				printf("%c%c%d,",ww[i],96+b[i][j].y,9-b[i][j].x);
	for(i = 1;i < num[6]; i++)
		printf("%c%d,",96+b[6][i].y,9-b[6][i].x);
	printf("%c%d\n",96+b[6][i].y,9-b[6][i].x);
	printf("\n");


	return 1;
}
int main()
{
	int i = 0,j,k;
	memset(w,0,sizeof(w));
	memset(b,0,sizeof(b));
	char c[50];
	for(i = 1; i <= 17; i++)
	{
		int tmp = 2;
		scanf("%s",c);
		j = i/2;		
		if( i%2 == 0)
			for(k = 1; k <= 8; k++)
			{
				map[j][k] = c[tmp];
				tmp += 4;
			}
	}
	srch();
	print();
return 0;
}