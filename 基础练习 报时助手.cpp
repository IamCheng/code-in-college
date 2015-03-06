#include<stdio.h>
int main()
{
	char num[21][10] = {"zero", "one", "two", "three", "four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" ,"ten" ,"eleven" ,"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,"sixteen" ,"seventeen" ,"eighteen" ,"nineteen" ,"twenty" };
	char tens[6][10] ={"", "", "twenty","thirty", "forty", "fifty"};
	int h, m;
	scanf("%d%d", &h, &m);
	if(m == 0)
		printf("%s o'clock\n", num[h]);
	else
	{
		int t= h / 10, tt = h % 10, a = m / 10, b = m % 10;
		if(t == 2)
		{
			printf("%s ", tens[2]);
			if(tt > 0)
				printf("%s ", num[tt]);
		}
		else
			printf("%s ", num[h]);
		if(a >= 2) 
		{
			printf("%s", tens[a]);
			if(b > 0)
				printf(" %s\n", num[b]);
		}
		else
			printf("%s\n", num[m]);
	}
	return 0;
}