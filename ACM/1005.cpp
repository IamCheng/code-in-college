#include<iostream>
using namespace std;
#define pi 3.1415926
int main()
{
	float x,y;
	int i,n,z;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		z = (int)(pi*(x*x+y*y)/100)+1;
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<z<<"."<<endl;

	}
	cout<<"END OF OUTPUT.";
	return 1;
}