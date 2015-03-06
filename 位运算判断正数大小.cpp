#include<stdio.h>
void main()
{
	int a,b,j;
	j = 0x40000000;
	scanf("%d%d",&a,&b);
	while( 1)
	{
		if((a&j)^(b&j))
		{	
			if(a&j)
				printf("a´ó\n");
			else
				printf("b´ó\n");
			break;
		};
		j = j>>1;
			

	}
}