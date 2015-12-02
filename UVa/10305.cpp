#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, t, v[N], tpo[N], g[N][N];

void dfs(int j)
{
    if(v[j]) return;
    for(int i = 1; i <= n; ++i)
        if(g[i][j]) dfs(i);
    v[j] = 1;
    tpo[++t] = j;
}

int main()
{
    int a, b, i;
    while(~scanf("%d %d", &n, &m), n)
    {
        memset(g, 0, sizeof(g));
        memset(v, 0, sizeof(v));
        while(m--)
        {
            scanf("%d%d", &a, &b);
            g[a][b] = 1;
        }

        t = 0;
        for(i = 1; i <= n; ++i)
            if(!v[i]) dfs(i);
        for(i = 1; i < n; ++i)
            printf("%d ", tpo[i]);
        printf("%d\n", tpo[n]);
    }
    return 0;
}
