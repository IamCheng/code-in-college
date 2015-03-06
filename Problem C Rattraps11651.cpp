#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int num[1000010];
int main()
{
    int T, i;
    scanf("%d", &T);
    while(T--)
    {
        int A, N, K, B, M;
        scanf("%d%d%d%d%d", &A, &N, &K, &B, &M);
        for(i = 0; i < N; i++)
        {
            num[i] = A;
            A = (((A + K) ^ B) & M);          
        }
	//	for(i = 1; num[i] != num[0] && i < N; i++);
        sort(num, num+i);
        int ans = 0;
        for(int j = 1; j < N; j++)
            if(num[j] - num[j-1] > ans) ans = num[j] - num[j-1];
        printf("%d\n", ans);
    }
    return 0;
}