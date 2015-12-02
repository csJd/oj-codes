#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int x[N], y[N], vis[N];
int dir[N], p[N], n, m;

void dfs(int i)
{
    vis[i] = 1;
    for(int j = 0; j < n; ++j)
    {
        if(!vis[j] && (x[j] == x[i] || y[j] == y[i]))
        {
            dfs(j);    //j和i属于一个连通块且j还没被访问 对j深搜
            if(x[j] == x[i])  //记录路径 上下左右分别用0，1，2，3表示
                dir[j] = y[j] < y[i] ? 0 : 1;
            else dir[j] = x[j] < x[i] ? 3 : 2;
            p[m++] = j;
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &x[i], &y[i]);

        memset(vis, 0, sizeof(vis));
        int cnt = m = 0;
        for(int i = 0; i < n; ++i)
            if(!vis[i]) ++cnt, dfs(i);

        printf("%d\n", cnt);
        char sdir[][10] = {"UP", "DOWN", "LEFT", "RIGHT"};
        for(int i = 0; i < m; ++i)
        {
            int j = p[i];
            printf("(%d, %d) %s\n", x[j], y[j], sdir[dir[j]]);
        }
    }

    return 0;
}
//Last modified :   2015-07-10 08:26

