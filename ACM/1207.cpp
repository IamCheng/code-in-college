#include<iostream>
using namespace std;
void judge(int n,int *s)
{
	if(n==1)
		return ;
	else
		if(n%2==1)
			judge(3*n+1,s);
		else
			judge(n/2,s);
	(*s)++;
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int a1=1,b1=1;
		judge(a,&a1);
		judge(b,&b1);
		a1=a1>b1?a1:b1;
		cout<<a<<" "<<b<<" "<<a1<<endl;
	}
	return 1;
}