#include<stdio.h>
#include<math.h>
void main()
{
	int i,j,a;
	int p(int,int,int,int,int);
	for(i=10000;i<=99999;i++)
	{
	   a=(i%10)*10000+(i%100/10)*1000+(i%1000)/100*100+(i%10000)/1000*10+i/10000;
	   if(p(i%10,(i%100/10),(i%1000)/100,(i%10000)/1000,i/10000))
	     for(j=0;j<9;j++)
		   if(i*j==a) printf("%d\n",i);
	}

}
int p(int x,int y,int z,int p,int n)
{
	int i,j,k,num[5]={x,y,z,p,n};
	for(i=0;i<4;i++)
		for(j=0;j<4-i;j++)
			if(num[j]>num[j+1])
			{
				k=num[j];
				num[j]=num[j+1];
				num[j+1]=k;
			}
	if(num[0]!=num[1]&&num[1]!=num[2]&&num[2]!=num[3]&&num[3]!=num[4])
		return 1;
	else return 0;
}