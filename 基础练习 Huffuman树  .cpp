#include<queue>
#include<stdio.h>
using namespace std;
struct node
{ 
	int a;
	friend bool operator < (node n1, node n2)
    {
      return n1.a > n2.a;
    }
   
};
int main()
{
	int n;
	scanf("%d", &n);
	priority_queue <node> q; 
	node num;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num.a);
		q.push(num);
	}
	int tot = 0;
	int len = q.size();
	for(int j = 1; j < len; j++)
	{
		node pa = q.top();
		q.pop();
		node pb = q.top();
		q.pop();
		pa.a = pa.a + pb.a;
		tot += pa.a;	
		q.push(pa);
	}
	if(n == 1)
		tot = q.top().a;
	printf("%d\n", tot);
	return 0;
}
