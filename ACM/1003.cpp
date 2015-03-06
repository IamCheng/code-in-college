#include<iostream>
using namespace std;
int n=0;
int sum(float c)
{
	if(c<0)
		return n;
	n++;
	sum(c-1/(float)(n+1));
}
int main()
{
	float c;
	while(cin>>c)
	{
		if(c==0.00) break;
		sum(c);
		cout<<n<<" card(s)\n";
		n=0;
	}
	return 1;
}