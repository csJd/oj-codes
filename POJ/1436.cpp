#include <cstdio>
#include <algorithm>
#include <cstring>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 1e4;
int setv[N * 8], top[N * 8];
int g[N][N];
struct seg
{
    int y1, y2, x;
} line[N];

bool cmp(seg a, seg b)
{
    return a.x < b.x;
}

void pushup(int p)
{
    top[p] = (top[p << 1] == top[p << 1 | 1]) ? top[p << 1] : 0;
}

void pushdown(int p)
{
    if(setv[p] > 0)
    {
        top[p << 1] = setv[p << 1] = setv[p];
        top[p << 1 | 1] = setv[p << 1 | 1] = setv[p];
        setv[p] = 0;
    }
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(s >= l && e <= r)
    {
        setv[p] = v;
        top[p] = v;
        return;
    }
    pushdown(p);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p);
}

void query(int p, int s, int e, int l, int r, int x)
{
    if(s >= l && e <= r && top[p])
    {
        g[top[p]][x] = 1;
        return;
    }
    if(s == e) return;
    pushdown(p);
    if(l <= mid) query(lc, l, r, x);
    if(r > mid) query(rc, l, r, x);
}

int main()
{
    int T, n, l, r;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d", &line[i].y1, &line[i].y2, &line[i].x);
        sort(line, line + n, cmp);

        memset(top, 0, sizeof(top));
        memset(setv, 0, sizeof(setv));
        memset(g, 0, sizeof(g));

        for(int i = 0; i < n; ++i)
        {
            l = (line[i].y1 + 1) * 2;
            r = (line[i].y2 + 1) * 2;
            query(1, 1, n, l, r, i + 1);
            update(1, 1, n, l, r, i + 1);
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                if(g[i][j])
                for(int k = j + 1; k <= n; ++k)
                    if(g[j][k] && g[i][k]) ++ans;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :   2015-07-14 08:03
