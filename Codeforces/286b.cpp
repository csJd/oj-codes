#include<cstdio>
#include<cstring>
using namespace std;
const int N = 105;
int d[N][N][N], ans;

int main()
{
    int a, b, c, n, m, q;
    while(~scanf("%d%d", &n, &m))
    {
        memset(d, 0, sizeof(d));
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            d[c][a][b] = d[c][b][a] = 1;
        }

        for(c = 1; c <= m; ++c)
        for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(!d[c][i][j]) d[c][i][j] = d[c][j][i] = (d[c][i][k] && d[c][k][j]);

        scanf("%d", &q);
        while(q--)
        {
            ans = 0;
            scanf("%d%d", &a, &b);
            for(int c = 1; c <= m; ++c)
                if(d[c][a][b]) ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}
