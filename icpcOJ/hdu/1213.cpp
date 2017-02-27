#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int par[N];

int find(int x)
{
	int r = x, tmp;
	while(par[r] >= 0) r = par[r];
	while(x!=r)
	{
		tmp = par[x];
		par[x] = r;
		x = tmp;
	}
	return r;
}

void merge(int u, int v)
{
	int ru = find(u), rv = find(v), tmp = par[ru] + par[rv];
	if(ru == rv) return;
	if(par[ru] < par[rv]) par[rv] = ru, par[ru] = tmp;
	else par[ru] = rv, par[rv] = tmp;
}

int main()
{
	int T, n, m, a, b, ans;
	scanf("%d",&T);
	while(T--)
	{
		memset(par, -1, sizeof(par));
		scanf("%d%d",&n, &m);
		while(m--)
		{
			scanf("%d%d",&a, &b);
			merge(a, b);
		}
		ans = 0;
		for(int i =1; i<=n; ++i) if(par[i]<0) ++ans;
		printf("%d\n",ans);
	}
    return 0;
}
//Last modified :   2015-07-06 16:02
