#include<stdio.h>
#include<string.h>
const int maxn = 5010;
char in[maxn];
int main()
{
	scanf("%s", in);
	int len = strlen(in), tot = 0, rear = 0;
	for(int i = 0; in[i] != 0; i++)
	{
		if(in[i] == 'b')
			if(in[i+1] == 'e' && in[i+2] == 'a' && in[i+3] == 'r')
			{		
				tot += (i - rear + 1) * (len - i - 3);
				rear = i + 1;
				i = i + 3;
			}
	}
	printf("%d\n", tot);
	return 0;
}
