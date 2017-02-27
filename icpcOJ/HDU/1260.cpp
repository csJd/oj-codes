#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int sig[N], tog[N], dp[N];

int main()
{
    int T, n, h, m, s;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &sig[i]);
        for(int i = 1; i < n; ++i)
            scanf("%d", &tog[i]);

        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0, dp[1] = sig[1];
        for(int i = 2; i <= n; ++i)
            dp[i] = min(dp[i - 1] + sig[i], dp[i - 2] + tog[i - 1]);

        s = dp[n] % 60;
        m = dp[n] / 60 % 60;
        h = 8 + dp[n] / 3600;
        if(h > 12) h -= 12;
        printf("%02d:%02d:%02d %s\n", h, m, s, h > 11 ? "pm" : "am");
    }
    return 0;
}
//Last modified :  2015-09-08 20:50 CST

