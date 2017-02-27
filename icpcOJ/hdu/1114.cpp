#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 505, M = 10005;
int dp[M], w, v;

int main()
{
    int n, m, e, f, T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &e, &f, &n);
        m = f - e;
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d %d", &v, &w);
            for(int j = w; j <= m; ++j)
                dp[j] = min(dp[j], dp[j - w] + v);
        }
        if(dp[m] < dp[m + 1])
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[m]);
        else puts("This is impossible.");
    }
    return 0;
}
//Last modified :  2015-08-28 15:16 CST

