#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=505;
const double INF=1000000;
int x[N],y[N],p;
double dis[N][N],cost[N],ans[N];

void prim()
{
    for(int i=0;i<=p;++i) cost[i]=INF;
    cost[1]=-1;
    int cur=1,next=ans[1]=0;
    for(int i=1;i<p;++i)
    {
        for(int j=1;j<=p;++j)
        {
            if(cost[j]<0) continue;
            if(dis[cur][j]<cost[j]) cost[j]=dis[cur][j];
            if(cost[j]<cost[next]) next=j;
        }
        ans[next]=cost[next];
        cur=next,next=0,cost[cur]=-1;
    }
}

int main()
{
    int cas,s;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d%d",&s,&p);
        for(int i=1;i<=p;++i)
            scanf("%d%d",&x[i],&y[i]);

        for(int i=1;i<=p;++i)
            for(int j=1;j<i;++j)
                dis[i][j]=dis[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));

        prim();
        sort(ans+1,ans+p+1);
        if(s==0) printf("%.2f\n",ans[p]);
        else printf("%.2f\n",ans[p+1-s]);
    }

    return 0;
}
