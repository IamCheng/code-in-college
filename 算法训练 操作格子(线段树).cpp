#include<stdio.h>
const int maxn = 100010;
int maxv[maxn*4], sum[maxn*4], p, v;
int build(int L, int R, int o)
{
    int m = L + (R-L)/2;
    if(R == L)
    {
        scanf("%d", &v);
        maxv[o] = v;
        sum[o] = v;
        return 0;
    }
    int ll = build(L, m, o*2);
    int rr = build(m+1, R, o*2+1);
    maxv[o] = maxv[o*2] > maxv[o*2+1] ? maxv[o*2] : maxv[o*2+1];
    sum[o] = sum[o*2] + sum[o*2+1]; 
    return 0;
}
int update(int L, int R, int o)
{
    int m = L + (R-L)/2;
    if(R == L)
    {
        maxv[o] = v;
        sum[o] = v;
        return 0;
    }
	if(p <= m)
		update(L, m, o*2);
	else
		update(m+1, R, o*2+1);
    sum[o] = sum[o*2] + sum[o*2+1]; 
    maxv[o] = maxv[o*2] > maxv[o*2+1] ? maxv[o*2] : maxv[o*2+1];  
    return 0;
}
int tot, max = -1;
int query(int L, int R, int o, int l, int r)
{
    int m = L + (R - L) / 2;
    if(l <= L && r >= R)
    {
        tot += sum[o];
        if(maxv[o] > max)
            max = maxv[o];
        return 0;
    }
	if(m >= r)
		query(L, m, o*2, l, r);
	if(m < l)
		query(m+1, R, o*2+1, l, r);
	if(m >= l && m < r)
	{
		query(L, m, o*2, l, m);
		query(m+1, R, o*2+1, m+1, r);
	}	
    return 0;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    for(int i = 1; i <= m; i++)
    {
        int ch;
        scanf("%d%d%d", &ch, &p, &v);
        switch(ch)
        {
            case 1:update(1, n, 1);break;
            case 2:query(1, n, 1, p, v);break;
            case 3:query(1, n, 1, p, v);break;
        }
        int ans = ch == 2 ? tot : max;
        if(ch == 2 || ch == 3)  
        {
            tot = 0;
            max = -1;
            printf("%d\n", ans);
        }
    }
    return 0;
}