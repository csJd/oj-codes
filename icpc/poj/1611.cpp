#include <cstdio>
#include <cstring>

using namespace std;
const int N = 30005;
int par[N], a[N];

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

int main()
{
    int n, m, k;
    while(scanf("%d%d", &n, &m), n || m)
    {
        memset(par, -1, sizeof(par));
        while(m--)
        {
            scanf("%d", &k);
            for(int i = 0; i < k; ++i)
            {
                scanf("%d", &a[i]);
                if(i) merge(a[i], a[i - 1]);
            }
        }
        printf("%d\n", -par[find(0)]);
    }
    return 0;
}
//Last modified :   2015-07-06 19:54

