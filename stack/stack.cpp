#include "stack.h"
#include<malloc.h>
bool stack::push(element x)
{
	if(++N >= lenth)
	{
		lenth += lenth;
		s = (int *)realloc(s, lenth*sizeof(int));
	}
	s[N] = x;
	return true;
}
bool stack::pop()
{
	if(N == -1)
		return false;
	s[N--] = 0;
	return true;
}
element stack::Get_top()
{
	if(N != -1)
		return s[N];
	return -1;
}
void stack::display()
{
	for(int i=N; i >= 0; i--)
		cout << s[i] << " ";
	cout<<endl;
}