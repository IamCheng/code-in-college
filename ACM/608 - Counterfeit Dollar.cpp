#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int flag[12];
char ch1[4][10], ch2[4][10];
char ans[][6] = {"light", "heavy"};
char ch3[6];
int insrt(int n)
{
	for(int i = 0; i < strlen(ch1[n]); i++)
	{
		if(flag[ch1[n][i]-65] == 0)
			flag[ch1[n][i]-65] = 1;
		if(flag[ch2[n][i]-65] == 0)
			flag[ch2[n][i]-65] = 1;
	}
	return 0;
}
bool isExist(int n, char * c)
{
	for(int i = 0; i < strlen(c); i++)
		if(n + 65 == c[i])
			return 1;
	return 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int num[3] = {0}, i, j, k;
		for(i = 0; i < 3; i++)
		{
			cin >> ch1[i] >> ch2[i] >> ch3;
			if(strcmp(ch3, "even") == 0)
				insrt(i);
			else
				num[i] = 1;
			if(strcmp(ch3, "up") != 0)
			{
				char tmp[10];
				strcpy(tmp, ch1[i]);
				strcpy(ch1[i], ch2[i]);
				strcpy(ch2[i], tmp);
			}
		}
		for(i = 0; i < 12; i++)
		{
			if(flag[i] == 0)
			{
				for(j = 0; j < 3; j++)
					if(num[j] == 1 && !isExist(i, ch1[j]))
						break;
				for(k = 0; k < 3; k++)
					if(num[k] == 1 && !isExist(i, ch2[k]))
						break;
				if(j == 3 || k == 3)
					break;
			}
		}
		printf("%c is the counterfeit coin and it is %s.\n", i + 65, ans[j == 3]);
		memset(flag, 0, sizeof(flag));
	}
	return 0;
}
