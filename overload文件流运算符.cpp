#include<iostream>
#include<string>
using namespace std;
ostream & operator << (ostream & out, char * ch)
{
	string t("Hi, I am coming...\n");
	t += ch;
	t += "Thanks! Goodbye!\n";
	out << t;
	return out;
}

int main()
{
	cout << "Hello, everyone! \n";
	return 0;
}