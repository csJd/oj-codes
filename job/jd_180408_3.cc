// 象棋中马k步从(0, 0)走到(x, y)的方法数; K <= 1e5, 0 =< x,y <= 8
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 8;
const int MOD = 1e9 + 7;

int dx[] = {-2, -2, -1, -1,  1,  1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int valid(int x, int y)
{
    return (x >= 0 && x <= 8 && y >= 0 && y <= 8);
}

int dp[MAXN][MAXM][MAXM];

int main()
{

    dp[0][0][0] = 1;
    int x, y;
    for(int i = 1; i < MAXN; ++i)
    {
        for(int j = 0; j <= MAXM; ++j)
        {
            for(int  k = 0; k <= MAXM; ++k)
            {
                for(int d = 0; d < 8; ++d)
                {
                    x = j + dx[d];
                    y = k + dy[d];
                    if(valid(x, y))
                    {
                        dp[i][j][k] += dp[i - 1][x][y];
                        dp[i][j][k] %= MOD;
                    }
                }
            }
        }
    }

    int k;
    while(~scanf("%d %d %d", &k, &x, &y))
    {
        printf("%d\n", dp[k][x][y]);
    }
    return 0;

}
