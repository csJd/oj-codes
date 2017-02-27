#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=30,M=1000;
int par[N],n,m,ans;
struct edge{int u,v,w;} e[M];
bool cmp(edge a,edge b) {return a.w<b.w;}

int Find(int x)
{
    int r=x,tmp;
    while(par[r]>=0) r=par[r];
    while(x!=r)
    {
        tmp=par[x];
        par[x]=r;
        x=tmp;
    }
    return r;
}

void Union (int u,int v)
{
    int ru=Find(u),rv=Find(v),tmp=par[ru]+par[rv];
    if(par[ru]<par[rv])
        par[rv]=ru,par[ru]=tmp;
    else
        par[ru]=rv,par[rv]=tmp;
}

void kruskal()
{
    memset(par,-1,sizeof(par));
    int cnt=0;
    for(int i=1;i<=m;++i)
    {
        int u=e[i].u,v=e[i].v;
        if(Find(u)!=Find(v))
        {
            ++cnt;
            ans+=e[i].w;
            Union(u,v);
        }
        if(cnt>=n-1) break;
    }
}

int main()
{
    char s[2]; int t,tt;
    while(scanf("%d",&n),n)
    {
        m=0;
        for(int i=1;i<n;++i)
        {
            scanf("%s%d",s,&t);
            for(int j=1;j<=t;++j)
            {
                scanf("%s%d",s,&tt);
                e[++m].u=i,e[m].v=s[0]-'A'+1,e[m].w=tt;
            }
        }

        sort(e+1,e+m+1,cmp);
        ans=0; kruskal();
        printf("%d\n",ans);
    }
    return 0;
}
