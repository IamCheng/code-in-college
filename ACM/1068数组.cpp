#include<stdio.h>
int main()
{
	int N,n,num,i,tmp,m,out;
	scanf("%d",&N);
	while(N--)
	{
		char ch[41] = {0};
		m = tmp = 0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&num);
			for(i = 0; i < num - tmp; i++)
				ch[m++] = '(';
			ch[m++] = ')';
			tmp = num;
		}
		for(i = 0; i < m; i++)
		{
			out = 0;
			if(ch[i] == ')')
			{
				tmp = i;
				out++;
				while(--tmp)
				{
					if(ch[tmp] == '(')
					{
						ch[tmp] = '0';
						break;						
					}
					if(ch[tmp] == ')')
						out++;
				}
				printf("%d ",out);
			}
		}
		printf("\n");		
	}
	return 1;
}