#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int g[N][N], a[N], b[N], vis[N];
int n, m, k, ans;

int dfs(int i)   //DFS����
{
    for(int j = 1; j < m; ++j)
    {
        if(g[i][j] && !vis[j])
        {
            vis[j] = 1;
            if( b[j] == -1 || dfs(b[j]))
            {
                //����a��ģʽi�����b��ģʽjƥ��
                a[i] = j;
                b[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int u, v, t;
    while(scanf("%d", &n), n)
    {
        memset(g, 0, sizeof(g));
        scanf("%d%d", &m, &k);
        for(int i = 0; i < k; ++i)
        {
            scanf("%d%d%d", &t, &u, &v);
            g[u][v] = 1;
        }

        ans = 0;
        memset(a, -1, sizeof(a));
        memset(b, -1, sizeof(b));
        //״̬0����Ҫ����  ���Կ��Ժ���0
        for(int i = 1; i < n; ++i)
        {
            if(a[i] == -1)  //iû��ƥ�� ��iΪ�����һ������·
            {
                memset(vis, 0, sizeof(vis));
                ans += dfs(i);  //
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
//Last modified :   2015-07-10 14:50

