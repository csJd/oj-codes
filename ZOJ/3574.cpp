#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 30005;
struct line
{
    int a, b;
} li[N];

bool cmp(line i, line j)
{
    return i.a < j.a;
}

bool cmpc(int i, int j)
{
    return li[i].b < li[j].b;
}

int bit[N], r[N], n;

void add(int x, int v)
{
    while(x <= n)
    {
        bit[x] += v;
        x += x & -x;
    }
}

int sum(int x)
{
    int ret = 0;
    while(x)
    {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

int main()
{
    int xa, xb, k, b;
    while(~scanf("%d%d", &xa, &xb))
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            r[i] = i;
            scanf("%d%d", &k, &b);
            li[i].a = k * xa + b;
            li[i].b = k * xb + b;
        }

        sort(li + 1, li + n + 1, cmp);
        sort(r + 1,  r + n + 1, cmpc);

        int ans = n + 1;
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; ++i)
        {
            ans += sum(n) - sum(r[i]);
            add(r[i], 1);
        }

        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :   2015-07-30 20:44

