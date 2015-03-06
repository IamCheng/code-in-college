#include<stdio.h>
#include<string.h>
char ch[100010], ox[133340];
int main()
{
	int n, e[3] = {1, 16, 256};
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", ch);
		int len = strlen(ch);
		int len_ox = 133339, i;
		for(len--; len >= 0;)
		{	
			int adc = 0, sum = 0;
			for(i = 0; i < 3 &&  len >= 0; i++)
				sum += (ch[len] >= 'A') ? (ch[len--] - 'A' + 10) * e[i] : (ch[len--] - '0') * e[i];
			for(int j = len_ox ; j >= len_ox - i; j--, sum /= 8)
				ox[j] = (sum % 8) + '0';
			len_ox -= i + 1;
			
		}
		if(ox[++len_ox] == '0')
			printf("%s\n", ox+len_ox+1);
		else
			printf("%s\n", ox+len_ox);
	}
	return 0;
}