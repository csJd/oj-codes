/*
班上同学聚餐吃火锅，一锅煮了的M(1<=M<=50)个鱼丸和N(1<=N<=50)个肉丸，现欲将M个鱼丸和N个肉丸分到K(1<=K<=50)个碗中，允许有空碗，鱼丸和肉丸不允许混在同一个碗里，问共有多少种装法？假设碗足够大，能装50个鱼丸或者50个肉丸，碗之间也没有区别，因此当M=N=1，K=3时，只有1种装法，因为(1,1,0)(1,0,1)(0,1,1)被看作是同一种装法。

输入:
输入数据包含三行，每行一个整数，分别是M、N、K(1 <= M,N,K<=50)
输出:
一个整数，单独一行，输出共有多少种装法，要求输出结果对10000取模。例如，计算出共有123456种装法，则输出3456
输入范例:
1
1
3
输出范例:
1
*/

/* wrong solution */
#include <stdio.h>
#include <string.h>

int ans = 0;
const int MOD = 10000;

int dp[51][51][51];

int dfs(int i, int j, int k){
    if (i < 0 || j < 0 || k < 0){
        return 0;
    }
    if (dp[i][j][k] > 0){
        return dp[i][j][k];
    }
    dp[i][j][k] = (dfs(i-1,j,k-1) + dfs(i,j-1,k-1) + dfs(i, j, k-1));
    return dp[i][j][k];
}

int main()
{
    int m, n, k;
    dp[0][0][0] = 1;
    scanf("%d %d %d", &m, &n, &k);
    // printf("%d %d %d", m, n, k);
    printf("%d\n", dfs(m,n,k) % MOD);
    return 0;
}
