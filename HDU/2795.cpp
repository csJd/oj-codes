#include <bits/stdc++.h>
#define lc p<<1, s, mid
#define rc p<<1|1, mid+1, e
#define mid ((s+e)>>1)
using namespace std;
const int N = 2e5 + 5;
int h, w, n, pos;
int maxv[N * 4];

void pushup(int p)
{
    maxv[p] = max(maxv[p << 1], maxv[p << 1 | 1]);
}

void build()
{
    for(int i = 1; i < h * 4; ++i)
        maxv[i] = w;
}

void update(int p, int s, int  e, int x)
{
    if(maxv[p] < x) return;
    if(s == e)
    {
        pos = s;
        maxv[p] -= x;
        return;
    }
    if(maxv[p << 1] >= x) update(lc, x);
    else update(rc, x);
    pushup(p);
}

int main()
{
    int x;
    while(~scanf("%d%d%d", &h, &w, &n))
    {
        h = min(h, n);
        build();
        while(n--)
        {
            scanf("%d", &x);
            pos = -1;
            update(1, 1, h, x);
            printf("%d\n", pos);
        }
    }
    return 0;
}
//Last modified :   2015-07-15 16:10

