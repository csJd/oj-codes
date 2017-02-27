#include <bits/stdc++.h>
using namespace std;
int dp[8][10];

int dfs(int i, int j) //记忆化搜索统计以 j 开头的 i 位数满足条件的个数
{
    if(dp[i][j] > -1) return dp[i][j];

    dp[i][j] = 0;
    for(int k = 0; k < 10; ++k)
    {
        if(j == 4 || (j == 6 && k == 2)) continue;
        dp[i][j] += dfs(i - 1, k);
    }
    return dp[i][j];
}

int getNum(int a) //统计[0,a)这个区间满足条件的数的个数
{
    int s[10] = {0};
    int i = 0, ret = 0;
    while(a)
    {
        s[i++] = a % 10;
        a /= 10;
    }

    while(i--)
    {
        for(int j = 0; j < s[i]; ++j)
            if(!(j == 2 && s[i + 1] == 6))
                ret += dfs(i + 1, j);
        if(s[i] == 4 || (s[i] == 2 && s[i + 1] == 6))
            break;    //已经不满足条件了
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < 10; ++i) dp[1][i] = (i != 4); //边界

    int n, m;
    while(scanf("%d%d", &n, &m), n || m)
        printf("%d\n", getNum(m + 1) - getNum(n));

    return 0;
}
//Last modified :   2015-07-22 15:22

