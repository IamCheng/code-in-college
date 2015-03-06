#include<stdio.h>
const int maxn = 100000; 
int num[maxn], de[maxn], in[maxn];
int main()
{
	int n = 0, in_max = 0, de_max = 0;
//	scanf("%d", &n);
//	for(int i = 0; i < n; i++)
	while(scanf("%d", &num[n++]) == 1);

	for(int j = 1; j < n - 1; j++)
	{
		for(int i = 0; i < j; i++)
		{
			if(num[j] <= num[i])
			{
				if(de[i] + 1 > de[j])
					de[j] = de[i] + 1;
			}
			else
			{
				if(in[i] + 1 > in[j])
					in[j] = in[i] + 1;
			}
		}
		if(de[j] > de_max)
			de_max = de[j];
		if(in[j] > in_max)
			in_max = in[j];
	}
	printf("%d\n%d\n", de_max+1, in_max+1); 
	return 0;
}