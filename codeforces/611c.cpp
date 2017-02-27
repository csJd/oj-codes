#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int ri[N][N], dw[N][N];
char g[N][N];

int main()
{
    int h, w, q, r1, c1, r2, c2;
    while(~scanf("%d%d", &h, &w))
    {
        for(int i = 0; i < h; ++i) scanf("%s", g[i]);

        for(int i = 0; i < h; ++i)
        {
            ri[i][w - 1] = 0;
            for(int j = w - 2; j >= 0; --j)
            {
                if(g[i][j] == '.' && g[i][j + 1] == '.')
                    ri[i][j] = ri[i][j + 1] + 1;
                else ri[i][j] = ri[i][j + 1];
            }
        }

        for(int j = 0; j < w; ++j)
        {
            dw[h - 1][j] = 0;
            for(int i = h - 2; i >= 0; --i)
            {
                if(g[i][j] == '.' && g[i + 1][j] == '.')
                    dw[i][j] = dw[i + 1][j] + 1;
                else dw[i][j] = dw[i + 1][j];
            }
        }

        scanf("%d", &q);
        while(q--)
        {
            int ans = 0;
            scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
            for(int i = r1 - 1; i < r2; ++i)
                ans += ri[i][c1-1] - ri[i][c2-1];

            for(int j = c1 - 1; j < c2; ++j)
                ans += dw[r1-1][j] - dw[r2-1][j];
            printf("%d\n", ans);
        }
    }
    return 0;
}
//Last modified :  2015-12-31 00:01 CST

