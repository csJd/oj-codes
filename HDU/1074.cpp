#include <cstdio>
#include <cstring>
using namespace std;
const int N = 16, M = 1 << N;
int d[N], c[N], n;
int dp[M], pre[M], t[M];
char s[N][105];

void print(int k)
{
    if(k == 0) return;
    print(pre[k]);
    k -= pre[k];
    for(int i = 0; i < n; ++i)
        if(k & 1 << i) puts(s[i]);
}

int main()
{
    int T, m, cost;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%s%d%d", s[i], &d[i], &c[i]);
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = t[0] = 0;  //边界 所有作业都没做的扣分为0
        m = 1 << n;

        for(int i = 1; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if((i & 1 << j) == 0) continue;
                int k = i - (1 << j);
                t[i] = t[k] + c[j];
                cost = t[i] > d[j] ? t[i] - d[j] : 0;
                if(dp[k] + cost <= dp[i])  //'='保证字典序最小
                {
                    dp[i] = dp[k] + cost;
                    pre[i] =  k;  //记录路径
                }
            }
        }
        printf("%d\n", dp[m - 1]);
        print(m - 1);  //打印路径
    }
    return 0;
}
//Last modified :  2015-08-28 09:33 CST

