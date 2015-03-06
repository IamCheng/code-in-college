#include<stdio.h>
#include<string.h>
int main()
{
	char in[1000005];
	bool flag = false;
	while(gets(in))
	{	

		flag = true;
		int num[26] = {0};
		for(int i = 0; i < strlen(in); i++)
		{
			if(in[i] >= 'a' && in[i] <= 'z')
				num[in[i]-'a']++;
		}
		for(int j = 0; j < 26; j++)
			printf("%c:%d\n", 'a'+j, num[j]);
	printf("\n");
	}
	return 0;
}