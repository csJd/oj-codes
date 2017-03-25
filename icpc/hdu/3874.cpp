#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 500005, M = 2000005;
int a[N], last[1000005],n;
ll ans[M], bit[N];

struct query
{
    int s, e, id;
} q[N];

bool cmp(query &i, query &j)
{
    return i.e < j.e;
}

void add(int x, int v)
{
    while(x <= n)
    {
        bit[x] += v;
        x += x & -x;
    }
}

ll sum(int x)
{
    ll ret  = 0;
    while(x)
    {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

int main()
{
    int T, m, s, e;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            add(i, a[i]);
        }

        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
            scanf("%d%d", &q[i].s, &q[i].e), q[i].id = i;
        sort(q, q + m, cmp);

        int del = 1;
        memset(last, 0, sizeof(last));
        for(int i = 0; i < m; ++i)
        {
            int j = q[i].id;
            s = q[i].s, e = q[i].e;
            for(int  k = del; k <= e; ++k)
            {
                if(last[a[k]])
                    add(last[a[k]], -a[k]);
                last[a[k]] = k;
            }
            del = e + 1;
            ans[j] = sum(e) - sum(s - 1);
        }

        for(int i = 0; i < m; ++i)
            printf("%lld\n", ans[i]);

    }
    return 0;
}
//Last modified :   2015-07-31 10:42
