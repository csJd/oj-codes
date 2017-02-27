#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> g[N];

struct Gw;
{
	int def, add;
	bool operator< (const gw &g) const
	{
		return def < g.def;
	}
}gw;

priority_queue<gw, vecter<gw>, greater<gw> > gws[N];

int atk,;

int main()
{
	int T, n, m, u, v;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d", &u, &v);
			g[u].pushback(v);
			g[v].pushback(u);
		}
		
		int id, def, add;
		for(int i = 0; i < m; ++i)
		{
			scanf("%d%d%d", &id, &gw.def, &gw.add);
			gws[id].push_back(gw);
		}



		

	}
    
    return 0;
}
//Last modified :  2016-04-10 16:23 CST
