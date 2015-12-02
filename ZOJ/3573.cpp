#include <cstdio>
#include <cstring>
#include <algorithm>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s + e)>>1)

using namespace std;
const int N = 15005;
int maxv[N * 4], add[N * 4];

void pushup(int p)
{
    maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]);
}

void pushdown(int p)
{
    if(!add[p]) return;
    add[p << 1] += add[p];
    maxv[p << 1] += add[p];
    add[p << 1 | 1] += add[p];
    maxv[p << 1 | 1] += add[p];
    add[p] = 0;
}

void build()
{
    memset(maxv, 0, sizeof(maxv));
    memset(add, 0, sizeof(add));
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(l <= s && e <= r)
    {
        maxv[p] += v;
        add[p] += v;
        return;
    }
    pushdown(p);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p);
}

int queryle(int p, int s, int e, int v)
{
    if(s == e) return s;
    pushdown(p);
    if(maxv[p << 1] >= v) return queryle(lc, v);
    return queryle(rc, v);
}

int queryri(int p, int s, int e, int v)
{
    if(s == e) return s;
    pushdown(p);
    if(maxv[p << 1 | 1] >= v) return queryri(rc, v);
    return queryri(lc, v);
}

int main()
{
    int n, l, r, v;
    while(~scanf("%d", &n))
    {
        build();
        while(scanf("%d%d%d", &l, &r, &v), l >= 0)
            update(1, 0, n, l, r, v);
        l = queryle(1, 0, n, maxv[1]);
        r = queryri(1, 0, n, maxv[1]);
        printf("%d %d\n", l, r);
    }
    return 0;
}
//last modified :   2015-07-30 13:17


