#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 505;
char a[N], b[N];
int dp[N][N], n, m;

int main()
{
    while(~scanf("%s%s", a + 1, b + 1))
    {
        n = strlen(a + 1);
        m = strlen(b + 1);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        printf("%d\n", dp[n][m]);
    }
    return 0;
}
//Last modified :  2015-09-15 19:06 CST

