#include <bits/stdc++.h>
using namespace std;
const int M = 100005,INF=1000005;
struct node{
	int v,l;
	node* nex;
};
node* g[M];
int n, m, k, t, d[M], v[M];

void ist(int u,int v,int l)
{
	node *p=g[u];
	while(p=p->nex) if(p->v==v) break;
	if(p) p->l=min(p->l, l);
	else
	{
		p = new node;
		p->v=v,p->l=l;
		p->nex=g[u]->nex;
		g[u]->nex=p;
	}
}

int dijkstra(int k)
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	int cur = d[1]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=1;j<=n;++j)
			if(!v[j] && d[j] < d[cur]) cur = j;
		v[cur]=1;
		if(cur == t) return d[cur];
		node *p= g[cur];
		while(p=p->nex)
		{
			if(p->l <= k) d[p->v] = min(d[p->v],d[cur]+1);
		}
	}
	return d[0];
}

int main()
{
	int a, b, c, l, r, mid;
	while(~scanf("%d%d%d%d",&n,&m,&k,&t))
	{
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			ist(a,b,c),ist(b,a,c);
		}
		l=0,r=INF;
		while(l<=r)
		{
			mid = (l+r)>>1;
			if(dijkstra(mid)<=k) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",r+1);
	}
	return 0;
}
