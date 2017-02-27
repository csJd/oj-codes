#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int a[N], v[N];
int main()
{
    int n, t, ans;
    while(~scanf("%d", &n))
    {
        ans = 0;
        memset(v, 0, sizeof(v));
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &t);
            while(v[t]) ++t, ++ans;
            v[t] = 1, a[i] = t;
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :   2015-05-23 00:30

