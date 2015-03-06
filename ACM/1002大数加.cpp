#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d", &n);
	for(int t = 1; t <= n; t++)
	{
		char a[1005], b[1005];
		scanf("%s %s", a, b);
		printf("Case %d:\n", t);
		printf("%s + %s = ", a, b);
		if(strlen(a) < strlen(b))
		{
			char c[1005];
			strcpy(c, a);
			strcpy(a, b);
			strcpy(b, c);
		}
		int aa = strlen(a), bb = strlen(b), i;
		for(i = 0; i < aa; i++)
		{
			a[i] -= '0';
			b[i] -= '0';
		}
		int adc = 0, out = aa;		
		for(bb--, aa--; aa >= 0; bb--, aa--)
		{	
			int tmp;
			if(bb >= 0)
			{
				tmp = (a[aa] + b[bb] + adc) % 10;
				adc = (a[aa] + b[bb] + adc) / 10;
			}
			else
			{
				tmp = (a[aa] + adc) % 10;
				adc = (a[aa] + adc) / 10;			
			}
			a[aa] = tmp;
		}
		if(adc > 0)
			printf("%d", adc);
		for(i = 0; i < out; i++)
			printf("%d", a[i]);
		printf("\n");
		if(t != n)
			printf("\n");
	}
	return 0;
}
