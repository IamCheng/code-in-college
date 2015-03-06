#include<stdio.h>
#include<vector>
using namespace std;
#define lenth 30
const int max_v = 1000000000;
const int maxn = 100000;
bool vis[maxn] = {1, 1};
int num[lenth] = {0, 0}, prime[10000], p, n;

int print_sub(int a, int len, int &v)
{
	vector <int> tmp;
	int i;
	__int64 div = 1;
	for(i = 0; i < len; i++)
	{
		if(a & (1 << i))
			tmp.push_back(prime[i]);
	}
	for(i = 1; i <= tmp.size(); i++)
		div *= tmp[i-1];
	int first = (p / div + 1) * div; 
	if(first > v)
		return 0;
	if(tmp.size() % 2 == 0)
		return -((v - first) / div + 1);
	else
		return (v - first) / div + 1;
}
int main()
{
	int i, j;
	//筛选素数
	for(i = 2; i * i <= maxn; i++)
	{
		if(vis[i])
			continue;
		for(int j = i*i; j <= maxn; j += i)
			vis[j] = true;
	}

	for(i = 2; i <= 32000; i++)
	{
		if(vis[i] == 0)
			prime[p++] = i;
		if(i <= lenth)
			num[i] = p;
	}
	while(scanf("%d%d", &n, &p) == 2)
	{	
		__int64 ans = 1;
		if(n == 1)
		{
			printf("%d\n", p);
			continue;
		}
		if(p < lenth)
		{
			int l = p, r = max_v, m;
			while(l < r)
			{
				m = l + (r - l) / 2;
				int tot = m - p + 1;
				for(int i = 1; i < (1<<(num[p]-1)); i++)
				{
					tot -= print_sub(i, num[p], m);
				}
				if(tot + 1 < n)
					l = m + 1;
				else
					r = m;
			}
			//找到结果
			ans = (__int64)p * l;
			ans = ans > max_v ? 0 : ans;
			printf("%d\n", ans);
			continue;
		}
		int cnt = 0;	
		if((__int64)p * p > max_v)
		{
			printf("0\n");
			continue;
		}	
		for(i = 0; prime[i] != p; i++);
		int t = i;
		for(i = p; i <= max_v; i += p + p)
		{
			for(j = 0; j < t; j++)//5095069 31
			{		
				if(i % prime[j] == 0)
					break;		
			}	
			if(j == t)
				cnt++;
			if(cnt == n)
			{
				printf("%d\n", i);
				break;
			}
		}
		if(i > max_v)
			printf("0\n");
	}
	return 0;
}
/*

Find the N-th smallest positive integer whose least prime factor is P.


输入


The input case has one line containing two integers N and P (1 ≤ N, P ≤ 109). P is a prime number.


输出


Output the expected result in one line. If the result is larger than 109, just output 0.


样例输入


1 2


样例输出


2

*/