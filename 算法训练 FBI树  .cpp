#include<stdio.h>
#include<string.h>
char B[1100] , I[1100];
char FBI[3] = {'B', 'I', 'F'};
int check(const char ch[], int n)
{
	if(strncmp(ch, B, n) == 0)
		return 0;
	if(strncmp(ch, I, n) == 0)
		return 1;
	return 2;
}
int build(char ch[], int n)
{
	if(n == 0)
		return 0;
	int type = check(ch, n);
	build(ch, n/2);
	build(ch+n/2, n/2);
	printf("%c", FBI[type]);
	return 0;
}
int main()
{
	char ch[1100];
	int N;
	for(int i = 0; i < 1099; i++)
	{
		B[i] = '0';
		I[i] = '1';
	}
	scanf("%d", &N);
	scanf("%s", ch);
	build(ch, strlen(ch));
	return 0;
}