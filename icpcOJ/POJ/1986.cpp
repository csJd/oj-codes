#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 10005;
int id[N], dep[N], dis[N];

struct node
{
	int to, val;
	node(int t, int v):to(t), val(v){}
	node();
}
vector<node> g[N];

void dfs(int i, int p, int d, int &k)
{
	id[i] = k;
	vs[k] = i;
	dep[k++] = d;
	for(int j = 0; j < g[i].size(); ++j)
	{
		if(g[i][j].to == p) continue;
		dfs(g[i][j].to, i, d + 1, k);
		vs[k] = v;
		dep[k++] = d;
	}
}

int main()
{
	int n, m, q, a, b, v;
	char s[];
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%s", &a, &b, &v, s);
			g[a].push_back(node(b, v));
			g[b].push_back(node(a, v));
		}

		int k = 1;
		dfs(1, 0, k);
	}
    return 0;
}
//Last modified :  2015-10-07 15:51 CST
