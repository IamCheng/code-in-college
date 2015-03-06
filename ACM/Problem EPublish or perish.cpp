#pragma warning (disable:4786)
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<iostream>
const int maxn = 110;
using namespace std;
map <string, vector<int> >  m;
char pa[maxn][25];
struct node
{
    string ch;
    int num;
}hu[maxn];
int cal(vector <int> & a)
{
	int tot = 1;
	if(a[a.size()-1] == 0)
		return 0;
	for(int i = a.size() - 1; i > 0; i--)
	{
		if(a[i] >= tot && tot >= a[i-1])
			return tot;
		tot++;
	}
    return tot;
}

int cmp(node a, node b)
{
    if(a.num == b.num)
        return a.ch < b.ch;
    return a.num > b.num;
    
}
int main()
{
    int n, i, j;
    while(scanf("%d", &n) == 1 && n)
    {
        int cnt[maxn] = {0};
        m.clear();
        int tt = 0;
        vector <int> v;
        for(i = 1; i <= n; i++)
        {
            scanf("%s", pa[i]);
            if(m.count(pa[i]) == 0)
				m.insert(pair<string, vector<int> >(pa[i], v));
        }
        char tmp[maxn];
        for(i = 1; i <= n; i++)
        {
            scanf("%s", tmp);
            for(j = 0; tmp[j] != 0; j++)
                if(tmp[j] == '1')   cnt[j+1]++;             
        }

        for(i = 1; i <= n; i++)
            m[pa[i]].push_back(cnt[i]);
        map <string, vector<int> >::iterator it;
        i = 0;
        for(it = m.begin(); it != m.end(); it++)
        {
            v = it->second;
            sort(v.begin(), v.end());
            hu[i].num = cal(v);
            hu[i].ch = it->first;
            i++;
        }
        sort(hu, hu+i, cmp);
        for(j = 0; j < i; j++)
            cout << hu[j].ch << " " << hu[j].num << endl;
		cout << endl;
    }
    return 0;
}                                 