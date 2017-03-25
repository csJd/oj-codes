#include<cstdio>
#include<algorithm>
#define lc p<<1,s,mid
#define rc p<<1|1,mid+1,e
#define mid ((s+e)>>1)
using namespace std;
const int N = 200005;
int maxv[N << 2];

void pushup(int p)
{
    maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]);
}

void build(int p, int s, int e)
{
    if(s == e) scanf("%d", &maxv[p]);
    else
    {
        build(lc);
        build(rc);
        pushup(p);
    }
}

void update(int p, int s, int e, int a, int b)
{
    if(s == e && e == a)
    {
        maxv[p] = b;
        return;
    }
    if(a <= mid) update(lc, a, b);
    else update(rc, a, b);
    pushup(p);
}

int query(int p, int s, int e, int l, int r)
{
    if(s >= l && e <= r) return maxv[p];
    if(r <= mid) return query(lc, l, r);
    if(l > mid) return query(rc, l, r);
    return max(query(lc, l, mid), query(rc, mid + 1, r));
}

int main()
{
    int n, m, a, b;
    char c[2];
    while(~scanf("%d%d", &n, &m))
    {
        build(1, 1, n);
        while(m--)
        {
            scanf("%s%d%d", c, &a, &b);
            if(c[0] == 'Q') printf("%d\n", query(1, 1, n, a, b));
            else update(1, 1, n, a, b);
        }
    }
    return 0;
}
