#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int x[maxn], y[maxn], z[maxn], d[maxn], n;
int dp(int i)
{
    if(d[i] > 0) return d[i];
    d[i] = z[i];
    for(int j = 1; j <= n; ++j)
    {
        if((x[i] > x[j] && y[i] > y[j]) || (x[i] > y[j] && y[i] > x[j]))
            d[i] = max(d[i], dp(j) + z[i]);
    }
    return d[i];
}

int main()
{
    int a, b, c, cas = 0;
    while (scanf("%d", &n), n)
    {
        n *= 3;
        for(int i = 1; i <= n;)
        {
            scanf("%d%d%d", &a, &b, &c);
            x[i] = a, y[i] = b, z[i++] = c;
            x[i] = a, y[i] = c, z[i++] = b;
            x[i] = b, y[i] = c, z[i++] = a;
        }

        int ans = 0;
        memset(d, 0, sizeof(d));
        for(int i = 1; i <= n; ++i)
            ans = max(dp(i), ans);
        printf("Case %d: maximum height = %d\n", ++cas, ans);
    }
    return 0;
}
