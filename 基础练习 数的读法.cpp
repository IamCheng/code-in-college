#include<stdio.h>
#include<string.h>
char T[10][10]  = {" ling", " yi", " er", " san", " si", " wu", " liu", " qi", " ba", " jiu"};
char W[][10] = {" shi", "", " qian", " bai", " shi", "", " qian", " bai", " shi", ""}; 
char ans[200];
int output(int * num)
{
	int c, i;
	memset(ans, 0, sizeof(ans));
	for(i = 0;num[i] == 0; i++);
	bool flag = false;
	for(; i <= 9; i++)
	{
		if(i <= 1)
		{
			if(i == 0)
			{
				if(num[0] == 1)
					strcat(ans, " shi");
				else
				{
					strcat(ans, T[num[i]]);
					strcat(ans, " shi");
				}	
			}	
			if(i == 1)
			{
				if(num[1] != 0)
					strcat(ans, T[num[i]]);
				strcat(ans, " yi");
			}
			flag = true;
		}
		if(i >= 2 && i <= 5)
		{
			if(!flag && i == 4 && num[4] == 1)
			{
				strcat(ans, " shi");
			}
			else
			{
				if(num[i] != 0 || (num[i+1] != 0 && i < 5))
				{

					strcat(ans, T[num[i]]);	
				}
				if(num[i] != 0)
					strcat(ans, W[i]);
			}
			flag = true;
			if(i == 5 && (num[2] !=0 || num[3] != 0 || num[4] != 0 || num[5] != 0))
				strcat(ans, " wan");
		}
		if(i >= 6 && i <= 9)
		{
			if(!flag && num[8] == 1 && i == 8)
				strcat(ans, " shi");
			else
			{
				if(num[i] != 0 || (num[i+1] != 0 && i < 9))
					strcat(ans, T[num[i]]);
				if(num[i] != 0)
					strcat(ans, W[i]);
			}
	
			flag = true;
		}
	}
	printf("%s\n", ans+1);
	return 0;
}
int main()
{
	int n[10];	
	__int64 num;
	while(scanf("%I64d", &num) == 1)
	{
		for(int i = 9; i >= 0; i--)
		{
			n[i] = num % 10;
			num /= 10;
		}
		output(n);
	}
	return 0;
}
