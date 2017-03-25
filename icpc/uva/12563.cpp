#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = 180;
int c[N], d[N * M], t, n;

int main()
{
    int cas, ans;
    scanf("%d", &cas);
    for(int k = 1; k <= cas; ++k)
    {
        memset(d, 0x8f, sizeof(d));
        scanf("%d%d", &n, &t);
        for(int i = 0; i < n; ++i) scanf("%d", &c[i]);
        for(int i = d[0] = 0; i < n; ++i)
            for(int j = t - 1; j >= c[i]; --j)
                d[j] = max(d[j], d[j - c[i]] + 1);
        for(int j = ans = t - 1; j >= 0; --j) if(d[j] > d[ans]) ans = j;
        printf("Case %d: %d %d\n", k, d[ans] + 1, ans + 678);
    }
    return 0;
}
