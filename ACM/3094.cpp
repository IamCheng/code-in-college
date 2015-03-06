#include<stdio.h>
int main()
{
	char ch;
	while(1)
	{
		int i = 1,sum = 0;
		ch = getchar();
		if(ch=='#')	break;
		while(ch!='\n')
		{
			if(ch!=' ')
				sum += (ch - 64) * i;
			ch=getchar();
			i++;
		}
		printf("%d\n",sum);
	}
    return 0;
}