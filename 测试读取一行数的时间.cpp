#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	freopen("1.txt", "r", stdin);
	//freopen("2.txt", "w", stdout);
	double s = clock();
	char ch[100000],*p,*q;
	gets(ch);
	q = p = ch;
	while((*p) != 0)
	{
		if((*p) == ' ')	
		{
			*p = 0;
			int i = atoi(q);
			p = q = p + 1; 
		}
		p++;

	}
	for(int k = 0; k < 100000000; k++);
	printf("\n%lf\n", clock()-s);
	s = clock();
	char c;
	int a[100];
	for(int i = 0; i < 100; i++) 
	{
		scanf("%d%c",&a[i],&c);
		if(c == 10)
			break;
	}
	for(int j = 0; j < 100000000; j++);
	printf("\n%lf\n", clock()-s);
	return 0;
}