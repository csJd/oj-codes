#include <bits/stdc++.h>
using namespace std;
int dp[8][10];

int dfs(int i, int j) //���仯����ͳ���� j ��ͷ�� i λ�����������ĸ���
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

int getNum(int a) //ͳ��[0,a)��������������������ĸ���
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
            break;    //�Ѿ�������������
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < 10; ++i) dp[1][i] = (i != 4); //�߽�

    int n, m;
    while(scanf("%d%d", &n, &m), n || m)
        printf("%d\n", getNum(m + 1) - getNum(n));

    return 0;
}
//Last modified :   2015-07-22 15:22

