#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char tp[][15] = {"", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
char tp1[][15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int s[110];
int n;
void seperate(char *f)
{
	char tmp[100];
	int crt = 0, len = strlen(f);
	n = 0;
	for(int i = 0; i <= len; i++)
	{	
		if(f[i] == '-' || f[i] == 0)
		{
			f[i] = 0;	
			strcpy(tmp, f + crt);
			crt = i + 1;
			s[n++] = atoi(tmp);
		}
	}
}
int main()
{
	int T, i , j, tt = 1;
	char num[110], form[250], rs[10000];
	scanf("%d", &T);
	while(T--)
	{
		int k = 0, flag = 0;
		memset(form , 0, sizeof(form));
		memset(rs, 0, sizeof(rs));
		scanf("%s %s", num, form);
		seperate(form);
		printf("Case #%d:", tt++);
		int lenth_of_num = strlen(num);
		for(i = 0, k = 0; i < lenth_of_num; i += s[k++])
		{	
			int nn = 0;
			for(j = i; j < i + s[k]; j++)
			{			
				if(num[j] == num[j+1] && j != i + s[k] - 1)
				{
					nn++;
					strcat(rs, " ");
					strcat(rs, tp1[num[j]-'0']);
				}
				else
				{			
					if(nn == 0)
						printf(" %s", tp1[num[j]-'0']);
					else
					if(nn > 9)
					{
						printf("%s", rs);
						printf(" %s", tp1[num[j]-'0']);
					
					}
					else
						printf(" %s %s", tp[nn], tp1[num[j]-'0']);	
					nn = 0;	
					memset(rs, 0, sizeof(rs));
				}
			}
		}
		printf("\n");
	}
	return 0;
}