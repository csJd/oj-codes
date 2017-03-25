#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100,INF=0x3f3f3f;
int cost[N][N], tax[N], nex[N][N];
int s, t, n;

void floyd()
{
    int tmp;
    for(int k = 1; k <= n; ++k)
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
    {
        tmp = cost[i][k] + cost[k][j] + tax[k];
        if(cost[i][j] > tmp || (cost[i][j] == tmp && nex[i][j] > nex[i][k]))
        {
            nex[i][j] = nex[i][k];
            cost[i][j] = tmp;
        }
    }
}

int main()
{
    while(scanf("%d", &n), n)
    {
        memset(nex,0,sizeof(nex));
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                scanf("%d", &cost[i][j]);
                if(cost[i][j] < 0) cost[i][j]=INF;
                else nex[i][j]=j;
            }
        }

        for(int i = 1; i <= n; ++i)  scanf("%d", &tax[i]);
        floyd();
        while(scanf("%d%d", &s, &t), s > 0)
        {
            int k=s;
            printf("From %d to %d :\nPath: %d", s, t, s);
            while(k!=t) printf("-->%d", k=nex[k][t]);
            printf("\nTotal cost : %d\n\n", cost[s][t]);
        }
    }
    return 0;
}
/*
3
-1  2  3
2  -1  1
3  1  -1
0  0  0
1 3
3 1
*/

//void dijkstra()
//{
//    memset(v, 0, sizeof(v));
//    memset(d, 0x3f, sizeof(d));
//    memset(pre,0,sizeof(pre));
//    d[s] = (s==t?0:-tax[s]);
//    for(int i = 1; i <= n; ++i)
//    {
//        int cur = 0;
//        for(int j = 1; j <= n; ++j)
//            if(!v[j] && d[j] < d[cur]) cur = j;
//        v[cur] = 1;
//        if(cur == t) return;
//        for(int j = 1; j <= n; ++j)
//        {
//            if(cost[cur][j]==-1) cost[cur][j]=d[0];
//            int tmp=d[cur] + cost[cur][j] + tax[cur];
//            if(d[j] > tmp||(d[j]==tmp&&cur<pre[j]))
//            {
//                d[j] = tmp; pre[j] = cur;
//            }
//        }
//    }
//}
