#include<stdio.h>
#include<string.h>
int main()
{
	char a1[11], b1[11];
	scanf("%s%s", a1, b1);
	if(strlen(a1) != strlen(b1))
		printf("1\n");
	else
	{
		if(strcmp(a1, b1) == 0)
			printf("2\n");
		else
		{
			for(int i = 0; i < strlen(a1); i++)
			{
				if(a1[i] >= 'a')
					a1[i] = (a1[i] - 'a') + 'A';
				if(b1[i] >= 'a')
					b1[i] = (b1[i] - 'a') + 'A';
			}
			if(strcmp(a1, b1) == 0)
				printf("3\n");
			else
				printf("4\n");
		}
	}
}