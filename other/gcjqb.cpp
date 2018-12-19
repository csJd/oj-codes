#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int m, n, cas, ans, cnt;
    scanf("%d", &cas);
    for(int k = 1; k <= cas; ++k)
    {
        scanf("%d", &n);
        for(int i = m = 0; i < n; ++i)
            scanf("%d", &a[i]), m = max(m, a[i]);

        ans = m;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = cnt = 0; j < n; ++j)
                cnt += a[j] / i - (a[j] % i == 0);
            ans = min(ans, i + cnt);
        }
        printf("Case #%d: %d\n", k, ans);
    }

    return 0;
}
//Last modified :   2015-04-11 22:57

