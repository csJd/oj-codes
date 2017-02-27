#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
typedef long long ll;
ll sum[N];
int n, d, p, r[N];
struct frd
{
    int m, s;
    bool operator< (const frd &f) const
    {
        return m < f.m;
    }
} a[N];

int main()
{
    while(~scanf("%d%d", &n, &d))
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i].m, &a[i].s);
        sort(a + 1, a + n + 1);
        ll ans = sum[0] = 0;
        for(int i = p = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + a[i].s;

        for(int i = p = 1; i <= n; ++i)
        {
            while(p <= n && a[p].m - a[i].m < d) ++p;
            ans = max(ans, sum[p - 1] - sum[i - 1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-23 00:51 CST

