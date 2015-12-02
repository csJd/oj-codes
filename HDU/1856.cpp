#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e7 + 5;
int par[N];
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
    int n, a, b, t, ans;
    while(~scanf("%d", &n))
    {
        ans = 1;
        memset(par, -1, sizeof(par));
        while(n--)
        {
            scanf("%d%d", &a, &b);
            merge(a, b);
            if((t = -par[find(a)]) > ans) ans = t;
        }
        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :   2015-07-06 19:54
