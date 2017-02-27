#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N], s[N], w[N], fol[N], n;

int dfs(int i)
{
    if(dp[i]) return dp[i];
    dp[i] = 1, fol[i] = -1;
    for(int j = 0; j < n; ++j)
        if(w[j] > w[i] && s[j] < s[i] && dp[i] < dfs(j) + 1)
            dp[i] = dp[j] + 1, fol[i] = j;
    return dp[i];
}

int main()
{
    int m = 0;
    while(~scanf("%d%d", &w[n], &s[n])) ++n;
    for(int i = 0; i < n; ++i)
        if(dfs(i) > dfs(m)) m = i;
    printf("%d\n", dp[m]);
    while(m >= 0)
    {
        printf("%d\n", m + 1);
        m = fol[m];
    }
    return 0;
}
//Last modified :  2015-09-12 09:44 CST

