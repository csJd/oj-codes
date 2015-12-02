#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
vector<int> e[N];
typedef vector<int>::iterator it;
int w[N], vis[N], par[N];
ll v[N];

bool cmp(int i, int j)
{
    return v[i] > v[j];
}

void dfs(int p, int pa)
{
    if(vis[p]) return;
    v[p] = v[pa] + w[p];
    vis[p] = 1;
    par[p] = pa;
    for(it i = e[p].begin(); i != e[p].end(); ++i)
        dfs(*i, p);
}

int main()
{
    int cas, n, k, a, b, r[N];
    scanf("%d", &cas);
    w[0] = -1;
    for(int kas = 1; kas <= cas; ++kas)
    {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &w[i]);
            e[i].clear();
            r[i] = i;
        }

        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d", &a, &b);
            e[a].push_back(b), e[b].push_back(a);
        }

        memset(vis, 0, sizeof(vis));
        dfs(1, 0);
        for(int i = 1; i <= n; ++i) if(e[i].size() > 1) v[i] = 0;
        sort(r + 1, r + n + 1, cmp);
        for(int i = 1; i <= n; ++i)
        {
            int cur = r[i];
            v[r[i]] = 0;
            while(w[cur] >= 0)
            {
                v[r[i]] += w[cur];
                w[cur] = -1;
                cur = par[cur];
            }
        }
        sort(v + 1, v + n + 1);
        for(int i = n - 1; i > n - k; --i) v[n] += v[i];
        printf("Case #%d: %lld\n", kas, v[n]);
    }
    return 0;
}
//Last modified :   2015-06-04 07:59
