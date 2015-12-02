#include <bits/stdc++.h>
using namespace std;
const int N = 35, M = 11;
int l[N][M], pre[N], dp[N], n, m;

bool smaller(int a, int b)
{
    for(int i = 0; i < m; ++i)
        if(l[a][i] >= l[b][i]) return false;
    return true;
}

int lis(int i)
{
    if(dp[i] > 0) return dp[i];
    dp[i] = 1;
    for(int j = 0; j < n; ++j)
    {
        if(smaller(j, i) && lis(j) + 1 > dp[i])
            dp[i] = lis(j) + 1, pre[i] = j;
    }
    return dp[i];
}

void print(int i)
{
    if(pre[i] != -1)
    {
        print(pre[i]);
        printf(" %d", i + 1);
    }
    else printf("%d", i + 1);
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
                scanf("%d", &l[i][j]);
            sort(l[i], l[i] + m);
        }

        int ans = 0;
        memset(dp, 0, sizeof(dp));
        memset(pre, -1, sizeof(pre));
        for(int i = 0; i < n; ++i)
            if(lis(i) > dp[ans]) ans = i;

        printf("%d\n", dp[ans]);
        print(ans);
        puts("");
    }
    return 0;
}
//Last modified :  2015-08-19 09:15 CST

