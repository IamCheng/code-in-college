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
				printf("a��\n");
			else
				printf("b��\n");
			break;
		};
		j = j>>1;
			

	}
}