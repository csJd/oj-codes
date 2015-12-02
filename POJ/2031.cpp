#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105, M = 10050;
int par[N], n, m;
double ans;
struct edge{int u, v; double w;} e[M];
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
    double x[N], y[N], z[N], r[N], dis;
    while(scanf("%d", &n), n)
    {
        m = 0;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf%lf%lf", &x[i], &y[i], &z[i], &r[i]);
            for(int j = 1; j < i; ++j)
            {
                double tx = x[i] - x[j], ty = y[i] - y[j], tz = z[i] - z[j];
                double dis = sqrt(tx * tx + ty * ty + tz * tz) - r[i] - r[j];
                e[++m].u = i, e[m].v = j, e[m].w = max(0.0, dis);
            }
        }
        sort(e + 1, e + m + 1, cmp);
        ans = 0;
        kruskal();
        printf("%.3f\n", ans);
    }
    return 0;
}

