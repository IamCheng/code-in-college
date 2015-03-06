#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Node
{
	char str[100];
	int n;
	bool operator < (const Node b)
	{
		return n < b.n;
	}
}node;

int travers(vector<node>con)
{	
	for(vector<node>::iterator i = con.begin(); i != con.end(); ++i)
		printf("%s %d\n", i->str, i->n);
	return 1;
}
void fun_1()
{	
	int N;
	node ini = {"xxx", 0};
	printf("输入vector元素的个数:\n");
	scanf("%d", &N);
	vector <node> con(N, ini) ;
	printf("初始化为：\n");
			travers(con);
	printf("输入每个元素的值:\n");
	for(vector<node>::iterator i = con.begin(); i != con.end(); ++i)
	{
		scanf("%s %d", i->str, &i->n);
	}
	travers(con);
	
}
void fun_2()
{
	node ini;
	vector <node> r;
	printf("输入元素（以0 0结束）\n");
	while(1)
	{
		scanf("%s %d", ini.str, &ini.n);
		if(ini.n == 0)
			break;
		else
			r.push_back(ini);
	}
	node insrt = {"the inserted one", 100}; 	
	for(int i = 0; i < 4; i++)
		r.insert(r.begin()+i*2, insrt);
	travers(r);

}
int cmp(const node a, const node b)
{
	return a.n > b.n;
}
int v_sort(vector <node> r, int flag)
{
	if(0 == flag)
		sort(r.begin(), r.end(), cmp);
	else
		sort(r.begin(), r.end());
	travers(r);
	return 0;
}
void fun_3()
{
	node ini;
	vector <node> r;
	printf("输入元素（以0 0结束）\n");
	while(1)
	{
		scanf("%s %d", ini.str, &ini.n);
		if(ini.n == 0)
			break;
		else
			r.push_back(ini);
	}
	reverse(r.begin(), r.end());
	printf("逆转元素:\n");
	travers(r);
	printf("删除指定的元素:\n");
	for(int i = 0; i < 2; i++)
		r.erase(r.begin()+2*i);
	travers(r);
	printf("删除头两个元素:\n");
	r.erase(r.begin(), r.begin()+2);
	travers(r);
	printf("降序排序的顺序:\n");
	v_sort(r, 0);
	printf("默认排序：\n");
	v_sort(r, 1);
	printf("is vector empty?\n%d\n", r.empty());
	r.clear();
	printf("is vector empty?\n%d\n", r.empty());

}

int main()
{

	//fun_1();	
	//fun_2();
	fun_3();
	return 0;
}
