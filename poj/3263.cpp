#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 10005;
int cnt[N << 2]; //记录对应区间被计数了多少次

void pushdown(int p)
{
    if(cnt[p] == 0) return;
    cnt[p << 1] += cnt[p];
    cnt[p << 1 | 1] += cnt[p];
    cnt[p] = 0;
}

void build()
{
    memset(cnt, 0, sizeof(cnt));
}

void update(int p, int s, int e, int l, int r)
{
    if(l <= s && e <= r)
    {
        cnt[p] += 1;
        return;
    }
    pushdown(p);
    if(l <= mid) update(lc, l, r);
    if(r > mid) update(rc, l, r);
}

int query(int p, int s, int e, int x)
{
    if(s == e) return cnt[p];
    pushdown(p);
    if(x <= mid) return query(lc, x);
    return query(rc, x);
}

struct See
{
    int a, b;
    bool operator< (const See &s) const
    {
        return a < s.a || (a == s.a && b < s.b);
    }
} see;

int main()
{
    int n, i, h, r;
    while(~scanf("%d%d%d%d", &n, &i, &h, &r))
    {
        set<See> data;
        build();
        while(r--)
        {
            scanf("%d%d", &see.a, &see.b);
            if(see.a > see.b) swap(see.a, see.b);
            if(see.a + 1  < see.b && (data.insert(see)).second)
                update(1, 1, n, see.a + 1, see.b - 1);
        }

        for(int j = 1; j <= n; ++j)
            printf("%d\n", h - query(1, 1, n, j));

    }
    return 0;
}
//Last modified :  2016-02-15 21:37 CST

