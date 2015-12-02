#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 105, M = 10050;
double x[N], y[N], ans;
int n, m , par[N];

struct edge {
    int u, v;
    double w;
} e[M];

bool cmp(edge a, edge b)  { return a.w < b.w;}

int Find(int x)
{
    int r = x;
    while(par[r] >= 0) r = par[r];
    while(x != r) //压缩
    {
        int tmp = par[x];
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
    int cur = 0, u, v;
    memset(par, -1, sizeof(par)); //初始化并查集
    for(int i = 1; i <= m; ++i)
    {
        u = e[i].u, v = e[i].v;
        if(Find(u) != Find(v))
        {
            ans += e[i].w;
            ++cur;
            Union(u, v);
        }
        if(cur >= n - 1) break;
    }
}

int main()
{
    int cas = 0;
    while(scanf("%d", &n), n)
    {
        if(cas) printf("\n");
        m = 0;

        for(int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf", &x[i], &y[i]);
            for(int j = 1; j < i; ++j)
            {
                double dis = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                e[++m].u = i, e[m].v = j, e[m].w = dis;
            }
        }

        sort(e + 1, e + 1 + m, cmp);
        ans = 0; kruskal();
        printf("Case #%d:\nThe minimal distance is: %.2f\n", ++cas, ans);
    }

    return 0;
}
