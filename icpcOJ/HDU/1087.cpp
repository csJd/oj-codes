#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int dp[N], a[N];

int main()
{
    int n, ans;
    while(scanf("%d", &n), n)
    {
        ans = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            dp[i] = a[i];
            for(int j = 0; j < i; ++j)
                if(a[i] > a[j]) dp[i] = max(dp[i], a[i] + dp[j]);
            if(dp[i] > ans) ans = dp[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
