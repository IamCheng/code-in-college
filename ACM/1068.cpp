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
	for(i = 0; i < n; i++)
	{
		p = head;
		while( p->ch != ')')
			p = p->next;
	
		t = p;
		while(p->before->ch != '(')
		{
			if(p->before->ch == 'n' )
			{
				t->num += p->before->num;
				p->before->ch = 'y';
			}
			p = p->before;
		}
		t->num += 1;
		p->before->ch = '0';
		t->ch = 'n';
		printf("%d ",t->num);

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
		while(head!=NULL)
		{
			p = head;
			head = head->next ;
			free(p);
			
		}
		b = 0;

	}
	return 1;
}