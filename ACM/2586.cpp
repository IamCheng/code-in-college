#include<stdio.h>
int main()
{/*
 ++++-++++-++
 +++--+++--++
 ++---++---++
 +----+----+-
 ------------
 */
	int s,d,tmp;
	while(scanf("%d%d",&s,&d) != EOF)
	{
		float i = (float)s/(float)d;
		if(i > 4)
			tmp = -1;
		else
		if( i < 0.25)
			tmp = s*10 - 2*d;
		else
		if( i < (float)2/(float)3)
			tmp = 8*s - 4*d;
		else
		if(i < 1.5)
			tmp = 6*s - 6*d;
		else
			tmp = 3*s - 9*d;
		if(tmp > 0)
			printf("%d\n",tmp);
		else
			printf("Deficit\n");
	}
	return 0;
}