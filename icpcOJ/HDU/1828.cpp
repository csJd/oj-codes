#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10005, M = N * 4;

struct SLine
{
    int x, y1, y2, flag;
    SLine() {}
    SLine(int xx, int a, int b, int f):
        x(xx), y1(a), y2(b), flag(f) {}
    bool operator< (const SLine &s) const
    {
        if(x == s.x) return flag > s.flag;
        //有入边出边在一条线上时 要先扫描入边 不然周长可能会多算重叠部分
        return x < s.x;
    }
} line[N];

int num[M], cnt[M], len[M], y[N];
bool lh[M], rh[M];

void pushup(int p, int s, int e)
{
    if(cnt[p])
    {
        len[p] = y[e] - y[s - 1];
        num[p] = lh[p] = rh[p] = 1;
    }
    else if(s == e)
        len[p] = num[p] = lh[p] = rh[p] = 0;
    else  //区间合并
    {
        len[p] = len[p << 1] + len[p << 1 | 1];
        num[p] = num[p << 1] + num[p << 1 | 1];
        lh[p] = lh[p << 1], rh[p] = rh[p << 1 | 1];
        if(rh[p << 1] && lh[p << 1 | 1]) --num[p];
    }
}

void update(int p, int s, int e, int l, int r, int v)
{
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
    int n, m, x1, y1, x2, y2;
    while(~scanf("%d", &n))
    {
        for(int i = m = 0; i < n; ++i)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            y[m] = y1, y[m + 1] = y2;
            line[m++] = SLine(x1, y1, y2, 1);
            line[m++] = SLine(x2, y1, y2, -1);
        }
        sort(line, line + m);
        sort(y, y + m);

        int ans = 0, last = 0, l, r;
        for(int i = 0; i < m; ++i)
        {
            l = lower_bound(y, y + m, line[i].y1) - y + 1;
            r = lower_bound(y, y + m, line[i].y2) - y;
            update(1, 1, m, l, r, line[i].flag);
            if(i < m - 1) ans += 2 * num[1] * (line[i + 1].x - line[i].x);
            ans += abs(len[1] - last);
            last = len[1];
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-08-13 08:58 CST
/*
2
0 0 1 1
1 0 2 1
*///6

