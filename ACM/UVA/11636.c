#include<stdio.h>
int tmp[15] =  {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
int n[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
int N = 1, t, r, l, m;
int main()
{
	while(scanf("%d", &N) == 1 && N > 0)
	{
		l = 0;
		r = 14;
		while(l != r)
		{
			m = (l + r)>>1;
			if(N == tmp[m]){l = m;break;}
			if(N > tmp[m])
				l = m + 1;
			else
				r = m;
		}
		printf("Case %d: %d\n", ++t, n[l]);
	}
	return 0;
}