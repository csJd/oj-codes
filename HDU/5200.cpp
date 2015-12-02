#include <bits/stdc++.h>
#define lp p<<1
#define rp p<<1|1
#define lc lp, s, mid
#define rc rp, mid + 1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 50005, INF = 1e9 + 5;
int minv[N << 2], num[N << 2], cut[N << 2];
int q[N], ans[N], r[N];
bool lh[N << 2], rh[N << 2];

bool cmp(int i, int j)
{
    return q[i] < q[j];
}

void pushup(int p)
{
    minv[p] = min(minv[lp], minv[rp]);
    num[p] = num[lp] + num[rp];
    lh[p] = lh[lp], rh[p] = rh[rp];
    if(rh[lp] && lh[rp]) --num[p];
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        scanf("%d", &minv[p]);
        num[p] = lh[p] = rh[p] = 1;
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}

void update(int p, int s, int e, int v)
{
    if(s == e)
    {
        minv[p] = INF;
        num[p] = lh[p] = rh[p] = 0;
        return;
    }
    if(minv[lp] <= v) update(lc, v);
    if(minv[rp] <= v) update(rc, v);
    pushup(p);
}

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        build(1, 1, n);
        for(int i = 0; i < m; ++i)
            scanf("%d", &q[i]), r[i] = i;
        sort(r, r + m, cmp);

        for(int i = 0, j; i < m; ++i)
        {
            j = r[i];
            if(minv[1] <= q[j])
                update(1, 1, n, q[j]);
            ans[j] = num[1];
        }

        for(int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
//Last modified :  2015-08-16 08:32 CST

