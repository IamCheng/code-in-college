#include<stdio.h>
#include<vector>
using namespace std;
int s[26] = {2, 3, 5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int main()
{
	while(1)
	{
		bool f = false;
		vector <int> a, b;
		while(1)
		{
			int num;
			char ch;
			scanf("%d%c", &num, &ch);			
			if(!f)
				a.push_back(num);
			else
				b.push_back(num);
			if(ch ==' ')
				f = true;
			if(ch == 10)
				break;
		}
		if(b.size() == 1 && a.size() == 1 && (a[0] == 0 || b[0] == 0))
			return 0;
		if(a.size() < b.size())
		{
			vector <int> c = b;
			b = a;
			a = c;
		}
		int n = 0, c_a = a.size(), c_b = b.size(), acc;
		for(c_a--, c_b--; c_a >= 0; c_a--, c_b--)
		{
			if(c_b < 0)
			{
				c_b = 0;
				b[c_b] = 0;
			}
			acc = (a[c_a] + b[c_b]) / s[n];
			a[c_a] = (a[c_a] + b[c_b]) % s[n];
			if(++n < a.size())
				a[c_a-1] += acc;
		}
		bool flag = false;
		if(acc > 0)
		{
			printf("%d", acc);
			flag = true;
		}
		for(n = 0; n < a.size(); n++)
		{
			if(flag)
				printf(",%d", a[n]);
			else
			{
				printf("%d", a[n]);
				flag = true;
			}
		}
		printf("\n");		
	}
	return 0;
}