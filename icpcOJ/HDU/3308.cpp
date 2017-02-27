#include <cstdio>
#include <algorithm>
#define lc lp, s, mid
#define rc rp, mid+1, e
#define lp p<<1
#define rp p<<1|1
#define mid ((s+e)>>1)
using namespace std;
const int N = 100005, M = N * 4;
int lcis[M], lle[M], lri[M], val[N];

void pushup(int p, int s, int e)
{
    lcis[p] = max(lcis[lp], lcis[rp]);
    lle[p] = lle[lp], lri[p] = lri[rp];
    if(val[mid + 1] > val[mid]) //合并条件
    {
        lcis[p] = max(lcis[p], lri[lp] + lle[rp]);
        if(lle[lp] == mid + 1 - s) lle[p] += lle[rp];
        if(lri[rp] == e - mid) lri[p] += lri[lp];
    }
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        lcis[p] = lle[p] = lri[p] = 1;
        scanf("%d", &val[s]);
        return;
    }
    build(lc);
    build(rc);
    pushup(p, s, e);
}

void update(int p, int s, int e, int x, int v)
{
    if(s == e)
    {
        val[s] = v;
        return;
    }
    if(x <= mid) update(lc, x, v);
    else if(x > mid) update(rc, x, v);
    pushup(p, s, e);
}

int query(int p, int s, int e, int l, int r)
{
    if(l <= s && e <= r) return lcis[p];
    int ret = 0;
    if(val[mid + 1] > val[mid])
        ret = min(r, mid + lle[rp]) - max(l, mid + 1 - lri[lp]) + 1;
    if(l <= mid)  ret = max(ret, query(lc, l, r));
    if(r > mid)  ret = max(ret, query(rc, l, r));
    return ret;
}

int main()
{
    int T, n, m, a, b;
    char op[5];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        build(1, 0, n - 1);
        while(m--)
        {
            scanf("%s%d%d", op, &a, &b);
            if(op[0] == 'Q')
                printf("%d\n", query(1, 0, n - 1, a, b));
            else update(1, 0, n - 1, a, b);
        }
    }
    return 0;
}
//Last modified :  2015-08-10 21:12 CST

/*
1
10 10
7 7 3 3 5 9 9 8 1 8
Q 6 6
U 3 4
Q 0 1
Q 0 5
Q 4 7
Q 3 5
Q 0 2
Q 4 6
U 6 10
Q 0 9
*/

