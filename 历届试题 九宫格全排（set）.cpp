#include<stdio.h>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
const int maxn = 1000000;
struct State
{
	char st[9];
	int num, x, y;
};
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1};
char goal[9];
int get_int(State st)
{
	int tot = 0;
	for(int i = 0; i < 9; i++)
	{
		tot = tot * 10 + st.st[i];
	}
	return tot;
}
int main()
{
	int i, j, k;
	State next;
	queue <State> q;
	set <int> map;
	for(i = 0; i < 9; i++)
	{
		scanf("%c", &next.st[i]);
		if(next.st[i] == '.')
		{
			next.st[i] = 0;
			next.x = i / 3;
			next.y = i % 3;
		}
		else
		{
			next.st[i] -= '0';
		}
	}
	next.num = 0;
	q.push(next);
	getchar();
	for(i = 0; i < 9; i++)
	{
		scanf("%c", &goal[i]);
		if(goal[i] == '.')
			goal[i] = 0;
		else
			goal[i] -= '0';
	}
	while(!q.empty())
	{
		next = q.front();
		q.pop();
		State tmp;

		if(memcmp(goal, next.st, sizeof(goal)) == 0)
		{
			printf("%d", next.num);
			return 0;
		}
	
		map.insert(get_int(next));
		for(i = 0; i <= 3; i++)
		{
			tmp = next;
			tmp.x += x[i];
			tmp.y += y[i];
			if(tmp.x >= 0 && tmp.x <= 2 && tmp.y >= 0 && tmp.y <= 2)
			{
				char ch = tmp.st[tmp.x * 3 + tmp.y];
				tmp.st[tmp.x*3+tmp.y] = tmp.st[next.x*3+next.y];
				tmp.st[next.x*3+next.y] = ch;
				tmp.num = next.num + 1;
				if(map.count(get_int(tmp)))
				{
					continue;
				}
				q.push(tmp);
			}
		}
	}
	printf("-1\n");
//	int ans = bfs();
//	if(ans > 0)
	return 0;
}