#include <bits/stdc++.h>
#define lc p<<1, s, mid
#define rc p<<1|1, mid + 1, e
#define mid ((s+e)>>1)
using namespace std;
typedef long long ll;
const int N = 100005;
ll pro[N << 2], MOD;

void pushup(int p)
{
    pro[p] = pro[p << 1] * pro[p << 1 | 1] % MOD;
}

void build(int p, int s, int e)
{
    if(s == e)
    {
        pro[p] = 1;
        return;
    }
    build(lc);
    build(rc);
    pushup(p);
}

void update(int p, int s, int e, int x, ll v)
{
    if(s == e)
    {
        pro[p] = v;
        return;
    }
    if(x <= mid) update(lc, x, v);
    else update(rc, x, v);
    pushup(p);
}

int main()
{
    int T, cas = 0, q, op, v;
    scanf("%d", &T);
    while(T--)
    {
        printf("Case #%d:\n", ++cas);
        scanf("%d%lld", &q, &MOD);
        build(1, 1, q);
        for(int i = 1; i <= q; ++i)
        {
            scanf("%d%d", &op, &v);
            if(op == 1)
                update(1, 1, q, i, v);
            else update (1, 1, q, v, 1);
            printf("%lld\n", pro[1]);
        }
    }
    return 0;
}
//Last modified :  2015-09-26 12:40 CST

