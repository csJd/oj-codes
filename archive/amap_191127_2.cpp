// 给予m个桶，每个桶有n个质量（整数）不同的球，请从每个桶抽取其中一个，使得m个球的总量为S,请输出有多少种方法。

#include <cstring>
#include <iostream>
using namespace std;

int solve(int m, int n, int s) {
    int dp[m + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // i 个桶各取一个球，总质量为 j 的方法数
    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= s; ++j) {
            for (int k = 1; k <= j && k <= n; ++k) {
                dp[i][j] += dp[i - 1][j - k]; // 第 i 个桶取质量为 k 的球
            }
        }
    }
    return dp[m][s];
}

int main() {
    cout << solve(2, 3, 4) << endl;
    cout << solve(0, 0, 0) << endl;
    return 0;
}
