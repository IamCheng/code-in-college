#include<stdio.h>
#include<algorithm>
using namespace std;
int w[30001];
int main()
{
	int n, v;
	scanf("%d", &v);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &w[i]);
	sort(w, w+n);
	int ans = 0;
	for(int front = 0, rear = n - 1; front <= rear;)
	{
		if(w[front] + w[rear] <= v)
		{
			front++;
			rear--;
		}
		else
			rear--;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}