#include<stdio.h>
#include<vector>
using namespace std;
vector <int> s;
int ans = 0;
bool vis[10];
int cal(int n, int depth)
{
	if(depth == 5)
	{
		if((s[0]*10+s[1])*(s[2]*100+s[3]*10+s[4]) == (s[0]*100+s[3]*10+s[1]) * (s[2]*10 + s[4]))
			ans++;
		return 0;
	}
	for(int i = 1; i <= 9; i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			s.push_back(i);
			cal(i, depth+1);
			s.pop_back();
			vis[i] = false;
		}
	}
	return 0;
}
int main()
{
	cal(0, 0);
	printf("%d\n", ans);
	return 0;
}