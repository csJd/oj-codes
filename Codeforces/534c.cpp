#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long LL;
LL a[N], b[N], s, sum, le, ri;
int main()
{
    int n;
    while(~scanf("%d%I64d", &n, &sum))
    {
        s = 0;
        for(int i = 1; i <= n; ++i)
            scanf("%I64d", &a[i]), s += a[i];
        for(int i = 1; i <= n; ++i)
        {
            le = max(LL(1), sum - (s - a[i]));
            ri = min(a[i], sum - (n - 1));
            b[i] = a[i] - (ri - le + 1);
        }
        for(int i = 1; i < n; ++i) printf("%I64d ", b[i]);
        printf("%I64d\n", b[n]);
    }
    return 0;
}

