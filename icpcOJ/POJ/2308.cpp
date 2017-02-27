#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 12;
char g[N][N];
int n, m, cnt[4];
int x[4] = { -1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
bool v[N][N], flag;

//当前位置(r, c), 搜索字符a, 当前方向d，改变方向次数cd
void dfs(int r, int c, char a, int d, int cd)
{
    if(flag || v[r][c] || cd > 2) return;
    if(g[r][c] == a && d != -1)
    {
        flag = true;
        g[r][c] = '*';
        return;
    }
    v[r][c] = 1;
    int nr, nc;
    for(int k = 0; k < 4; ++k)
    {
        nr = r + x[k], nc = c + y[k];
        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(g[nr][nc] == '*' || g[nr][nc] == a)
            dfs(nr, nc, a, k, cd + (k != d ? 1 : 0));
    }
}

bool gao()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j  = 0; j < m; ++j)
        {
            if(g[i][j] == '*') continue;
            memset(v, 0, sizeof(v));
            flag = false;
            dfs(i, j, g[i][j], -1, -1);
            if(flag)
            {
                g[i][j] = '*';
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d%d", &n, &m), n || m)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", g[i]);
            for(int j = 0; j < m; ++j)
                if(g[i][j] != '*') ++cnt[g[i][j] - 'A'];
        }

        if(cnt[0] % 2 || cnt[1] % 2 || cnt[2] % 2 || cnt[3] % 2)
        {
            puts("no");
            continue;
        }

        int tot = cnt[0] + cnt[1] + cnt[2] + cnt[3];
        while(tot)
        {
            if(gao()) tot -= 2;
            else break;
        }

        puts(tot ? "no" : "yes");
    }
    return 0;
}
//Last modified :   2015-08-02 21:03
/*
4 3
ABA
BAB
ABA
BAB
*/

