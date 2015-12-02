#include<cstdio>
using namespace std;
const int N = 110;
char mat[N][N];

int dfs(int r, int c)
{
    if(mat[r][c] != '@') return 0;
    else
    {
        mat[r][c] = '*';
        for(int i = -1; i <= 1; ++i)
            for(int j = -1; j <= 1; ++j)
                if(mat[r + i][c + j] == '@')
                    dfs(r + i, c + j);
    }
    return 1;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) , m)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%s", mat[i] + 1);

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                ans += dfs(i, j);
        printf("%d\n", ans);
    }
    return 0;
}

