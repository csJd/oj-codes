#include<cstdio>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;
const int M = 550010;
unordered_map<string, int> p;
struct edge
{
    int u, v;
} e[M];
int par[M], deg[M], n, m, ok, cnt;

int Find(int x)
{
    int r = x, tmp;
    while(par[r] > 0) r = par[r];
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
    if(par[ru] < par[rv]) par[rv] = ru, par[ru] = tmp;
    else par[ru] = rv, par[rv] = tmp;
}

void Connect()
{
    memset(par, -1, sizeof(par));
    for(int i = 1; i <= m; ++i)
    {
        int u = e[i].u, v = e[i].v;
        if(Find(u) != Find(v)) Union(u, v);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(deg[i] % 2) ++cnt;
        if(cnt > 2)
        {
            ok = 0;
            break;
        }
        for(int j = 1; j <= n; ++j)
            if(Find(i) != Find(j)) ok = 0;
    }
    if(cnt == 1) ok = 0;
}

int main()
{
    ok = 1;
    char a[20], b[20];
    while(~scanf("%s %s", a, b))
    {
        if(p[a] == 0) p[a] = (++n);
        if(p[b] == 0) p[b] = (++n);
        int u = p[a], v = p[b];
        e[++m].u = u, e[m].v = v;
        ++deg[u], ++deg[v];
    }
    Connect();
    if(ok) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}
