#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;
ll a[N], le[N], ri[N];

int main()
{
    int n, k, x;
    while(~scanf("%d%d%d", &n, &k, &x))
    {
        ll ans = 0, xx = 1;
        while(k--) xx *= x;
        le[0] = ri[n - 1] = 0;

        for(int i = 0; i < n; ++i)
        {
            scanf("%I64d", &a[i]);
            le[i + 1] = le[i] | a[i];
        }

        for(int i = n - 1; i >= 0; --i)
        {
            if(i) ri[i - 1] = ri[i] | a[i];
            ans = max(ans, le[i] | ri[i] | (a[i] * xx));
        }

        printf("%I64d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-17 00:49 CST

