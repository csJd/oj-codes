#include <cstring>
#include <cstdio>
#include <algorithm>
#define lp p<<1
#define rp p<<1|1
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 50005, M = 200000;
int len[M], ll[M], lr[M], setv[M], n;
//最长连续长度， 最左连续长度, 最右连续长度

void pushup(int p, int s, int e)
{
    len[p] = max(len[lp], len[rp]);
    len[p] = max(len[p], lr[lp] + ll[rp]);
    ll[p] = ll[lp], lr[p] = lr[rp];
    if(ll[p] == mid - s + 1) ll[p] += ll[rp];
    if(lr[p] == e - mid) lr[p] += lr[lp];
}

void pushdown(int p, int s, int e)
{
    if(setv[p] < 0) return;
    setv[lp] = setv[rp] = setv[p];
    len[lp] = ll[lp] = lr[lp] = setv[p] * (mid - s + 1);
    len[rp] = ll[rp] = lr[rp] = setv[p] * (e - mid);
    setv[p] = -1;
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        len[p] = ll[p] = lr[p] = 1;
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
        len[p] = ll[p] = lr[p] = v * (e - s + 1);
        return;
    }
    pushdown(p, s, e);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p, s, e);
}

int query(int p, int s, int e, int v)
{
    if(s == e) return s;
    pushdown(p, s, e);
    if(len[lp] >= v) return query(lc, v);
    if(lr[lp] + ll[rp] >= v) return mid + 1 - lr[lp];
    return query(rc, v);
}

int main()
{
    int op, x, l, pos, m;
    while(~scanf("%d%d", &n, &m))
    {
        build(1, 1, n);
        memset(setv, -1, sizeof(setv));
        while(m--)
        {
            scanf("%d%d", &op, &x);
            if(op == 1)
            {
                if(len[1] < x)
                {
                    puts("0");
                    continue;
                }
                pos = query(1, 1, n, x);
                printf("%d\n", pos);
                update(1, 1, n, pos, pos + x - 1, 0);
            }
            else
            {
                scanf("%d", &l);
                update(1, 1, n, x, x + l - 1, 1);
            }
        }
    }
    return 0;
}
//Last modified :  2015-08-10 17:32 CST

