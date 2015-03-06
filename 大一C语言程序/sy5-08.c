#include<stdio.h>
void main()
{
	int i,n,m;
	i=1;
		for(i=1;i<10;i++)
		{
			for(n=1;n<i+1;n++)
			{m=i*n;
			printf("%d*%d=%d",i,n,m);
			
			printf(" ");
			}
			printf("\n");
	    }
}