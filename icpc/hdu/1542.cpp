#include <cstdio>
#include <cstring>
#include <algorithm>
#define lc p<<1, s, mid
#define rc p<<1|1, mid + 1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 205;
int cnt[N * 4];
double len[N * 4], y[N];

struct SLine
{
    double x, y1, y2;
    int flag;
    SLine() {}
    SLine(double a, double b, double c, int t):
        x(a), y1(b), y2(c), flag(t) {}
    bool operator< (const SLine &s) const
    {
        return x < s.x;
    }
} line[N];

void pushup(int p, int s, int e)
{
    if(cnt[p]) len[p] = y[e] - y[s - 1];
    else if(s == e) len[p] = 0;
    else len[p] = len[p << 1] + len[p << 1 | 1];
}

void build()
{
    memset(len, 0, sizeof(len));
    memset(cnt, 0, sizeof(cnt));
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(l <= s && e <= r)
    {
        cnt[p] += v;
        pushup(p, s, e);
        return;
    }
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p, s, e);
}

int main()
{
    int n, m, cas = 0;
    double x1, y1, x2, y2;
    while(scanf("%d", &n), n)
    {
        build();
        m = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            y[m] = y1, y[m + 1] = y2;
            line[m++] = SLine(x1, y1, y2, 1);
            line[m++] = SLine(x2, y1, y2, -1);
        }
        sort(line, line + m);
        sort(y, y + m); //compress

        double sum = 0;
        for(int i = 0; i < m - 1; ++i)
        {
            int l = lower_bound(y, y + m, line[i].y1) - y;
            int r = lower_bound(y, y + m, line[i].y2) - y;
            update(1, 1, m, l + 1, r, line[i].flag);
            sum += len[1] * (line[i + 1].x - line[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++cas, sum);
    }
    return 0;
}
//Last modified :  2015-08-12 15:36 CST
/*
2
0 0 2 3
1 1 3 2
*/

