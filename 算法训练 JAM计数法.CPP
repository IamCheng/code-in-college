#include<stdio.h>
int p[26], num;
void output()
{
	for(int i = 0; i < num; i++)
		printf("%c", p[i]+'a');
	printf("\n");
}
int main()
{
	int s, end;
	scanf("%d%d%d", &s, &end, &num);
	getchar();
	for(int i = 0; i < num; i++)
	{
		char c = getchar();
		p[i] = c - 'a';
	}
	int t = 5;
	while(t)
	{
		int crt = num - 1, tmp = end - 1;
		while(crt >= 0 && p[crt--] == tmp--);
		if(crt == -1 && p[0] == tmp + 1)
			return 0;
		p[crt] = p[++crt]++;
		while(++crt < num)
			p[crt] = p[crt-1] + 1;
		output();
	}
	return 0;
}