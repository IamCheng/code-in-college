#include<iostream>
#include<math.h>
using namespace std;
int n;
bool is_flower_number(int num)
{
	int s = 0, num1 = num;
	while(num1/10 > 0)
	{
		s += pow(num1%10, n);
		num1 /= 10;
	};
	s += pow(num1, n);
	if(s == num)
		return true;
	else
		return false;
}
int solve()
{
	int sum = pow(10, n);
	if(sum == 10)
		cout << "0" << endl;
	for(int i=sum/10; i < sum; i++)
		if(is_flower_number(i))
			cout << i <<endl;
	return 1;
}
int main()
{
	cout << "输入水仙花数位数(1-7)：" << endl;
	cin >> n;
	n;
	cout << "水仙花数为:" << endl;
	solve();//只能解决小范围的数，大的数需要用到大数算法+减枝
	return 0;
}