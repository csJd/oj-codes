#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int v[N], deg[N], par[N], q[N];
bool g[N][N];
vector<int> e[N];

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
    int ru = find(u), rv = find(v);
    if(ru == rv) return;
    if(par[ru] < par[rv])
        par[ru] += par[rv], par[rv] = ru;
    else par[rv] += par[ru], par[ru] = rv;
}

int main()
{
    int T, a, b, n, m;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &v[i]);
            deg[i] = 0;
            e[i].clear();
        }

        memset(g, 0, sizeof(g));
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d", &a, &b);
            g[a][b] = g[b][a] = 1;
            e[a].push_back(b);
            e[b].push_back(a);
            ++deg[a];
            ++deg[b];
        }

        int front = 0, rear = 0;
        for(int i = 1; i <= n; ++i)
            if(deg[i] == 1) q[rear++] = i;
        while(front < rear)
        {
            int i = q[front++];
            if(deg[i] != 1) continue;
            for(int j = 0; j < e[i].size(); ++j)
            {
                int k = e[i][j];
                if(g[i][k])
                {
                    --deg[i];
                    --deg[k];
                    g[i][k] = g[k][i] = 0;
                    if(deg[k] == 1) q[rear++] = k;
                }
            }
        }

        memset(par, -1, sizeof(par));
        for(int i = 1; i <= n; ++i)
        {
            if(!deg[i]) continue;
            for(int j = 0; j < e[i].size(); ++j)
            {
                int k = e[i][j];
                if(g[i][k]) merge(i, k);
            }
        }

        long long ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(!deg[i]) continue;
            int r = find(i);
            if((-par[r]) % 2) ans += v[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
//Last modified :  2015-09-13 09:31 CST

