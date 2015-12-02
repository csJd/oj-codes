#include <bits/stdc++.h>
using namespace std;
const int N=10005,INF=0x3f3f3f;
int g[N][N],v[N],d[N];
int n,m,k,t;

int dijkstra(int dis)
{
	memset(d,0x3f,sizeof(d));
	int cur=d[1]=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j) if(!v[j]&&d[j]<d[cur]) cur=j;
		v[cur]=1;
		if(cur==t) return d[cur];
		for(int j=1;j<=n;++j)
			if(!v[j]&&g[cur][j]<=dis) d[j]=d[cur]+1;
		cur=0;
	}
	return d[0];
}


int main()
{
	int a,b,c,l,r,mid;
	while(~scanf("%d%d%d%d",&n,&m,&k,&t))
	{
		while(m--) 
		{
			scanf("%d%d%d",&a,&b,&c);
			if(g[a][b]>c) g[a][b]=g[b][a]=c;
		}
		l=1,r=k;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(dijkstra(mid)<=k) r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",r+1);
	}	
    return 0;
}
