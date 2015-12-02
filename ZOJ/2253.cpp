#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=205;
double d[N][N];
int x[N],y[N],n;

void floyd()
{
    for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
        d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
}

int main()
{
    int cas=0;
    while(scanf("%d",&n),n)
    {
        memset(d,0x3f,sizeof(d));
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=1;j<i;++j)
            {
                int tx=x[i]-x[j],ty=y[i]-y[j];
                d[i][j]=d[j][i]=sqrt(tx*tx+ty*ty);
            }
        }
        floyd();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++cas,d[1][2]);
    }
    return 0;
}
