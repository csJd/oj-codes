#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int a[N], s[N], n;

int maxs(int l, int r)
{
    if(l == r) return a[r];
    int m, ret, ls, rs;
    m = (l + r) >> 1;
    ret = max(maxs(l, m), maxs(m + 1, r));
    ls = a[m], rs = a[m + 1];
    for(int i = m; i >= l; --i) ls = max(ls, s[m] - s[i - 1]);
    for(int i = m + 1; i <= r; ++i) rs = max(rs, s[i] - s[m]);
    return max(ret, ls + rs);
}

int main()
{
    while(~scanf("%d", &n))
    {
        s[0] = 0;
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
        printf("%d\n", maxs(1, n));
    }
    return 0;
}
