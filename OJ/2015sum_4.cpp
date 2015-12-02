#include <cstdio>
#include <cstring>
#include <algorithm>
#define lc p<<1,s,mid
#define rc p<<1|1,mid+1,e
#define mid ((s+e)>>1)
using namespace std;
const int N = 100005;
int a[N * 4], setv[N * 4];

int gcd(int m, int n)
{
    return n ? gcd(n, m % n) : m;
}

void pushdown(int p)
{
    if(setv[p] == -1) return;
    a[p << 1] = a[p << 1 | 1] = setv[p];
    setv[p << 1] = setv[p << 1 | 1] = setv[p];
    setv[p] = -1;
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        scanf("%d", &a[p]);
        return;
    }
    build(lc);
    build(rc);
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(s == l && e == r)
    {
        a[p] = setv[p] = v;
        return;
    }
    pushdown(p);
    if(r <= mid) update(lc, l, r, v);
    else if(l > mid) update(rc, l, r, v);
    else update(lc, l, mid, v), update(rc, mid + 1, r, v);
}

void update_gcd(int p, int s, int e, int l, int r, int v)
{
    if(s >= l && e <= r)
    {
        if(setv[p] != -1)
        {
            if(setv[p] > v)
                a[p] = setv[p] = gcd(setv[p], v);
            return;
        }
        if(s == e)
        {
            if(a[p] > v);
            a[p] = gcd(a[p], v);
            return;
        }
    }
    pushdown(p);
    if(mid >= l) update_gcd(lc, l, r, v);
    if(mid + 1  <= r) update_gcd(rc, l, r, v);
}

int query(int p, int s, int e, int x)
{
    if(s == e) return a[p];
    pushdown(p);
    if(x <= mid) return query(lc, x);
    return query(rc, x);
}

int main()
{

    int T, n, q, l, r, op, x;
    scanf("%d", &T);
    while(T--)
    {
        memset(setv, -1, sizeof(setv));
        scanf("%d", &n);
        build(1, 1, n);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d%d%d", &op, &l, &r, &x);
            if(op == 1) update(1, 1, n, l, r, x);
            else update_gcd(1, 1, n, l, r, x);
        }
        for(int i = 1; i <= n; ++i)
            printf("%d ", query(1, 1, n, i));
        puts("");
    }
    return 0;
}



