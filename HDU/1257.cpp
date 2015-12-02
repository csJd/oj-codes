#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int h[N], dp[N];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int ans = 0;
        for(int i = 0; i < n ; ++i)
        {
            dp[i] = 1;
            scanf("%d", &h[i]);
            for(int j = 0; j < i; ++j)
                if(h[j] < h[i]) dp[i] = max(dp[i], dp[j] + 1);
            if(dp[i] > ans) ans = dp[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-08 21:39 CST

