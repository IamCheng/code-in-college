#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float sum=0,tmp;
	int i=1;
	while(i++<=12)
	{
		cin>>tmp;
		sum+=tmp;
	}
	cout<<fixed<<setprecision(2)<<"$"<<sum/12<<endl;
	return 1;
}