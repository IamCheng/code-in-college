#include<stdio.h>
int main()
{
	int n;
	char ch[9];
	scanf("%d", &n);
	sprintf(ch, "%0x", n);
	for(int i = 0; ch[i] != 0; i++)
		if(ch[i] >= 'a')	
			ch[i] = ch[i] - 'a' + 'A';
	printf("%s\n", ch);
		return 0;
}