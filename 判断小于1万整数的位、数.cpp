#include<stdio.h>
int judge(int n)
{
	if(n<10)
		return 1;
	else
		return 1+judge(n/10);
}
void main()
{
	int i;
	printf("输入一个小于10000的整数：\n");
	while(scanf("%d",&i)!=EOF)
	{
	
		if(i>=100000||i<0)
		{
			printf("error!try again!\n");
			fflush(stdin);
		}
		else
			printf("该数是%d位数。\n",judge(i));
	}
}

