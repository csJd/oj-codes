#include<cstdio>
#include<cstring>
using namespace std;
const int N = 105;
int cost[N], mat[N][N], n, m, ans;

void prim()
{
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = -1;
    int cur = 1, next = 0;
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(cost[j] == -1) continue;
            if(cost[j] > mat[cur][j]) cost[j] = mat[cur][j];
            if(cost[j] < cost[next]) next = j;
        }
        ans += cost[next], cost[cur = next] = -1, next = 0;
    }
}

int main()
{
    int a, b, c;
    while(scanf("%d%d", &m, &n), m)
    {
        memset(mat, 0x3f, sizeof(mat));
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(c < mat[a][b]) mat[a][b] = mat[b][a] = c;
        }
        ans = 0;
        prim();
        if(ans >= cost[0]) printf("?\n");
        else printf("%d\n", ans);
    }
    return 0;
}
