#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
vector<int> g[N];
int par[N], dep[N], cnt[N], n;

void build()
{
	int u, v, m;
	memset(par, 0, sizeof(par));
	dep[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d:(%d)", &u, &m);
		g[u].clear();
		while(m--)
		{
			scanf("%d",&v);
			g[u].push_back(v);
			par[v] = u;
			dep[v] = dep[u] + 1;
		}
	}
}

int main()
{
	int q, u, v;
	while(~scanf("%d",&n))
	{
		build();
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &q);
		while(q--)
		{
			scanf(" (%d,%d)", &u, &v);
			while(dep[u] > dep[v]) u = par[u];
			while(dep[v] > dep[u]) v = par[v];
			while(u != v)
			{
				u = par[u];
				v = par[v];
			}
			++cnt[u];
		}

		for(int i = 1; i <= n; ++i)
		{
			if(cnt[i])
				printf("%d:%d\n", i, cnt[i]);
		}
	}

    return 0;
}
//Last modified :   2015-07-10 09:46

