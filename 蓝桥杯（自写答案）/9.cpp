#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int g[4][4] = 
{ 
	{ 0, 1 , 3 , 5},
	{9 , 0 , 7 , 4},
	{7 , 3 , 0,  2},
	{5 , 6 ,8 , 0 }
};
void main()
{
	int i;
	int win = 0;
	int r1,r2,r3,r4;
	int tmp;
	srand(time(0));
	for(i = 0;i < 100000; i++)
	{
		r1 = rand()%3+1;
		tmp = (rand()%10+1);
		if( tmp <= g[0][r1] )
		{
			do
			{
				r2 = rand()%3+1;
			}
			while(r2 == r1);
			r3 = 6 - r2 -r1;
			tmp = (rand()%10+1);
			if( tmp >= g[r2][r3] )
				r2 = r3;
			tmp = (rand()%10+1);
			if( tmp <= g[0][r2] )
			{
				win++;
			}
		}		
	}
	printf("%f\n",(float)win/100000);
}