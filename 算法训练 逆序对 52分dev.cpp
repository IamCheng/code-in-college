#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<malloc.h>
#include<string.h>
#include<cctype>
#include<stdio.h>
using namespace std;

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

typedef struct node
{
	int w;
	int v;
	struct node *l, *r;
	
}list;
const int maxn = 200010;
int n, mid[maxn], L[maxn];
int build(list  * &head)
{
	int w;
	w = readint();
	head = (list *)malloc(sizeof(list));
	head->l = NULL;
	head->r = NULL;	
	head->w = w;
	if(w == 0)
	{	
		build(head->l);
		build(head->r);
		head->v = head->l->v + head->r->v;
	}
	else
	{
		head->v = 1;
	}
	return 0;
}
int DFS(list *head)
{
    if(head != NULL)
    {
        printf("%d ", head->v);
        DFS(head->l);
        DFS(head->r);
    }
    return 0;
}
long long Get_min(list *head, int l_s, int m, int r_e)
{
	if(head->l == NULL && head ->r == NULL)
	{
		return 0;
	}
	long long cnt = 0, i = 0, l, r, rev = 0, tot = 0;
	list * & left = head->l, * & right = head->r;

	if(m - l_s == 1)
		L[l_s] = left->w;
	else
		tot += Get_min(left, l_s, l_s+left->l->v, m);

	if(r_e - m == 1)
		L[m] = right->w;
	else
		tot += Get_min(right, m, m+right->l->v, r_e);
	
	for(l = l_s, r = m; l < m || r < r_e; )
	{
		if(r >= r_e || (l < m && L[l] < L[r]))
		{
			mid[i++] = L[l++];
			cnt += r - m;
		}
		else	
		{
			mid[i++] = L[r++];
			rev += l - l_s;
		}
	}
	tot += rev > cnt ? cnt : rev;
//	memcpy(L+l_s, mid, r_e-l_s);
	memcpy(L+l_s, mid, (r_e-l_s) * sizeof(int));
//	for(l = l_s, i = 0; l < r_e; l++)
	//	L[l] = mid[i++];
	return tot;
}

int main()
{
	//	freopen("1.txt", "r", stdin);
	scanf("%d", &n);
	if(n == 1)
	{
		printf("0\n");
		return 0;
	}
	list * head;
	build(head);
//	DFS(head);
//	printf("\n");
	cout << Get_min(head, 0, head->l->v, n);
	
	return 0;
}
