#include "stack.cpp"
void show()
{
	cout << "1����ջ   2����ջ   3����ȡջ��Ԫ��  4����ʾ" <<endl;
}
void fun1(stack &s)
{
	int N;
	cout << "����Ҫ��ջ��Ԫ�ظ�����\n";
	cin >> N;
	cout << "��������Ԫ��\n";
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
	cout << "����Ҫ��ջ��Ԫ�ظ�����\n";
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