#include<stdio.h>
int main()
{
	int a, b, c, tmp;
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		tmp = c;
		printf("%d", a/b);
		a = a % b;
		if(c == 0)	printf("\n");
		while(c--)
		{
			if(tmp - 1 == c)
				printf(".");	
			if(c == 0)
			{
				tmp = a * 10 / b;
				if((a * 10 % b) * 10 / b >= 5)
					tmp++;
				printf("%d\n", tmp);
				break;
			}	
			a *= 10;
			printf("%d", a/b);	
			a %= b;	
		}
	}

	return 0;
}