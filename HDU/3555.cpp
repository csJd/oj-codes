#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull dp[21][3];

void init()
{
    dp[0][2] = 1;
    for(int i = 1; i < 20; ++i)
    {
        dp[i][0] = dp[i - 1][0] * 10 + dp[i - 1][1]; //含有49
        dp[i][1] = dp[i - 1][2];            //不含49但以9开头
        dp[i][2] = dp[i - 1][2] * 10 - dp[i - 1][1]; //不含49
    }
}

ull calc(ull n)
{
    int bit[21];
    int i = 0, flag = 0;
    ull ret = 0;
    while(n)
    {
        bit[++i] = n % 10;
        n /= 10;
    }
    while(i)
    {
        ret += dp[i - 1][0] * bit[i];
        if(flag) ret += dp[i - 1][2] * bit[i];
        else if(bit[i] > 4)
            ret += dp[i - 1][1];
        if(bit[i] == 9 && bit[i + 1] == 4) flag = 1;
        --i;
    }
    return ret;
}

int main()
{
    int T;
    ull n;
    init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%llu", &n);
        printf("%llu\n", calc(n + 1));
    }
    return 0;
}
//Last modified :   2015-07-22 20:12
//9223372036854775807
