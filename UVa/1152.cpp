#include <bits/stdc++.h>
#define l(i) lower_bound(s,s+m,i)
#define u(i) upper_bound(s,s+m,i)
using namespace std;
const int N = 4005;
int a[N], b[N], c[N], d[N], s[N * N];

int main()
{
    int cas, m, k, n;
    long long ans;
    scanf("%d", &cas);
    while(cas--)
    {
        ans = m = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                s[m++] = a[i] + b[j];
        sort(s, s + m);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                k = -c[i] - d[j], ans += (u(k) - l(k));

        printf("%lld\n", ans);
        if(cas) puts("");
    }
    return 0;
}
