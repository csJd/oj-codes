#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int par[N], p[N], vis[N];

int find(int x)
{
    int r = x, tmp;
    while(par[r] >= 0) r = par[r];
    while(x != r)
    {
        tmp = par[x];
        par[x] = r;
        x = tmp;
    }
    return r;
}

void merge(int u, int v)
{
    int ru = find(u), rv = find(v), tmp = par[ru] + par[rv];
    if(par[ru] < par[rv])
        par[rv] = ru, par[ru] = tmp;
    else par[ru] = rv, par[rv] = tmp;
}

int main()
{
    int a, b, n, m;
    while(scanf("%d%d", &a, &b), a + 1)
    {
        if(a == 0 && b == 0)
        {
            printf("Yes\n");
            continue;
        }

        m = 1, n = 0;
        memset(par, -1, sizeof(par));
        memset(vis, 0, sizeof(vis));
        bool flag = 1;

        if(!vis[a]) vis[a] = ++n;
        if(!vis[b]) vis[b] = ++n;
        if(find(a) != find(b)) merge(a, b);
        else flag = 0;

        while(scanf("%d%d", &a, &b), a || b)
        {
            ++m;
            if(!vis[a]) vis[a] = ++n;
            if(!vis[b]) vis[b] = ++n;
            if(!flag) continue;
            if(find(a) != find(b)) merge(a, b);
            else flag = 0;
        }

        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(par[p[i]] < 0) ++cnt;
        flag = flag && n == m + 1;
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
//Last modified :   2015-07-06 16:14

