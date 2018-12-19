#include <bits/stdc++.h>
#define l(x) d[x][j+1]
using namespace std;
const int N = 105;
int n, m, g[N][N], d[N][N], fol[N][N];
int main()
{
    int n, m, u, b, t, k;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                scanf("%d", &g[i][j]);

        memset(d, 0x3f, sizeof(d));
        for(int i = 0; i < n; ++i) d[i][m - 1] = g[i][m - 1];
        for(int j = m - 2; j >= 0; --j)
        {
            for(int i = 0; i < n; ++i)
            {
                u = (i + n - 1) % n, b = (i + 1) % n, t = i;
                if(l(u) < l(t) || (l(u) == l(t) && u < t)) t = u;
                if(l(b) < l(t) || (l(b) == l(t) && b < t)) t = b;
                d[i][j] = g[i][j] + d[t][j + 1], fol[i][j] = t;
            }
        }

        for(int i = k = 0; i < n; ++i)
            if(d[i][0] < d[k][0] || (d[i][0] == d[k][0] && i < k)) k = i;
        int ans = d[k][0];
        for(int j = 0; j < m - 1; ++j) printf("%d ", k + 1), k = fol[k][j];
        printf("%d\n%d\n", k + 1, ans);
    }
    return 0;
}
