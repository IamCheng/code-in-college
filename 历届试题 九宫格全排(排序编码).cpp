#include<stdio.h>
#include<string.h>
#include<queue>
#include<set>
using namespace std;
const int maxn = 370000;
bool vis[maxn];
struct State
{
	char st[9];
	int num, x, y;
};
int x[4] = {-1, 0, 1, 0}, y[4] = {0, -1, 0, 1}, level[] = {40320, 5040, 720,120 ,24 ,6 ,2 ,1, 1};
char goal[9];
int get_int(State st)
{
	int tot = 0;
	for(int i = 0; i < 9; i++)
	{
		vis[st.st[i]] = true;
		int cnt = 0;
		for(int j = i + 1; j < 9; j++)
			if(st.st[i] > st.st[j])	cnt++;
		tot += cnt * level[i];
	}
	return tot;
}
int main()
{
	int i;
	State next;
	queue <State> q;
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
			next.st[i] -= '0';
	}
	next.num = 0;
	q.push(next);
	getchar();
	for(i = 0; i < 9; i++)
	{
		scanf("%c", &goal[i]);
		goal[i] = goal[i] == '.' ? 0 : goal[i] - '0';
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
	
		vis[get_int(next)] = true;
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
				if(vis[get_int(tmp)])
				{
					continue;
				}
				q.push(tmp);
			}
		}
	}
	printf("-1\n");
	return 0;
}