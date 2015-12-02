#include <cstdio>
#include <algorithm>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define lp p<<1
#define rp p<<1|1
#define mid ((s+e)>>1)
using namespace std;
const int N = 100005, M = N * 4;
//最大连续i的长度 左端连续长度 右端连续长度
int len[2][M], lle[2][M], lri[2][M];
int opp[M], setv[M], sum[M];

void swap01(int p)  //将p对应区间的01信息交换
{
    swap(len[0][p], len[1][p]);
    swap(lle[0][p], lle[1][p]);
    swap(lri[0][p], lri[1][p]);
}

void setAll(int p, int i, int v) //将p对应的区间全部置为i
{
    int j = 1 - i;
    len[i][p] = lle[i][p] = lri[i][p] = v;
    len[j][p] = lle[j][p] = lri[j][p] = 0;
}

void pushup(int p, int s, int e)
{
    sum[p] = sum[lp] + sum[rp];
    for(int i = 0; i < 2; ++i)
    {
        len[i][p] = max(len[i][lp], len[i][rp]);
        lle[i][p] = lle[i][lp], lri[i][p] = lri[i][rp];
        if(lri[i][lp] && lle[i][rp]) //左右孩子边界可连接
        {
            len[i][p] = max(len[i][p], lri[i][lp] + lle[i][rp]);
            if(lle[i][lp] == mid + 1 - s) lle[i][p] += lle[i][rp];
            if(lri[i][rp] == e - mid) lri[i][p] += lri[i][lp];
        }
    }
}

void build(int p, int s, int e)
{
    opp[p] = 0;
    setv[p] = -1;
    if(s == e)
    {
        scanf("%d", &sum[p]);
        int i = sum[p];
        setAll(p, i, 1);
        return;
    }
    build(lc);
    build(rc);
    pushup(p, s, e);
}

void pushdown(int p, int s, int e)
{
    if(setv[p] != -1)
    {
        int i = setv[lp] = setv[rp] = setv[p];
        opp[lp] = opp[rp] = 0;
        sum[lp] = i * (mid + 1 - s);
        sum[rp] = i * (e - mid);

        setAll(lp, i, mid + 1 - s);
        setAll(rp, i, e-mid);
        setv[p] = -1;
    }

    if(opp[p])
    {
        opp[lp] ^= 1;
        opp[rp] ^= 1;
        sum[lp] = mid + 1 - s - sum[lp];
        sum[rp] = e - mid - sum[rp];

        swap01(lp);
        swap01(rp);
        opp[p] = 0;
    }
}

void update(int p, int s, int e, int l, int r, int v)
{
    if(l <= s && e <= r)
    {
        if(v == 2)
        {
            opp[p] ^= 1;
            sum[p] = e - s + 1 - sum[p];
            swap01(p);

        }
        else
        {
            int i = setv[p] = v;
            opp[p] = 0;
            sum[p] = v * (e - s + 1);
            setAll(p, i, e - s + 1);
        }
        return;
    }
    pushdown(p, s, e);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p, s, e);
}

int query(int p, int s, int e, int l, int r, int op)
{
    if(l <= s && e <= r) return op == 3 ? sum[p] : len[1][p];
    pushdown(p, s, e);
    int ret = 0;
    if(op == 3)  //the number of '1's
    {
        if(l <= mid) ret += query(lc, l, r, op);
        if(r > mid) ret += query(rc, l, r, op);
    }
    else  // the length of '1's
    {
        ret = max(ret, min(r, mid + lle[1][rp]) - max(l, mid + 1 - lri[1][lp]) + 1);
        if(l <= mid) ret = max(ret, query(lc, l, r, op));
        if(r > mid) ret = max(ret, query(rc, l, r, op));
    }
    return ret;
}

int main()
{
    int T, n, m, a, b, op;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        build(1, 0, n - 1);
        while(m--)
        {
            scanf("%d%d%d", &op, &a, &b);
            if(op < 3) update(1, 0, n - 1, a, b, op);
            else
                printf("%d\n", query(1, 0, n - 1, a, b, op));
        }
    }
    return 0;
}
//Last modified :  2015-08-12 09:24 CST

