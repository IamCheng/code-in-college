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
	cout << "����ˮ�ɻ���λ��(1-7)��" << endl;
	cin >> n;
	n;
	cout << "ˮ�ɻ���Ϊ:" << endl;
	solve();//ֻ�ܽ��С��Χ�������������Ҫ�õ������㷨+��֦
	return 0;
}