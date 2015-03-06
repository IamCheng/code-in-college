#include<stdio.h>
#include<stdlib.h>
#define maxn 40100
int num[maxn];
int main()
{
    int n, m, i;
    while(scanf("%d%d", &n, &m) == 2)
    {
        int p, odd[(maxn<<1)+10] = {0}, even[(maxn<<1)+10] = {0}, b = 0, t = 0, ans, pos, s;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            if(num[i] == m)    p = i;
        }
        for(i = p - 1; i >= 1; i--)
        {
            t++;
            if(num[i] > m)    b++;
            s = (p - i) - b;
            if(t % 2 == 0)
                even[b-s+maxn]++;
            else
                odd[b-s+maxn]++;
        }
		ans = ++even[maxn];
        t = b = 0;
        for(i = p + 1; i <= n; i++)
        {
            t++;
            if(num[i] > m)	b++;
           	s = i - p - b;
            pos = (b - s) > 0 ? (maxn-(b-s)) : (maxn+s-b);
            if(t % 2 == 0)
                ans += even[pos];
            else
                ans += odd[pos];
        }
        printf("%d\n", ans);
    }
    return 0;
}
