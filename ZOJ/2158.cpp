#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2005;
char s[N][10];
struct edge
{
    int u, v, w;
} e[N*N];
int n, m, t, ans, par[N];
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int Find(int x)
{
    int r = x, tmp;
    while(par[r] >= 0) r = par[r];
    while(x != r) tmp = par[x], par[x] = r, x = tmp;
    return r;
}

void Union(int u, int v)
{
    int ru = Find(u), rv = Find(v), tmp = par[ru] + par[rv];
    if(par[ru] < par[rv]) par[rv] = ru, par[ru] = tmp;
    else par[ru] = rv, par[rv] = tmp;
}

void kruskal()
{
    memset(par, -1, sizeof(par));
    int cnt = 0;
    for(int i = 1; i <= m; ++i)
    {
        if(Find(e[i].u != Find(e[i].v)))
        {
            ++cnt;
            ans += e[i].w;
            Union(e[i].u, e[i].v);
        }
        if(cnt >= n - 1) break;
    }
}

int main()
{
    while(scanf("%d", &n), n)
    {
        m = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%s", s[i]);
            for(int j = 1; j < i; ++j)
            {
                for(int k = t = 0; k < 7; ++k)
                    if(s[i][k] != s[j][k]) ++t;
                e[++m].u = i, e[m].v = j, e[m].w = t;
            }
        }
        ans = 0;
        sort(e + 1, e + m + 1, cmp);
        kruskal();
        printf("The highest possible quality is 1/%d.\n", ans);
    }
}

