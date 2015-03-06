#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
#define e (6.11*exp(5417.7530* ((1/273.16) - (1/(dewpoint+273.16)))))
#define h ( (0.5555)*(e-10.0))
int main()
{
	char a[2];
	double dewpoint,t,H;
	int i;
	while(1)
	{
		for(i=0;i<2;i++)
		{
			cin>>a[i];
			switch(a[i])
			{
			case 'T':cin>>t;break;
			case 'D':cin>>dewpoint;break;
			case 'H':cin>>H;break;
			case 'E':break;
			}
			if(a[i]=='E') return 0;
		}
		if(a[0]!='H'&&a[1]!='H')
			H=t+h;
		else
		{
			if(a[0]=='D'||a[1]=='D')
				t=H-h;
			else
				dewpoint=1/((1/273.16)-((log((((H-t)/0.5555)+10.0)/6.11))/5417.7530))-273.16;
		}
		cout<<setprecision(1)<<fixed<<"T "<<t<<" D "<<dewpoint<<" H "<<H<<endl;  
	}
	return 1;
}