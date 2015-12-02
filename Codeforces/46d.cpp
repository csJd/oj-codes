#include <bits/stdc++.h>
#define lc lp, s, mid
#define rc rp, mid+1, e
#define mid ((s+e)>>1)
#define lp p<<1
#define rp p<<1|1
using namespace std;
const int N = 400005;

int len[N], lle[N], lri[N], setv[N];
int car[105], pos[105];

void pushdown(int p, int s, int e)
{
    if(setv[p] == -1) return;
    setv[lp] = setv[rp] = setv[p];
    len[lp] = lle[lp] = lri[lp] = setv[p] * (mid - s + 1);
    len[rp] = lle[rp] = lri[rp] = setv[p] * (e - mid);
    setv[p] = -1;
}

void pushup(int p, int s, int e)
{
    len[p] = max(len[lp], len[rp]);
    lle[p] = lle[lp], lri[p] = lri[rp];
    if(lri[lp] && lle[rp])
    {
        len[p] = max(len[p], lri[lp] + lle[rp]);
        if(lle[p] == mid - s + 1) lle[p] += lle[rp];
        if(lri[p] == e - mid) lri[p] += lri[lp];
    }
}

void build(int p, int s, int e)
{
    setv[p] = -1;
    if(s == e)
    {
        len[p] = lle[p] = lri[p] = 1;
        return;
    }
    build(lc);
    build(rc);
    pushup(p, s, e);
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(l <= s && e <= r)
    {
        setv[p] = v;
        len[p] = lle[p] = lri[p] = v * (e - s + 1);
        return;
    }
    pushdown(p, s, e);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p, s, e);
}

int query(int p, int s, int e, int v)
{
    pushdown(p, s, e);
    if(len[lp] >= v) return query(lc, v);
    if(lri[lp] + lle[rp] >= v) return mid - lri[lp] + 1;
    return query(rc, v);
}

int main()
{
    int l, b, f, n, op, x;
    scanf("%d%d%d%d", &l, &b, &f, &n);
    int s = 1 - f, e = l + b;
    build(1, s, e);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &op, &x);
        if(op == 1)
        {
            car[i] = x;
            if(len[1] < x + b + f) puts("-1");
            else
            {
                pos[i] = query(1, s, e, x + b + f);
                update(1, s, e, pos[i] + b, pos[i] + b + x - 1, 0);
                printf("%d\n", pos[i] + f - 1);
            }
        }
        else update(1, s, e, pos[x] + b, pos[x] + car[x] + b - 1, 1);
    }

    return 0;
}
//Last modified :  2015-08-15 18:59 CST
/*
20 2 2
10
1 2
1 3
1 3
1 5
1 5
1 1
1 2
1 5
1 5
1 5
*/

