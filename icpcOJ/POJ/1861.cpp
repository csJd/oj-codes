#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005, M = 15005;
struct edge{int u, v, w;} e[M];
int par[N], ea[N], n, m, num, ans;
bool cmp(edge a, edge b){ return a.w < b.w; }

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
    if(par[ru] > par[rv])
        par[ru] = rv, par[rv] = tmp;
    else
        par[rv] = ru, par[ru] = tmp;
}

void kruskal()
{
    memset(par, -1, sizeof(par));
    for(int i = 1; i <= m; ++i)
    {
        int u = e[i].u, v = e[i].v;
        if(Find(u) != Find(v))
        {
            ea[++num] = i;
            ans = max(ans, e[i].w);
            Union(u, v);
        }
        if(num >= n - 1) break;
    }
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            e[i].u = u, e[i].v = v, e[i].w = w;
        }

        sort(e + 1, e + m + 1, cmp);
        ans = num = 0;
        kruskal();
        printf("%d\n%d\n", ans, num);
        for(int i = 1; i <= num; ++i)
        {
            int j = ea[i];
            printf("%d %d\n", e[j].u, e[j].v);
        }
    }
    return 0;
}
