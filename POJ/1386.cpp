#include<cstdio>
#include<cstring>
using namespace std;
const int N = 30, M = 100010;
struct edge{int u, v; } e[M];
int vis[N], in[N], out[N], par[N], m, ok;

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
    if(par[ru] < par[rv]) par[rv] = ru, par[ru] = tmp;
    else par[ru] = rv, par[rv] = tmp;
}

void connect()
{
    memset(par, -1, sizeof(par)); //初始化并查集
    for(int i = 0; i < m; ++i)
    {
        int u = e[i].u, v = e[i].v;
        if(Find(u) != Find(v)) Union(u, v);
    }
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j)
            if(vis[i] && vis[j] && Find(i) != Find(j)) ok = 0;
}

int main()
{
    char s[1005];
    int u, v, cas;
    scanf("%d", &cas);
    while(cas--)
    {
        for(int i = 0; i < 26; ++i)
            vis[i] = in[i] = out[i] = 0;
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
        {
            scanf("%s", s);
            u = s[0] - 'a', v = s[strlen(s) - 1] - 'a';
            vis[u] = vis[v] = 1;
            e[i].u = u, e[i].v = v;
            ++in[u], ++out[v];
        }

        int id = 0, od = 0;//i[d]记录入度比出度大1的点的个数 o[d]小1
        ok = 1;
        for(int i = 0; i < 26; ++i)
        {
            if(!vis[i]) continue;
            int k = in[i] - out[i];
            if(k < -1 || k > 1) {ok = 0; break;}
            if(k == 1) ++id;
            if(k == -1) ++od;
        }
        if(id > 1 || od > 1 || id - od) ok = 0;
        connect();
        if(ok)  printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
