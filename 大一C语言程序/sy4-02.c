
#include<stdio.h>
void main()
{
	float x,y;
    printf("输入一个数\n");
    scanf("%f",&x);
	if(x>1)
	y=x;
    else 
	if(x<10.0)
		y=2*x-1;
	else
		y=3*x-11;
	printf("x=%f\n",x);
	printf("y=%f\n",y);
}

