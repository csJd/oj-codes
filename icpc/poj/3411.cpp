#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 11, INF = 2333333;
int n, m, ans, vis[N];
struct road{
    int a, b, c, p, r;
} rd[N];

//当前所在城市, 到过哪些城市, 当前已经用了多少过路费
void dfs(int p, int s, int v)
{
    if(vis[p] > 5) return;
    s = s | 1 << (p - 1);
    if(p == n)
    {
        ans = min(ans, v);
        return;
    }

    for(int i = 0; i < m; ++i)
    {
        if(rd[i].a != p) continue;
        ++vis[rd[i].b];
        if(s & 1 << (rd[i].c - 1)) //到过城市c
            dfs(rd[i].b, s, v + rd[i].p);
        else dfs(rd[i].b, s, v + rd[i].r);
        --vis[rd[i].b]; //回溯
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < m; ++i)
            scanf("%d%d%d%d%d", &rd[i].a, &rd[i].b, &rd[i].c, &rd[i].p, &rd[i].r);

        ans = INF;
        memset(vis, 0, sizeof(vis));
        dfs(1, 0, 0);
        if(ans == INF) puts("impossible");
        else printf("%d\n", ans);
    }

    return 0;
}
//Last modified :   2015-08-01 20:29
/*
4 5
1 2 1 10 10
2 3 1 30 50
3 4 3 80 80
2 1 2 10 10
1 3 2 10 50

6 9
1 2 1 1 1
1 3 2 1 4
1 4 3 1 6
1 5 4 1 8
1 6 5 1 10
2 1 2 0 0
3 1 3 0 0
4 1 4 0 0
5 1 5 0 0
*/

