#include <cstdio>
#include <algorithm>
#define lc p<<1, s, mid
#define rc p<<1|1, mid + 1 , e
#define mid ((s+e)>>1)
using namespace std;
const int N = 2005;
int a[N], n;
int maxv[N * 4];

void pushup(int p)
{
    maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]);
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        if(s > n) s -= n;
        maxv[p] = a[s];
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}

int query(int p, int s, int e, int l, int r)
{
    if(l <= s && e <= r) return maxv[p];
    int ret = 0;
    if(l <= mid) ret = max(ret, query(lc, l, r));
    if(r > mid) ret = max(ret, query(rc, l, r));
    return ret;
}

int main()
{
    int cas = 0, m, l, r;
    while(~scanf("%d", &n))
    {
        printf("Case #%d:\n", ++cas);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        build(1, 1, 2 * n);
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d%d", &l, &r);
            if(r < l) r += n;
            printf("%d\n", query(1, 1, n * 2, l, r));
        }
        puts("");
    }
    return 0;
}
//Last modified :  2015-08-11 12:49 CST

