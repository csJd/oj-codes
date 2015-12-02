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
    //cost[i]Ϊ�ѵ�i���ڵ���뵽��С����������С����,-1�����Ѿ�����
    int cur = 1, next = 0;
    //curΪ��ǰ���뵽��С�������еĽڵ�
    //nextΪ��һ��Ӧ�ü�����С�������Ľڵ�
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
