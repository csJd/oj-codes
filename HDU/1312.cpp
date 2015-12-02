#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int x[] = { -1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
char g[N][N], v[N][N];
int  cnt, n, m;

void dfs(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m || v[r][c] || g[r][c] == '#') return;
    ++cnt, v[r][c] = 1;
    for(int i = 0; i < 4; ++i)
        dfs(r + x[i], c + y[i]);
}

int main()
{
    while(scanf("%d%d", &m, &n),n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%s", g[i]);
        memset(v, 0, sizeof(v));
        cnt = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(g[i][j] == '@') dfs(i, j);
        printf("%d\n", cnt);
    }
    return 0;
}
//Last modified :   2015-07-05 18:56

