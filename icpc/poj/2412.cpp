#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105, M = 10050;
int par[N], n, m, mat[N][N];
int ans;
struct edge{int u, v, w;} e[M];
bool cmp(edge a, edge b){return a.w < b.w;}

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

void Union (int u, int v)
{
    int ru = Find(u), rv = Find(v), tmp = par[ru] + par[rv];
    if(par[ru] < par[rv])
        par[rv] = ru, par[ru] = tmp;
    else
        par[ru] = rv, par[rv] = tmp;
}

void kruskal()
{
    memset(par, -1, sizeof(par));
    int cnt = 0;
    for(int i = 1; i <= m; ++i)
    {
        int u = e[i].u, v = e[i].v;
        if(Find(u) != Find(v))
        {
            ++cnt;
            ans += e[i].w;
            Union(u, v);
        }
        if(cnt >= n - 1) break;
    }
}

int main()
{
    int t, u, v;
    while(~scanf("%d", &n))
    {
        m = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                scanf("%d", &mat[i][j]);
                if(j < i) e[++m].u = i, e[m].v = j, e[m].w = mat[i][j];
            }
        }

        scanf("%d", &t);
        while(t--)
        {
            scanf("%d%d", &u, &v);
            e[++m].u = u, e[m].v = v, e[m].w = 0;
        }

        sort(e + 1, e + m + 1, cmp);
        ans = 0; kruskal();
        printf("%d\n", ans);
    }
    return 0;
}

