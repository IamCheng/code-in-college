#include<stdio.h>
void main()
{
	long i,j,m=10,n=89;
	for(i=1;i<=20;i++)
	{
	   if(i%2)
	   {
		   for(j=1;j<=3;j++)
		   {
			   if(n<=0) {n=0;break;}
			   if(j==1)n=n-m;
			   if(j==2){n=n-m;n=2*n;};
			   if(j==3){n=n-m;m=2*m;}
		
		   }
	   }
	    else
		{
			for(j=1;j<=3;j++)
			{
				if(n<=0) {n=0;break;}
				if(j==1){n=n-m;n=2*n;};
			    if(j==2)n=n-m;
			    if(j==3){n=n-m;m=2*m;n=n*2;};
	
			}
			
		}
		if(n==0) break;
	}
	printf("%d\n",n);
}
/* 假设有两种微生物 X 和 Y

    X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。

    一个新出生的X，半分钟之后吃掉1个Y，并且，从此开始，每隔1分钟吃1个Y。

    现在已知有新出生的 X=10, Y=89，求60分钟后Y的数目。

    如果X=10，Y=90  呢？

    本题的要求就是写出这两种初始条件下，60分钟后Y的数目。*/