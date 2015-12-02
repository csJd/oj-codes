#include <cstdio>
#include <cstring>
#include <algorithm>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
typedef long long ll;
const int N = 50;
int y[N], flag[N * 2], len[N * 2];

struct Rect
{
    int x1, y1, x2, y2, v;
    bool operator< (const Rect &r) const
    {
        return v > r.v;
    }
} r[N];

struct SLine
{
    int x, y1, y2, flag;
    SLine() {}
    SLine(int xx, int a, int b, int f):
        x(xx), y1(a), y2(b), flag(f) {}
    bool operator< (const SLine &s) const
    {
        return x < s.x;
    }
} line[N];

void build()
{
    memset(flag, 0, sizeof(flag));
    memset(len, 0, sizeof(len));
}

void pushup(int p, int s, int e)
{
    if(flag[p]) len[p] = y[e] - y[s - 1];
    else if(s == e) len[p] = 0;
    else len[p] = len[p << 1] + len[p << 1 | 1];
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(l <= s && e <= r)
    {
        flag[p] += v;
        pushup(p, s, e);
        return;
    }
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p, s, e);
}

int main()
{
    int T, n, m, cas = 0;
    int x1, y1, x2, y2, v;
    ll ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d%d%d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2, &r[i].v);
        sort(r, r + n);
        ll ans = 0, last = 0, area;

        for(int i = m = 0; i < n; ++i)
        {
            build();
            area = 0;
            y[m] = r[i].y1, y[m + 1] = r[i].y2;
            line[m++] = SLine(r[i].x1, r[i].y1, r[i].y2, 1);
            line[m++] = SLine(r[i].x2, r[i].y1, r[i].y2, -1);
            sort(y, y + m);
            sort(line, line + m);

            for(int j = 0; j < m - 1; ++j)
            {
                int l = lower_bound(y, y + m, line[j].y1) - y;
                int r = lower_bound(y, y + m, line[j].y2) - y;
                update(1, 1, m, l + 1, r, line[j].flag);
                area += len[1] * (line[j + 1].x - line[j].x);
            }

            ans += (area - last) * r[i].v;
            last = area;
        }
        printf("Case %d: %I64d\n", ++cas, ans);
    }
    return 0;
}

