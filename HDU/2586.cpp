#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 400005;
int id[N], dis[N], vs[N];
int minp[N][32], k;

struct node
{
    int to, len;
    node(int t, int l): to(t), len(l) {}
    node();
};
vector<node> g[N];

void dfs(int i, int p, int d)
{
    id[i] = k;
    vs[k] = i;
    dis[k++] = d;
    for(int j = 0; j < g[i].size(); ++j)
    {
        if(g[i][j].to == p) continue;
        dfs(g[i][j].to, i, d + g[i][j].len);
        vs[k] = i;
        dis[k++] = d;
    }
}

void initST()
{
    for(int i = 0; i < k; ++i) minp[i][0] = i;
    for(int j = 1; 1 << j <= k; ++j)
    {
        for(int i = 0; i + (1 << j) <= k; ++i)
        {
            int l = minp[i][j - 1], r = minp[i + (1 << j - 1)][j - 1];
            minp[i][j] = dis[l] < dis[r] ? l : r;
        }
    }
}

int queryST(int l, int r)
{
    if(l > r) swap(l, r);
    int j = log2(r - l + 1);
    int a = minp[l][j], b = minp[r + 1 - (1 << j)][j];
    return dis[a] < dis[b] ? a : b;
}

int main()
{
    int T, n, q, a, b, v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 0; i < n - 1; ++i)
        {
            scanf("%d%d%d", &a, &b, &v);
            g[a].push_back(node(b, v));
            g[b].push_back(node(a, v));
        }

        dfs(1, -1, k = 0);
        initST();

//        for(int i = 0; i < k; ++i)
//            printf("%d ", vs[i]);
//        printf("");

        while(q--)
        {
            scanf("%d%d", &a, &b);
            int lca = queryST(id[a], id[b]);
            //printf("%d\n", vs[lca]);
            printf("%d\n", dis[id[a]] + dis[id[b]] - 2 * dis[lca]);
        }

    }
    return 0;
}
//Last modified :  2015-10-08 21:15 CST
/*
1
5 3
1 2 100
1 3 200
2 4 300
2 5 100
4 5
3 4
2 3

结果
400
600
300
*/

