#include <cstdio>
#include <cstring>
using namespace std;
const int N = 2005;
int n, m, par[N], dif[N];

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
    int T, a, b, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        memset(par, -1, sizeof(par));
        memset(dif, 0, sizeof(dif));
        scanf("%d%d", &n, &m);

        int flag = 1;
        while(m--)
        {
            scanf("%d%d", &a, &b);
            if(!flag) continue;
            if(find(a) == find(b))
            {
                flag = 0;
                continue;
            }

            if(dif[a]) merge(dif[a], b);
            if(dif[b]) merge(dif[b], a);
            dif[a] = b;
            dif[b] = a;
        }

        printf("Scenario #%d:\n%s", ++cas, flag ? "No s" : "S");
        puts("uspicious bugs found!\n");
    }
    return 0;
}
//Last modified :   2015-07-06 17:52
