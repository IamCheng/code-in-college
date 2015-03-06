#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1000100;
int num[maxn], r[maxn], in[maxn], n;
map<int, int>  B;
int Lowbit(int t)
{
	return t&(t^(t-1));
}
int sum(int end)
{
	int sum = 0;
	while(end > 0)
	{
		sum += in[end];
		end -= Lowbit(end);
	}
	return	sum;
}
void plu(int pos, int num)
{
	while(pos <= n)
	{
		in[pos] += num;
		pos += Lowbit(pos);
	}
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);	
	for(i = n - 1; i >= 0; i--)
	{
		r[i] = ++B[num[i]];
		plu(r[i], 1);
	}
	B.clear();
	__int64 ans = 0;
	for(j = 0; j < n; j++)
	{
		plu(r[j], -1);
		ans += sum(++B[num[j]]-1);
	}
	printf("%I64d", ans);
	return 0;
}
