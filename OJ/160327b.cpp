#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 305;
int dp[N][N], s[N];

int main()
{
    int T, t, m, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &m, &n);
        s[0] = 0;
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d", &t);
            s[i] = s[i-1] + t;
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                for(int k = 0; k < i; ++k)
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], s[i] - s[k]));
            }
        }
        printf("%d\n", dp[m][n]);
    }
    return 0;
}
