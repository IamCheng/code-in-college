#include<map>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct cow
{
    int r, c;
};
cow c[50010];int N;
int degree;
int deal()
{
    map <int, int> row, col;
    map<int, int>::iterator iter;
    int i;
    for(i=0; i < N; i++)
        if(c[i].r != -1)
        {
            iter = row.find(c[i].r);
            if(iter != row.end())
                row[iter->first]++;
            else
                row.insert(pair<int, int>(c[i].r, 1));  
        }

    for(i=0; i < N; i++)
        if(c[i].r != -1)
        {
            iter = col.find(c[i].c);
            if(iter != col.end())
                col[iter->first]++;
            else
                col.insert(pair<int, int>(c[i].c, 1));
        }
		cout << col.size() << endl << row.size() << endl;
	if(degree == 0 && (row.size() <= 3 || col.size() <= 3))
	{
		printf("1\n");
		return -1;
	}

	degree++;
        int maxr = -1, maxc = -1;
        int tr = -1, tc = -1;
        bool flag = false;
        for(iter=row.begin(); iter != row.end(); iter++) 
            if(maxr < iter->second){tr = iter->first;maxr = iter->second;}
        for(iter=col.begin(); iter != col.end(); iter++)  
            if(maxc < iter->second){tc = iter->first;maxc = iter->second;}
        if(maxr < maxc)
        {
            maxr = maxc;
            tr = tc;
            flag = true;
        }
    

    for(i=0; i < N; i++)
        if((flag&&c[i].c == tr)||c[i].r == tr)
            c[i].r = -1;
    
    return maxr;
}
int main()
{
    int tot = 0;
    cin >> N;
    for(int i=0; i < N; i++)
		scanf("%d%d", &c[i].r, &c[i].c);
    for(int j=0; j < 3; j++)
    {
        int tt = deal();
		if(tt == -1)
			return 0;
        tot += tt;
        if(tot == N)
        {
           printf("1\n");;
            return 0;
        }   
    }
    printf("0\n");;
    return 0;
}
//  for(map<int, int> ::iterator it=row.begin(); it != row.end(); it++)         printf("%d %d\n", it->first, it->second);
