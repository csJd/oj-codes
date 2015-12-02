#include <bits/stdc++.h>
using namespace std;
const int N = 805;
int g[N][N], vis[N];
struct pir
{
    int r, c, v;
    bool operator< (const pir &p) const
    {
        return v < p.v;
    }
} tmp;
priority_queue<pir> pq;

int main()
{
    int n, m, v;
    while(~scanf("%d", &n))
    {
        m = 2 * n;
        memset(vis, 0, sizeof(vis));
        for(int i = 2; i <= m; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                scanf("%d", &tmp.v);
                tmp.r = j, tmp.c = i;
                pq.push(tmp);
            }
        }

        while(!pq.empty())
        {
            tmp = pq.top();
            vis[tmp.r] = tmp.c;
            vis[tmp.c] = tmp.r;
            while(!pq.empty() && (vis[tmp.r] || vis[tmp.c]))
            {
                pq.pop();
                tmp = pq.top();
            }
        }

        for(int i = 1; i <= m; ++i)
            printf("%d%c", vis[i], i < m ? ' ' : '\n');
    }
    return 0;
}
//Last modified :  2015-09-16 23:43 CST

