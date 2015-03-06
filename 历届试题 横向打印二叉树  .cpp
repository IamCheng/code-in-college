#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node
{
	int value;
	int cnt;
	struct node *l, *r;
}Node;
int num[111], n = 0, cnt;
char ch[10], map[110][1010];
Node null = {1, 1, NULL, NULL};
int insert(Node* & head)
{	
	if(head == &null)
	{	
		head = (Node *)malloc(sizeof(Node));
		head->l = head->r = &null;
		head->value = num[cnt];
		return 0;
	}
	if(num[cnt] > head->value)
		insert(head->r);
	else
		insert(head->l);
	return 0;
}
void tran(Node * &head)
{
	if(head == &null)
		return;
	tran(head->r);
	head->cnt = ++cnt;
	tran(head->l);
}
void show()
{
	int i, j, k;
	for(i = 1; i <= n; i++)
	{
		for(j = 1000; map[i][j] == 0; j--);
		for(k = 0; k <= j; k++)
			printf("%c", map[i][k] == 0 ? '.' : map[i][k]);
		printf("\n");
	}
}
int srch(Node * head, int b_num)
{
	if(head == &null)
		return 0;
	if(b_num != 0 && (head->l != &null || head->r != &null))
	{
		sprintf(ch, "-%d-|", head->value);
		sprintf(&map[head->cnt][b_num], "-%d-|", head->value);
	}
	if(head->l == &null && head->r == &null)
	{
		sprintf(&map[head->cnt][b_num], "-%d", head->value);
		return 0;
	}
	if(b_num == 0)
	{
		sprintf(ch, "%d-|", head->value);
		sprintf(&map[head->cnt][b_num], "%d-|", head->value);
	}
	int t = strlen(ch), s;
	b_num += t;
	for(s = (head->r == &null) ? head->cnt : head->r->cnt; s <= head->cnt; s++)	
		map[s][b_num-1] = '|';
	for(s = head->cnt; s <= head->l->cnt; s++)
		map[s][b_num-1] = '|';
	srch(head->r, b_num);
	srch(head->l, b_num);
	return 0;
}
int main()
{
	while(scanf("%d", &num[n++]) == 1);
	n--;
	Node *head = &null;
	for(cnt = 0; cnt < n; cnt++)
		insert(head);
	cnt = 0;
	tran(head);
	srch(head, 0);
	show();
	return 0;
}
