#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 505;
int vis[N], dp[10086];

struct enemy
{
    ll x, y;
    int t, w;
} e[N];


bool cmp(enemy a, enemy b)  //按与原点的距离排序
{
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

bool aLine(int i, int j) //判断是否在同一条射线上·
{
    if(e[i].x * e[j].y == e[i].y * e[j].x)
        return e[i].x * e[j].x >= 0 &&  e[i].y * e[j].y >= 0;
    return 0;
}

int main()
{
    ll x, y, x0, y0;
    int n, t0;
    while(~scanf("%lld%lld%d%d", &x0, &y0, &n, &t0))
    {
        for(int i = 0; i < n; ++i)
        {
            scanf("%lld%lld%d%d", &x, &y, &e[i].t, &e[i].w);
            e[i].x = x - x0;
            e[i].y = y - y0;
        }
        sort(e, e + n, cmp);  //按与原点的距离排序

        vector<enemy> em[N];  //把在一条射线上的放到一个分组里
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; ++i)
        {
            if(vis[i]) continue;  //i已经在别的组里了
            em[i].push_back(e[i]);
            for(int j = i + 1; j < n; ++j)
            {
                if(!aLine(i, j)) continue;
                int k = em[i].size() - 1;
                vis[j] = 1;
                if(e[j].t == 0)  //把耗时为0的敌人放到上一个里
                {
                    em[i][k].w += e[j].w;
                    continue;
                }

                em[i].push_back(e[j]);
                em[i][k + 1].w += em[i][k].w;
                em[i][k + 1].t += em[i][k].t;
            }
        }

        memset(dp, 0, sizeof(dp)); //分组背包
        for(int i = 0; i < n; ++i)
        {
            int k = em[i].size();
            for(int v = t0; v >= 0; --v)
                for(int j = 0; j < k && em[i][j].t <= v; ++j)
                    dp[v] = max(dp[v], dp[v - em[i][j].t] + em[i][j].w);
        }
        printf("%d\n", dp[t0]);
    }

    return 0;
}
//Last modified :   2015-07-28 18:43
/*
0 0 5 10
0 5 2 3
0 10 2 8
3 2 4 6
6 7 3 9
4 4 10 2

0 0 5 0
0 5 0 1
0 10 0 1
3 2 0 1
6 7 0 1
4 4 0 1
*/
