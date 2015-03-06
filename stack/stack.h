#include<iostream>
using namespace std;
typedef int element;
class stack
{
private:
	element *s;
	int N, lenth;
public:
	stack()
	{
		N = -1;
		lenth = 10;
		s = (element *)malloc(lenth*sizeof(element));
	}
	bool push(element a);
	bool pop();
	element Get_top();
	void display();
};