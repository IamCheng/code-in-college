#include<stdio.h>
#include<malloc.h>
typedef struct kh
{
	char ch;
	int num;
	struct kh *before;
	struct kh *next;
}node;
node *head,*p,*pre;
int b;
int creat(int i, int tmp)
{
	int temp = tmp;
	tmp = tmp - b;	
	for(int j = 0; j <= tmp; j++)
	{
		p = (node *)malloc(sizeof(node));
		if(NULL == p)
			return -1;
		if( j == tmp)
			p->ch = ')';
		else
			p->ch = '(';
		p->num = 0;	
		if(0 == i)
		{
			i++;
			head = p;
			pre = p;
		}
		pre->next = p;
		p->before = pre;
		pre = p;
	}
	p->next = NULL;
	b = temp;
	return 1;
}
int srch(int n)
{
	int i;
	node *t;
	t = head;
	for(i = 0; i < n; i++)
	{
		int rcd = 0;
		p = t;
		while( p->ch != ')')
			p = p->next;	
		t = p->next;
		while( p != NULL && p->ch != '(' )
		{
			if( p->ch == ')' )
				rcd++;
			p = p->before;
		}
		if( p != NULL)
			p->ch = 0;
		else
			rcd = 0;
		printf("%d ",rcd);

	}
	return 1;
}
int main()
{
	int N,n,tmp,i;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		for(i = 0;i <n; i++)
		{
			scanf("%d",&tmp);
			creat(i,tmp);
		}
		head->before = NULL;
		srch(n);
		printf("\n");
		b = 0;

	}
	return 1;
}