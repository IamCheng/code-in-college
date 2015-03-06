#include<stdio.h>
#include<string.h>
int sum_of_months[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int main()
{
	char in[20];
	while(scanf("%s", in) != EOF)
	{
		//1985/1/2
		int num[3] = {0}, t = 0;
		for(int i = 0; i < strlen(in); i++)
		{
			if(in[i] != '/')
				num[t] = 10 * num[t] + in[i] - '0';
			else
				t++;
		}
		if(num[0] % 400 == 0 || (num[0] % 4 == 0 && num[0] % 100 != 0))
			t = 1;
		else
			t = 0;
		int total = sum_of_months[num[1]] + num[2];
		if(num[1] > 2)
			printf("%d\n", total+t);
		else
			printf("%d\n", total);
	}
	return 0;
}
