#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[] = {0, 0, -1, 1};
int y[] = { -1, 1, 0, 0};
char g[N][N];
int ans[N][N];
int n, m;

int dfs(int r, int c, int v)
{
    if(ans[r][c] >= v) return 0;
    int ret = 0;
    ans[r][c] = v;
    for(int i = 0; i < 4; ++i)
    {
        int nr = r + x[i], nc = c + y[i];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(g[nr][nc] == '*') ++ret;
        else ret += dfs(nr, nc, v);
    }
    return ret;
}

int main()
{
    int q, r, c;
    while(~scanf("%d%d%d", &n, &m, &q))
    {
        for(int i = 0; i < n; ++i) scanf("%s", g[i]);
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
                if(g[i][j] == '.' && !ans[i][j])
                {
                    ans[i][j] = dfs(i, j, 1);
                    dfs(i, j, ans[i][j] + 1);
                }
        }

//        for(int i = 0; i < n; ++i)
//        {
//            for(int j = 0; j < m; ++j)
//                printf("%d ", ans[i][j]);
//            puts("");
//        }

        while(q--)
        {
            scanf("%d%d", &r, &c);
            printf("%d\n", ans[r - 1][c - 1] - 1);
        }
    }
    return 0;
}
//Last modified :  2015-11-14 08:39 CST
