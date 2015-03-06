#include<stdio.h>
int main()
{
	int ans = 0;
	//ab*cde = adb*ce;
	for(int a = 1; a <= 9; a++)
	{
		for(int b = 1; b <= 9; b++)
		{
			if(a == b)
				continue;
			for(int c = 1; c <= 9 ; c++)
			{
				if(c == b || c == a)
					continue;
				for(int d = 1; d <= 9 ; d++)
				{
				
					if(d == a || d == b || d == c)
						continue;
					for(int e = 1; e <= 9; e++)
					{
						if(e == d || e == c || e == b || e == a)
							continue;
						if((a*10+b)*(c*100+d*10+e) == (a*100+d*10+b) * ((10 * c) + e))
							ans++;

					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}