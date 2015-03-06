#include <cstdio>
#include <cstring>
#include<stdio.h>
#include<iostream>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
//#define LL long long
#define LL __int64
const int maxn = 100100;
int add[(maxn<<2)+100];
int sum[(maxn<<2)+100];
int le[20100], rig[20100];
bool flag;
void PushUp(int rt) {

		sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int rt,int m) {
	if (add[rt]) {
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];

			sum[rt<<1] += add[rt] * (m - (m >> 1));
			sum[rt<<1|1] += add[rt] * (m >> 1);
			add[rt] = 0;
	}
}
void build(int l,int r,int rt) {
	add[rt] = 0;
	if (l == r) {
		sum[rt] = 0;
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
	if (L <= l && r <= R) {
		add[rt] += c;
	
			sum[rt] += (LL)c * (r - l + 1);

		return ;
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , c , lson);
	if (m < R) update(L , R , c , rson);
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		return sum[rt];

	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (m < R) ret += query(L , R , rson);
	return ret;
}
LL num[20010];
int main() {

	int T, N;
	scanf("%d", &T);
	build(1 , 100010 , 1);
	while(T--)
	{
		scanf("%d",&N);
		memset(add, 0, sizeof(add));
		memset(sum, 0, sizeof(sum));
		int t = 0;	
		while (N--) {
			LL &a = num[t];
			scanf("%d", &a);
			le[t++] = query(a , a , 1 , maxn , 1);
			update(a , 100010 , 1 , 1 , maxn , 1);
		}
		N = t;
		memset(add, 0, sizeof(add));
		memset(sum, 0, sizeof(sum));

		while(t-- > 0)
		{
			rig[t] = query(num[t] , num[t] , 1 , 100010 , 1);
			update(1, num[t]  , 1 , 1 , 100010 , 1);
		}
		
		LL ans = 0;
		for(int i = 0; i < N; i++)
		{
			ans += (LL)le[i] * (LL)rig[i] + (LL)(i - le[i] ) * (LL)(N - i - 1 - rig[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

