#include <bits/stdc++.h>
using namespace std;
const int  N = 105;
int g[N], ans[N];

int main()
{
    int n, m, res;
    while(~scanf("%d%d", &n, &m))
    {
        memset(ans, 0, sizeof(ans));
        res = 1;
        for(int i = 1; i <= n; ++i)
        {
            int chs = 1;
            for(int j = 1; j <= m; ++j)
            {
                scanf("%d", &g[j]);
                if(g[j] > g[chs]) chs = j;
            }
            ++ans[chs];
            if(ans[chs] > ans[res]) res = chs;
        }
        printf("%d\n", res);
    }

    return 0;
}
//Last modified :  2015-08-14 00:28 CST

