#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1010;
int A[maxn], B[maxn];
int main()
{
	int m, n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	for(j = 0; j < m; j++)
		scanf("%d", &B[j]);
	sort(A, A+n);
	sort(B, B+m);
	int k = 0, t = 0;
	vector <int> c;
	for(i = 0, j = 0; i + j < m + n; )
	{
		if(i < n)
		{
			if(A[i] < B[j] || j >= m)
				c.push_back(A[i++]);
			else
				if(A[i] == B[j])
				{
					c.push_back(A[i]);
					printf("%d ", A[i]);
					j++;			
					A[i++] = 0;
				}		
		}
		if(j < m && (A[i] > B[j] || i >= n))
			c.push_back(B[j++]);
	}
	printf("\n");
	for(i = 0; i < c.size(); i++)
		printf("%d ", c[i]);
	if(c.size() != 0)	
		printf("\n");
	for(i = 0; i < n; i++)
		if(A[i] != 0)
			printf("%d ", A[i]);
	return 0;
}
