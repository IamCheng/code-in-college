#include<stdio.h>
#include<string.h>
const  int maxn = 8100;
char ch[maxn];
int main()
{
	while(scanf("%s", ch) != EOF)
	{
		for(int j = 0; ch[j] != 0; j++)
		{
			char tmp;
			if(ch[j] == 'A')
			{
				tmp = ch[j+5];
				ch[j+5] = 0;
				if(strcmp(ch+j, "Apple") == 0)
					printf("MAI MAI MAI!\n");
				ch[j+5] = tmp;
			}
			if(ch[j] == 'i')
			{
				int flag = 0;
				tmp = ch[j+6];
				ch[j+6] = 0;
				if(strcmp(ch+j, "iPhone") == 0)	flag = 1;
				ch[j+6] = tmp;
				tmp = ch[j+4];
				ch[j+4] = 0;
				if(strcmp(ch+j, "iPad") == 0 || strcmp(ch+j, "iPod") == 0)	flag = 1;
				ch[j+4] = tmp;
				if(flag)	printf("MAI MAI MAI!\n");	
			}
			if(ch[j] == 'S')
			{
				tmp = ch[j+4];
				ch[j+4] = 0;
				if(strcmp(ch+j, "Sony") == 0)
					printf("SONY DAFA IS GOOD!\n");
				ch[j+4] = tmp;

			}
		}
	}
	return 0;
}
