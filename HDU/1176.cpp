#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 11;
int dp[N][M], num[N][M];

int main()
{
    int n, x, t;
    while(scanf("%d", &n), n)
    {
        memset(num, 0, sizeof(num));
        memset(dp, 0x9f, sizeof(dp));
        dp[0][5] = 0;

        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x, &t);
            ++num[t][x];
        }

        int ans = 0;
        for(int i = 1; i < N; ++i)
        {
            for(int j = 0; j < M; ++j)
            {
                for(int k = -1; k < 2; ++k)
                {
                    if(j + k < 0 || j + k > 10) continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k] + num[i][j]);
                }
                if(dp[i][j] > ans) ans = dp[i][j];
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-08 19:53 CST

