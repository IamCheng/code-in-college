#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<bitset>
using namespace std;
struct bitset
{
	unsigned int b[626];
	int n;
	bitset operator | (bitset a)
	{
		int len = n / 32;
		bitset c;
		for(int i = 1; i <= len+1; i++)
			c.b[i] = a.b[i] | b[i];
		return c;
	}
}bit[20000];
int main()
{	
	freopen("lj.out", "w", stdout);
	int i, N = 20000;
	for(i = 1; i <= N; i++)
		{
			int ans = 0;
			for(int j = 1; j <= N; j++)
			{
				int l, t = j / 8;
				if(j % 8 == 0)
				{
					l = 8;
				}
				else
					l = j % 8;
				if(bit[i].b[t] & (1 << (l-1)))
				{
					ans += 1;
				}
			}
			if(i == 1)
				printf("%d", ans);
			else
				printf(" %d", ans);
		}
}