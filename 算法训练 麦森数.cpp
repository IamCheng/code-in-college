#include<math.h>
#include<stdio.h>
#include<string.h>

#define sum(xx) ((int)floor(log(2.0)/log(10.0)*xx) + 1)
const int len = 500;
int Big_cal(char a[], char b[], int len_b)
{
	char c[501] = {0};
	for(int i = len; i > len - len_b; i--)
	{
		int adc = 0;
		int cc = i;
		for(int j = len; j >= 0; j--)
		{
		
			int tmp = c[cc] + a[j] * b[i] + adc;
			if(cc > 0)
				c[cc--] = tmp % 10;
			else
				break;
			adc = tmp / 10;
		}
	}
	memcpy(a, c, sizeof(c));

/*
	for(i = 1; i <= 500; i++)
	{
		printf("%d", a[i-1]);	
		if(i % 50 == 0)
			printf("\n");
	}
	printf("\n\n******************\n\n");*/
	return 0;

}
int cal(char ans[], int n)
{
	char b[501];
	if(n == 1)
	{
		b[500] = 2;
		Big_cal(ans, b, 1);
		return 0;
	}
	cal(ans, n/2);
	memcpy(b, ans, sizeof(char) * 501);
	Big_cal(ans, b, sum(n/2));	
	if(n % 2 != 0)
	{
		b[500] = 2;
		Big_cal(ans, b, 1);		
	}
	return 0;		
}
int main()
{
	int n;
	char ans[501];
	memset(ans, 0, sizeof(ans));
	ans[500] = 1;
	scanf("%d", &n);
	int t = (int)floor(log(2.0)/log(10.0)*n) + 1;
	printf("%d\n", t);
	cal(ans, n);
	ans[500]--;
	for(int i = 1; i <= 500; i++)
	{
		printf("%d", ans[i]);
		if(i % 50 == 0)
			printf("\n");	
	}
	return 0;
}