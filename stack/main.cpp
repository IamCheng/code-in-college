#include "stack.cpp"
void show()
{
	cout << "1、入栈   2、出栈   3、获取栈顶元素  4、显示" <<endl;
}
void fun1(stack &s)
{
	int N;
	cout << "输入要入栈的元素个数：\n";
	cin >> N;
	cout << "依次输入元素\n";
	for(int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		s.push(tmp);
	}
}
void fun2(stack & s)
{
	int N;
	cout << "输入要出栈的元素个数：\n";
	cin >> N;
	for(int i = 0; i < N; i++)
		s.pop();
}
int main()
{
	stack s;
	while(1)
	{
		show();
		int choice;
		cin >> choice;
		switch(choice)
		{
		case 1:fun1(s);break;
		case 2:fun2(s);break;
		case 3:cout << s.Get_top() << endl;break;
		case 4:s.display();break;
		default:exit(0);		
		}
	}
	return 0;
}