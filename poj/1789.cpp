#include<cstdio>
#include<cstring>
using namespace std;
const int N = 2005;
int cost[N], dis[N][N], n, ans;

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
            if(dis[cur][j] < cost[j]) cost[j] = dis[cur][j];
            if(cost[j] < cost[next]) next = j;
        }
        cur = next, next = 0, ans += cost[cur], cost[cur] = -1;
    }
}

int main()
{
    char s[N][10];
    while(scanf("%d", &n), n)
    {
        memset(dis, 0, sizeof(dis));
        for(int i = 1; i <= n; ++i)
            scanf("%s", s[i]);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                for(int k = 0; k < 7; ++k)
                    if(s[i][k] != s[j][k]) ++dis[i][j];
        ans = 0;
        prim();
        printf("The highest possible quality is 1/%d.\n", ans);
    }
}
