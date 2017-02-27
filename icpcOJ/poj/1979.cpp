#include<cstdio>
#include<cstring>
using namespace std;
const int N = 30;
char mat[N][N];
int dx[4] = {0, 0, -1, 1}, dy[4] = { -1, 1, 0, 0};
int ans;

void dfs(int r, int c)
{
    if(mat[r][c] != '.') return;
    mat[r][c] = '#';
    for(int i = 0; i < 4; ++i)
    {
        int x = r + dx[i], y = c + dy[i];
        if(mat[x][y] == '.')
        {
            dfs(x, y);
            ++ans;
        }
    }
}

int main()
{
    int m, n, sx, sy;
    while(scanf("%d%d", &m, &n), m)
    {
        memset(mat, 0, sizeof(mat));
        for(int i = 1; i <= n; ++i)
            scanf("%s", mat[i] + 1);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(mat[i][j] == '@') sx = i, sy = j;
        ans = 1;
        dfs(sx, sy);
        printf("%d\n", ans);
    }
}
