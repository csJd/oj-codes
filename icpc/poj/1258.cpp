#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105, M = 10050;
int par[N], ans, n, m, t;
struct edge { int u, v, w;} e[M];
bool cmp(edge a, edge b){ return a.w < b.w;}

int Find(int x)
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

void Union(int u, int v)
{
    int ru = Find(u), rv = Find(v), tmp = par[ru] + par[rv];
    if(par[ru] < par[rv])
        par[rv] = ru, par[ru] = tmp;
    else
        par[ru] = rv, par[rv] = tmp;
}

void kruskal()
{
    int cur = 0, u, v;
    memset(par, -1, sizeof(par));
    for(int i = 1; i <= m; ++i)
    {
        u = e[i].u, v = e[i].v;
        if(Find(u) != Find(v))
        {
            ans += e[i].w;
            Union(u, v);
            ++cur;
        }
        if(cur >= n - 1) break;
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        ans = m = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                scanf("%d", &t);
                if(j < i) e[++m].u = i, e[m].v = j, e[m].w = t;
            }
        }
        sort(e + 1, e + m + 1, cmp);
        kruskal();
        printf("%d\n", ans);
    }
    return 0;
}
