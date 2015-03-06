#include<stdio.h>
int main()
{
	int x,y;
	char c;
	scanf("%d%c%d",&x,&c,&y);
	switch(c)
	{
	case '+': printf("%d+%d=%d\n",x,y,x+y);break;
	case '-': printf("%d-%d=%d\n",x,y,x-y);break;
	case '*': printf("%d*%d=%d\n",x,y,x*y);break;
	case '/': printf("%d/%d=%f\n",x,y,(float)x/(float)y);
	}
	getch();
	return 0;
}