#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000005;
int dp[N], pre[N], a[N];
///dp[i][j] 表示在前j个数中取i段(j在最后一段中)的最大值
///dp[i][j] = max(dp[i][j - 1], max{dp[i - 1][k], i - 1 <= k < j}) + a[j];
int main()
{
    int n, m, ans;
    while(~scanf("%d%d", &m, &n))
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        memset(pre, 0, sizeof(pre));
        for(int i = 1; i <= m; ++i)
        {
            ans = -233333333;
            for(int j = i; j <= n; ++j)
            {
                dp[j] = max(dp[j - 1], pre[j - 1]) + a[j];
                //pre[j - 1]维护max{dp[i-1][k] | i - 1 <= k <= j - 1}

//                for(int k = i - 1; k < j; ++k)
//                    dp[i][j] = max(dp[i][j], dp[i - 1][k]);
//                dp[i][j] += a[i];
                pre[j - 1] = ans;
                ans = max(ans, dp[j]); //ans保存的是max{dp[i][k] | i <= k <= j}
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-08-26 13:25 CST

