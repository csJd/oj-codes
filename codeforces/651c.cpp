#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int par[N];

struct Poi
{
    int x, y, no;
} p[N];

bool cmpx(Poi &a, Poi &b)
{
    return a.x < b.x;
}

bool cmpy(Poi &a, Poi &b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

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
    int ru = find(u), rv = find(v), tmp = par[ru] + par[rv];
    if(ru == rv) return;
    if(par[ru] < par[rv]) par[rv] = ru, par[ru] = tmp;
    else par[ru] = rv, par[rv] = tmp;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            p[i].no = i;
        }

        memset(par, -1, sizeof(par));
        sort(p, p + n, cmpx);
        for(int i = 1; i < n; ++i)
        {
            if(p[i].x == p[i - 1].x)
                merge(p[i].no, p[i - 1].no);
        }

        long long ans = 0, t;

        for(int i = 0; i < n; ++i)
        {
            t = -par[i];
            if(t > 0) ans += t * (t - 1) / 2;
        }

        memset(par, -1, sizeof(par));
        sort(p, p + n, cmpy);
        for(int i = 1; i < n; ++i)
        {
            if(p[i].y == p[i - 1].y)
                merge(p[i].no, p[i - 1].no);
        }
        for(int i = 0; i < n; ++i)
        {
            t = -par[i];
            if(t > 0) ans += t * (t - 1) / 2;
        }

        memset(par, -1, sizeof(par));
        for(int i = 1; i < n; ++i)
        {
            if(p[i].y == p[i - 1].y && p[i].x == p[i-1].x)
                merge(p[i].no, p[i - 1].no);
        }
        for(int i = 0; i < n; ++i)
        {
            t = -par[i];
            if(t > 0) ans -= t * (t - 1) / 2;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
