#include<stdio.h>
void main()
{
	int i,re(int);
	i=re(5);
	printf("���ٴ���%d����\n",i);

}
int re(int j)
{
	int sum;
	if(j==0) {sum=1; printf("��%d��������%d����\n\n",5-j,sum);return sum;}
	else
	{
		sum=5*re(j-1)+1;
		if(j!=5) printf("��%d��������%d����\n\n",5-j,sum);
		return sum;
		
	}
}
