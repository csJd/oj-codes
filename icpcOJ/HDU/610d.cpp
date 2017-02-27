#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 10005;
int n, m, par[N], dif[N];
bool vis[N], viss[N];
struct edge
{
    int u, v;
} e[N * 10], use[N * 10];

int find(int x)
{
    int r = x, t;
    while(par[r] >= 0) r = par[r];
    while(x != r)
    {
        t = par[x];
        par[x] = r;
        x = t;
    }
    return r;
}

void merge(int u, int v)
{
    int ru = find(u), rv = find(v), t = par[ru] + par[rv];
    if(ru == rv) return;
    if(par[ru] < par[rv])
        par[rv] = ru, par[ru] = t;
    else par[ru] = rv, par[rv] = t;
}

bool cmp(edge i, edge j)
{
    int ui = -par[find(i.u)];
    int vi = -par[find(i.v)];
    int uj = -par[find(j.u)];
    int vj = -par[find(j.v)];
    return(abs(ui - vi) > abs(uj - vj));
}



int main()
{
    int T, a, b, k;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        if(!m) printf("%d\n", n / 2 * (n - n / 2));
        else
        {
            memset(par, -1, sizeof(par));
            memset(dif, 0, sizeof(dif));
            memset(vis, 0, sizeof(vis));
            for(int i = k = 0; i < m; ++i)
            {
                scanf("%d%d", &a, &b);
                e[i].u = a, e[i].v = b;

                if(!vis[a]) vis[a] = 1, ++k;
                if(!vis[b]) vis[b] = 1, ++k;

                if(dif[a]) merge(dif[a], b);
                if(dif[b]) merge(dif[b], a);
                dif[a] = b;
                dif[b] = a;
            }

            int cnt = 0, cu, cv;
            memset(vis, 0, sizeof(vis));
            for(int i = 0; i < m; ++i)
            {
                a = find(e[i].u), b = find(e[i].v);
                if(!vis[a])
                {
                    vis[a] = vis[b] = 1;
                    use[cnt++] = e[i];
                }
            }

            a = b = 0;
            sort(use, use + cnt, cmp);
            for(int i = 0; i < cnt; ++i)
            {
                cu = -par[find(use[i].u)];
                cv = -par[find(use[i].v)];
                if(cu < cv) swap(cu, cv);
                if(i % 2) a += cu, b += cv;
                else a += cv, b += cu;
            }

            while(a + b < n)
            {
                if(a < b) ++a;
                else ++b;
            }

            printf("%d\n", a * b - m);

        }

    }
    return 0;
}

