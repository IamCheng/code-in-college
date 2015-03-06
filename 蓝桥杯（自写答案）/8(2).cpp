#include<stdio.h>
int add(int sum[])
{
	for(int i = 0;i < 6 ;i++)
	{
		while(sum[i] >= 10)
		{
			sum[i] = sum[i] % 10 + sum[i]/10;
		}
	}
	return 1;	
}
void main()
{
	int num;
	char tmp;
	scanf("%d",&num);	
	for( int i = 0;i < num; i++)
	{
		fflush(stdin);
		int sum[6] = {0};	
		int j = 0;
		tmp = getchar();
		while(tmp != 10)
		{
			if(j >= 6)
				j = j % 6;
			sum[j++] += tmp; 
			tmp = getchar();
		}
		fflush(stdin);
		add(sum);
		for(int h = 0;h<6;h++)
			printf("%d",sum[h]);
		printf("\n");
		
	}
	
}	