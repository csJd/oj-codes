#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int v[N][N], dp[N][N], dir[N][N], num[N << 1];
int n, m;

int main()
{
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &v[i][j]);

        memset(dp, 0x3f, sizeof(dp));
        dp[1][1] = v[1][1];
        for(int i = 1; i <= n89 ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(i == 1 && j == 1) continue;
                if(dp[i - 1][j] + v[i][j] < dp[i][j - 1] + v[i][j])
                {
                    dir[i][j] = -1;
                    dp[i][j] = dp[i - 1][j] + v[i][j];
                }
                else
                {
                    dir[i][j] = 1;
                    dp[i][j] = dp[i][j - 1] + v[i][j];
                }
            }
        }

        int i = n, j = m, k = 0;
        num[0] = v[n][m];
        while(j > 0 && j > 0)
        {
            num[k++] = v[i][j];
            if(dir[i][j] < 0) i--;
            else j--;
        }

        int ans = 0;
        for(int i = 0; i < k; ++i)
            ans += (num[i] * k - dp[n][m]) * (num[i] * k - dp[n][m]);
        printf("Case #%d: %d\n", ++cas, ans / k);

    }
    return 0;
}
//Last modified :  2015-09-27 13:51 CST

