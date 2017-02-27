#include <bits/stdc++.h>
using namespace std;
const int N = 20005;
int deg[N], n, m;

int main()
{
    int T, u, v, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        vector<int> y;
        scanf("%d%d", &n, &m);
        memset(deg, 0, sizeof(deg));
        for(int i = 0; i < m; ++i)
        {
            if(i == n - 1)
            {
                for(int j = 1; j <= n; ++j)
                    if(deg[j] == 1) y.push_back(j);
            }
            scanf("%d%d", &u, &v);
            ++deg[u];
            ++deg[v];
        }
        int ans = deg[y[0]];
        for(int i = 0; i < y.size(); ++i)
            if(deg[y[i]] < ans) ans = deg[y[i]];
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
//Last modified :  2015-09-19 15:04 CST

