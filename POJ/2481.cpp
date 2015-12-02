#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100005;
struct cow
{
    int s, e, id;
} c[N];

bool cmp(cow &i, cow &j)
{
    if(i.s == j.s) return i.e > j.e;
    return i.s < j.s;
}

int n, bit[N], ans[N];

void add(int x, int v)
{
    while(x < N)
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
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d%d", &c[i].s, &c[i].e), c[i].id = i;
        sort(c, c + n, cmp);

        memset(bit, 0, sizeof(bit));
        for(int i = 0; i < n; ++i)
        {
            int j = c[i].id;
            if(i && c[i].s == c[i - 1].s && c[i].e == c[i - 1].e)
            {
                ans[j] = ans[c[i - 1].id];
                add(c[i].e + 1, 1);
                continue;
            }
            ans[j] = sum(N - 1) - sum(c[i].e);
            add(c[i].e + 1, 1);
        }

        for(int i  = 0; i < n; ++i)
            printf("%d%c", ans[i], i < n - 1 ? ' ' : '\n');

    }

    return 0;
}
//Last modified :   2015-07-31 14:41

