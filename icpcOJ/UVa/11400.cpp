#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct lamp
{
    int v, k, c, l;
    bool operator < (lamp a)    {
        return v < a.v;
    }
} ls[N];
int s[N], d[N], n;

int main()
{
    while(~scanf("%d", &n), n)
    {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", &ls[i].v, &ls[i].k, &ls[i].c, &ls[i].l);
        sort(ls + 1, ls + n + 1);
        memset(d, 0x3f, sizeof(d)), d[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            s[i] = s[i - 1] + ls[i].l;
            d[i] = s[i] * ls[i].c + ls[i].k;
            for(int j = 1; j < i; ++j)
                d[i] = min(d[i], d[j] + (s[i] - s[j]) * ls[i].c + ls[i].k);
        }
        printf("%d\n", d[n]);
    }
    return 0;
}
