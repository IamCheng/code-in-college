#include<iostream>
#include<map>
#include<string>
#include<queue>
using namespace std;
int main()
{
	map<string, int> mp;
	queue <string> q;
	string ch;	
	int max = -1;
	freopen("input1.txt", "r", stdin);
	while(cin >> ch)
	{
		int i = 0;
		while(ch[i] != 0)
		{
			if(ch[i] >= 'a' && ch[i] <= 'z')
			{
				ch[i] = ch[i] - 'a' + 'A';
			}
			if(ch[i] == ',' || ch[i] == '.')
				ch = ch.substr(0, i);
			else
				i++;
		}
		if(mp.count(ch) == 0)
		{
			q.push(ch);
			if((int)ch.size() > max)	
				max = ch.size();
		}
		mp[ch]++;
	}
	while(!q.empty())
	{
		ch = q.front();
		q.pop();
		int i;
		for(i = ch.size(); i < max; i++)
			cout << " ";
		cout << ch << ":";
		for(i = 0; i < mp[ch]; i++)
			cout << "*";
		cout << mp[ch] << endl;
	}

}