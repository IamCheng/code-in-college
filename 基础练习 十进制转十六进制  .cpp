#include<stdio.h>
int main()
{
char in[9];
scanf("%s", in);
unsigned int sum = 0;
int i = 0;
while(in[i]!=0)
	sum = sum * 16 + (in[i] >= 'A' ? (in[i++] - 'A' + 10) : (in[i++] - '0'));
printf("%u\n", sum);
return 0;
}