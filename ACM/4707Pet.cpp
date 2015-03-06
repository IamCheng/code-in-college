#include<stdio.h>
#include<vector>
using namespace std;
const int maxn = 100010;
vector <int> list[maxn];
int n;
int BFS(vector <int> tmp, int D)
{
	int len = tmp.size();
	if(D > 0)
	{
		n -= len;
		for(vector<int>::iterator i = tmp.begin();  i != tmp.end(); i++)
		{
			BFS(list[*i], D - 1);
		}
	}
	return 0;
}
int main()
{
	int T, a, b, D, i;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &D);
		int N = n;
		for(i = 1; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			list[a].push_back(b);
		}
		int ans = BFS(list[0], D);
		printf("%d\n", n-1);
		for(i = 0; i < N; i++)
			list[i].erase(list[i].begin(), list[i].end());

	}
	
	return 0;
}