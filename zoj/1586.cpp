#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
int cost[N], mat[N][N], a[N], n, ans;

void prim()
{
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = -1;
    //cost[i]为把第i个节点加入到最小生成树的最小花费,-1代表已经加入
    int cur = 1, next = 0;
    //cur为当前加入到最小生成树中的节点
    //next为下一个应该加入最小生成树的节点
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(cost[j] == -1 || j == cur) continue;
            cost[j] = min(cost[j], mat[cur][j]);
            if(cost[j] < cost[next]) next = j;
        }
        ans += cost[next];
        cur = next, cost[cur] = -1, next = 0;
    }
}

int main()
{
    int cas, t;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i)
        {
           for(int j = 1; j <= n; ++j)
            {
                scanf("%d", &t);
                mat[i][j] = a[i] + a[j] + t;
            }
        }
        ans = 0;  prim();
        printf("%d\n", ans);
    }
    return 0;
}
