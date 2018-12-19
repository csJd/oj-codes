#include <cstdio>
#include <cstring>
#define lc p<<1, s, mid
#define rc p<<1|1, mid + 1, e
#define mid ((s + e)>>1)
using namespace std;
const int N = 100005;

typedef long long ll;
ll sum[N << 2], add[N << 2];

void pushup(int p)
{
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void pushdown(int p, int s, int e)
{
    if(!add[p]) return;
    add[p << 1] += add[p];
    add[p << 1 | 1] += add[p];
    sum[p << 1] += add[p] * (mid - s + 1);
    sum[p << 1 | 1] += add[p] * (e - mid);
    add[p] = 0;
}

void build(int p, int s, int e)
{
    add[p] = 0;
    if(s == e)
    {
        scanf("%I64d", &sum[p]);
        return;
    }
    build(lc);
    build(rc);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void update(int p, int s, int e, int l, int r, ll v)
{
    if(l <= s && e <= r)
    {
        sum[p] += v * (e - s + 1);
        add[p] += v;
        return;
    }
    pushdown(p, s, e);
    if(l <= mid) update(lc, l, r, v);
    if(r > mid) update(rc, l, r, v);
    pushup(p);
}

ll query(int p, int s, int e, int l, int r)
{
    if(l <= s && e <= r) return sum[p];
    pushdown(p, s, e);
    ll ret = 0;
    if(l <= mid) ret += query(lc, l, r);
    if(r > mid) ret += query(rc, l, r);
    pushup(p);
    return ret;
}

int main()
{
    int n, m, l, r;
    ll v;
    char op[5];
    while(~scanf("%d%d", &n, &m))
    {
        memset(sum, 0, sizeof(sum));
        build(1, 1, n);
        while(m--)
        {
            scanf("%s%d%d", op, &l, &r);
            if(op[0] == 'Q')
                printf("%I64d\n", query(1, 1, n, l, r));
            else
            {
                scanf("%I64d", &v);
                update(1, 1, n, l, r, v);
            }
        }
    }
    return 0;
}
//Last modified :  2015-10-11 18:07 CST

