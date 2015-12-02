#include<cstdio>
#include<cstring>
using namespace std;
const int N = 55;
char mat[N][N];
int type[11][4] = {   //对应11种水管类型 按顺时针方向有管道的为1否则为0
    {1, 0, 0, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0},
    {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {1, 0, 1, 1},
    {0, 1, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
};

int dfs(int r, int c)
{
    int cur = mat[r][c] - 'A';
    if(cur < 0 || cur > 10) return 0;
    mat[r][c] = 0;           //标记已经访问 0-'A'是小于0的
    int up = mat[r - 1][c] - 'A', dw = mat[r + 1][c] - 'A',
        le = mat[r][c - 1] - 'A', ri = mat[r][c + 1] - 'A';  //4个相邻块的管道类型
    if(up > -1 && up < 11 && type[up][2] && type[cur][0])  dfs(r - 1, c);
    if(dw > -1 && dw < 11 && type[dw][0] && type[cur][2])  dfs(r + 1, c);
    if(le > -1 && le < 11 && type[le][1] && type[cur][3])  dfs(r, c - 1);
    if(ri > -1 && ri < 11 && type[ri][3] && type[cur][1])  dfs(r, c + 1);
    return 1;     //一个连通块中只有一个返回1
}

int main()
{
    int n, m, ans;
    while (scanf("%d%d", &n, &m), n >= 0)
    {
        ans = 0;
        memset(mat, 0, sizeof(mat));
        for(int i = 1; i <= n; ++i)
            scanf("%s", mat[i] + 1);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                ans += dfs(i, j);
        printf("%d\n", ans);
    }
    return 0;
}
