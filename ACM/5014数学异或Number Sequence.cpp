#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 110000;
int num[maxn];
int pp[100] = {0xffffffff, 0xfffffffe, 0xfffffffc, 0xfffffff8, 0xfffffff0, 0xffffffe0, 0xffffffc0, 0xffffff80, 0xffffff00,
			   0xfffffe00, 0xfffffc00, 0xfffff800, 0xfffff000, 0xffffe000, 0xffffc000, 0xffff8000, 0xffff0000, 0xfffe0000};
int pow[20] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};
int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        int cnt, m, i;
        __int64 ans = 0;
        bool flag = false;
        for(i = n; i >= 0; i--)
        {        
            if(!flag)	m = upper_bound(pow, pow+18, i) - pow;
            int tmp = pp[m] ^ (~i);
            num[i] = tmp;
            if(!flag)
            {
                cnt = i - tmp + 1;
                flag = true;
            }
            if(--cnt == 0)	flag = false;
            ans += tmp ^ i;
        }
        printf("%I64d\n", ans);
        scanf("%d", &cnt);
        printf("%d", num[cnt]);
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &cnt);
            printf(" %d", num[cnt]);
        }
        printf("\n");
    
    }
    return 0;
}