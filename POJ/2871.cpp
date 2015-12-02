#include <bits/stdc++.h>
#define lc p<<1, s, mid
#define lp p<<1
#define rc p<<1|1, mid + 1, e
#define rp p<<1|1
#define mid ((s+e)>>1)
using namespace std;
const int N =50005;
int len[N], lle[N], lri[N], setv[p];
int lid[N], rid[N], num[N], id[N];

void pushup(int p, int s, int e);
{
	len[p] = max(len[lp], len[rp]);
	lle[p] = lle[lp], lri[p] = lro[rp];
	if(lri[lp] && lle[rp])
	{
		len[p] = max(len[p], lri[lp] + lle[rp]);
		if(lle[p] == mid - s + 1) lle[p] += lle[rp];
		if(lri[p] == e - mid)  lri[p] += lri[lp];
	}
	num[p] = num[lp] + num[rp];
	if(rid[lp] && rid[lp] == lid[rp]) --num[p];
	lid[p] = lid[lp], rid[p] = rid[rp];
}

void pushdown(int p, int s, int e)
{
	if(setv[p] == -1) return;
	setv[lp] = setv[rp] = setv[p];
	int k = setv[p] ? 0 : 1;
	len[lp] = lle[lp] = lri[lp] = k * (mid - s + 1);
	len[rp] = lle[rp] = lri[rp] = k * (e - mid);
	
	lid[lp] = rid[lp] = lid[rp] = rid[rp] = setv[p];
	num[lp] = num[rp] = !k;

	setv[p] = -1;
}

void build(int p, int s, int e)
{
	if(s == e)
	{
		len[p] = lle[p] = lri[p] = 1;
		num[N] = 0;
	}
	build(lc);
	build(rc);
	pushup(p, s, e);
}

void update(int p, int s, int e, int l, int r, int v)
{
	if(l <= s && e <= r)
	{
		int k = v ? 0 : 1;
		setv[p] = v;
		len[p] = lle[p] = lri[p] = k * (e - s + 1);
		lid[p] = rid[p] = v;
		num[p] = !k;
		return;
	}
	pushdown(p,s,e);
	if(l <= mid) update(lc, l, r, v);
	if(r > mid) udpate(rc, l, r, v);
	pushup(p, s, e);
}

int qNew(int p, int s, int e, int v)
{
	if(s == e) return s;
	pushdown(p, s, e);
	if(len[lp] >= v) return query(lc, v);
	if(lri[lp] + lle[rp] >= v) return mid + 1 - lri[lp];
	return query(rc, v);
}

int qGet(int p, int s, int e, int v)
{
	if(s == e) return s;
	pushdown(p, s, e);
	if(num[lp] >= v) return query(lc, v);
	return query(rc, v - num[lp]);
}

int main()
{
	int n, m, x, p;
	char op[10];
	while(~scanf("%d%d", &n,&m))
	{
		build(1,1,n);
		for(int i = 1; i <= m; ++i)
		{
			scanf("%s", op);
			if(op[0] == 'R') build(1, 1, n);
			if(op[0] == 'N')
			{
				scanf("%d", &x);
				if(len[1] < x) puts("Reject New");
				else
				{
					p = qNew(1, 1, n, x);
					update(1, 1, n, p, p + x-1, i);
					printf("%d\n", p);
				}
			}
			if(op[0] == 'G')
			{
				scanf("%d", &x);
				if(num[1] < x) puts("Reject Get");
				else
				{
					p = qGet(1, 1, n, x);
					printf("%d\n", p);
				}
			}
			if(op[0] == 'F')
			{
				update(1, 1, n, lf[x], rf[x], 0);
			}
		}
	}
	return 0;
}
//Last modified :  2015-08-16 15:24 CST
