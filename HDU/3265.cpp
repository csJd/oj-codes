#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005, M = N << 3;
typedef long long ll;

struct SLine
{
    int x, y1, y2, flag;
    SLine() {};
    SLine(int xx, int a, int b, int f) :
        x(xx), y1(a), y2(b), flag(f) {}
    bool operator< (const SLine &s) const{
        return x < s.x;
    }
} line[N << 3];

int len[M], cnt[M];

void pushup(int p, int s, int e)
{
    if(cnt[p]) len[p] = e - s + 1;
    else if(s == e) len[p] = 0;
    else len[p] = len[p << 1] + len[p << 1 | 1];
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(r < l) return;
    if(l <= s && e <= r)
    {
        cnt[p] += v;
        pushup(p, s, e);
        return;
    }
    int mid = (s + e) >> 1;
    if(l <= mid) update(p << 1, s, mid, l, r, v);
    if(r > mid) update(p << 1 | 1, mid + 1, e, l, r, v);
    pushup(p, s, e);
}

int main()
{
    int n, m, x1, y1, x2, y2, x3, y3, x4, y4, f;
    while(scanf("%d", &n), n)
    {
        m = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
            //将矩形框分成4个矩形
            line[m++] = SLine(x1, y1, y2, 1);
            line[m++] = SLine(x3, y1, y2, -1);
            line[m++] = SLine(x4, y1, y2, 1);
            line[m++] = SLine(x2, y1, y2, -1);

            line[m++] = SLine(x1, y1, y3, 1);
            line[m++] = SLine(x2, y1, y3, -1);
            line[m++] = SLine(x1, y4, y2, 1);
            line[m++] = SLine(x2, y4, y2, -1);
        }
        sort(line, line + m);

        ll ans = 0;
        for(int i = 0; i < m; ++i)
        {
            update(1, 1, N, line[i].y1 + 1, line[i].y2, line[i].flag);
            ans += ll(len[1]) * (line[i + 1].x - line[i].x);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
//Last modified :  2015-08-14 14:29 CST

