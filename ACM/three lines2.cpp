#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cctype>
using namespace std;
struct cow
{
	int x, y;
};
inline int readint()
{
    char c=getchar();
    bool flag=1;
    while(!isdigit(c)) {if(c=='-') flag=0;c=getchar();}
    int x=0;
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    if(!flag) x*=-1;
    return x;
}
int cmp(cow a , cow b)
{
	if(a.x == b.x)
		return b.y > a.y;
	return a.x < b.x;
}
int cmp1(cow a, cow b)
{
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
	return a.y <= b.y;
}
const int maxn = 100050;
cow C[maxn], C1[maxn], C2[maxn], C3[maxn];
int find_max(cow c[], int r)
{
	int p, max = -1;
	for(int i=1; i <= r; i ++)
		if(c[i].x > -1 && c[i].y > max)
		{
			max = c[i].y;
			p = i;
		}
	return p;
}
int main()
{
	int N, i, r = 1, c = 1;
	scanf("%d", &N);
	for(i=0; i < N; i++)
	{
		C[i].x = readint();
		C[i].y = readint();
	}
	memcpy(C1, C, sizeof(cow)*N);
	sort(C, C+N, cmp);
	sort(C1, C1+N, cmp1);
	bool flag = true;
	for(i=1; i < N; i++)
	{
		if(C[i].x != C[i-1].x)
		{
			C2[r].x = C2[r-1].x + C2[r-1].y;
			C2[r].y = i - C2[r].x;			
			r++;	
			
		}
		if(C1[i].y != C1[i-1].y) 
		{		
			C3[c].x = C3[c-1].x + C3[c-1].y;
			C3[c].y = i - C3[c].x;	
			c++;
		}
	}
	C2[r].x = C2[r-1].x + C2[r-1].y;
	C2[r].y = N - C2[r].x;

	C3[r].x = C3[c-1].x + C3[c-1].y;
	C3[r].y = N - C3[c].x;


	if(r <= 3 || c <=3)
	{
		printf("1\n");
		return 0;
	}


	int p = find_max(C2, r);
	memset(C+C2[p].x, NULL, sizeof(cow) * C2[p].y);
	C2[p].x = -1;
	p = find_max(C2, r);
	memset(C+C2[p].x, NULL, sizeof(cow) * C2[p].y);


	p = find_max(C3, c);
	memset(C1+C3[p].x, NULL, sizeof(cow) * C3[p].y);
	C3[p].x = -1;
	p = find_max(C3, c);
	memset(C1+C3[p].x, NULL, sizeof(cow) * C3[p].y);


	flag = true;
	int key;
	for(i = 0; i < N; i++)
		if(C[i].x != NULL)
		{
			if(flag){
				key = C[i].y;
				flag = false;
			}
			else	
				if(key != C[i].y)
				{
					break;
				}
		}
	if(i == N)
	{
		printf("1\n");
		return 0;
	}
	flag = true;
	for(i = 0; i < N; i++)
		if(C1[i].y != NULL)
		{
			if(flag){
				key = C1[i].x;
				flag = false;
			}
			else	
				if(key != C1[i].x)
				{
					printf("0\n");
					return 0;
				}
		}
	printf("1\n");
	return 0;
}