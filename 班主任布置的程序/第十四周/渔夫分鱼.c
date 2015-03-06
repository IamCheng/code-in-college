#include<stdio.h>
void main()
{
	int i,re(int);
	i=re(5);
	printf("至少打了%d条鱼\n",i);

}
int re(int j)
{
	int sum;
	if(j==0) {sum=1; printf("第%d个人拿了%d条鱼\n\n",5-j,sum);return sum;}
	else
	{
		sum=5*re(j-1)+1;
		if(j!=5) printf("第%d个人拿了%d条鱼\n\n",5-j,sum);
		return sum;
		
	}
}
