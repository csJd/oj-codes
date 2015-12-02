#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2005;
int v[N], dp[N][N], n;

int main()
{
    while(~scanf("%d", &n))
    {
        memset(v, 0, sizeof(v));
        int ans = dp[1][n] = 0;  //dp[i][j]表示i左边和j右边的全部取完的最大和
        for(int i = 1; i <= n; ++i)
            scanf("%d", &v[i]);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = n; j >= i; --j)
            {
                int k = n - (j - i + 1);
                dp[i][j] = max(dp[i - 1][j] + k * v[i - 1], dp[i][j + 1] + k * v[j + 1]);
                if(i == j) ans = max(ans, dp[i][j] + v[i] * n);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-15 21:37 CST

