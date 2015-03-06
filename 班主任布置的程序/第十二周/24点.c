#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int i,j,k,num[4],x,y,z,p;
	int chose(int x,int y,int z,int p,int);
	void search(int,int,int,int);
	srand((int)time(0));
    for(i=0;i<4;i++)
		num[i]=rand()%14+1;
	printf("随机数为：%d %d %d %d\n",num[0],num[1],num[2],num[3]);
	
	for(i=0;i<4;i++)
	{
		x=chose(num[0],num[1],num[2],num[3],i);
		for(j=0;j<3;j++)
		{
			if(i!=j)
				y=chose(num[0],num[1],num[2],num[3],j);
			for(k=0;k<2;k++)
			{
				if(i!=j&&j!=k&&i!=k)
				{
					z=chose(num[0],num[1],num[2],num[3],k);
					p=num[6-i-j-k];
					search(x,y,z,p);
				}
			}
		}
	}
	printf("此算法存在不足，程序给出的结果可能不完全正确！见谅。\n");

	

}
void search(int a,int b,int c,int d)
{
	int i,j,k,r,t;
	float sum;
	char f[4]={'+','-','*','/'};
	for(i=0;i<4;i++)
	{
		if(i==0) sum=a+b;
		if(i==1) sum=a-b;
		if(i==2) sum=a*b;
		if(i==3) sum=(float)a/(float)b;
		for(j=0;j<4;j++)
		{
			r=sum;
			if(j==0) sum=sum+c;
		    if(j==1) sum=sum-c;
		    if(j==2) sum=sum*c;
            if(j==3) sum=sum/c;
			for(k=0;k<4;k++)
			{
				t=sum;
			    if(k==0) sum=sum+d;
		        if(k==1) sum=sum-d;
		        if(k==2) sum=sum*d;
                if(k==3) sum=sum/d;
				if(sum==24) 
				{
						
				printf("((%d%c%d)%c%d)%c%d=24\n",a,f[i],b,f[j],c,f[k],d); 
				}
				sum=t;
			
			}
			sum=r;
		}

	}
		
}
int chose(int x,int y,int z,int p,int i)
{
	if(i==0) return(x);
	if(i==1) return(y);
	if(i==2) return(z);
	if(i==3) return(p);
	else return(0);
}
