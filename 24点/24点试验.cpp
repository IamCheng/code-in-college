#include<stdio.h>
void main()
{
	int chose(int,int,int,int,int),i,j,k,x,y,z,p;
	void search(int,int,int,int);
	search(2,1,4,2);
	for(i=0;i<4;i++)
	{
		x=chose(2,1,6,2,i);
		for(j=0;j<3;j++)
		{
			if(i!=j)
				y=chose(2,1,4,2,j);
			for(k=0;k<2;k++)
			{
				if(i!=j&&j!=k&&i!=k)
				{
					z=chose(2,1,4,2,k);
					p=11-x-y-z;
					search(x,y,z,p);
				}
			}
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
void search(int a,int b,int c,int d)
{
	int i,sum,j,k,r,t; 
	char f[4]={'+','-','*','/'};
	for(i=0;i<4;i++)
	{
		if(i==0) sum=a+b;
		if(i==1) sum=a-b;
		if(i==2) sum=a*b;
		if(i==3) sum=a/b;
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