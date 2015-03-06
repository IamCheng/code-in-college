#include<vector>
#include<malloc.h>
#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct node
{
    int w;
    struct node *l, *r;
}list;
int n;
int build(list  * &head)
{
    int w;
    scanf("%d", &w);
    head = (list *)malloc(sizeof(list));
    head->l = NULL;
    head->r = NULL;
 	head->w = w;
    if(w == 0)
    {         
        build(head->l);
        build(head->r);
    }
    return 0;
}
__int64 Get_max(list *head, vector <int> &L)
{
    if(head->l == NULL && head ->r == NULL)
    {
        L.push_back(head->w);
        return 0;
    }
    vector <int> tmp, R;
    __int64 tot = Get_max(head->l, L) + Get_max(head->r, R);
    int ll = L.size(), rr = R.size(), i = 0, l, r;
	__int64 rev = 0, cnt = 0;
    for(l = 0, r = 0; l < ll || r < rr; )
    {
        if(r >= rr || (l < ll && L[l] < R[r]))
        {
             tmp.push_back(L[l++]);
             cnt += r;
        }
        else    
        {
            tmp.push_back(R[r++]); 
			rev += l;
        }
    }
    tot += rev > cnt ? cnt : rev;
    L = tmp;
    return tot;
}
int main()
{
    scanf("%d", &n);
    vector <int> L;
    list * head;
    build(head);
    printf("%I64d", Get_max(head, L));
    return 0;
}
