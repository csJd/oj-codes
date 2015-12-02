#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 105;
char g[N][N];
int v[N][N],n,m,k,ans;
int x[4] = {-1,1,0,0};
int y[4] = {0,0,-1,1};
struct point
{
    int r,c,d;
    point(int rr = 0,int cc = 0,int dd = 0)
    {
        r = rr;
        c = cc;
        d = dd;
    }
} p;

bool bfs(int i, int j)
{
    int cnt,cr,cc,tr,tc,td;
    memset(v,0,sizeof(v));
    queue<point> q;
    q.push(point(i,j,0));
    v[i][j] = 1;

    cnt = 0;
    ans = 0;

    while(!q.empty() && cnt < k)
    {
        tr = q.front().r, tc = q.front().c, td = q.front().d;
        q.pop();
        for(int k = 0; k < 4; ++k)
        {
            cr = tr + x[k], cc = tc + y[k];
            if(cr>=0 && cr<n && cc>=0 && cc<m && g[cr][cc]!='#' && !v[cr][cc])
            {
                if(g[cr][cc] >= '0' && g[cr][cc] <='9')
                {
                    g[cr][cc] = '.';
                    ans += td + 1;
                    ++cnt;

                    while(!q.empty()) q.pop();
                    memset(v,0,sizeof(v));

                    v[cr][cc] = 1;
                    q.push(point(cr,cc,0));
                    break;
                }
                v[cr][cc] = 1;
                q.push(point(cr,cc,td+1));
            }
        }
    }
    return cnt == k;
}


int main()
{
    int si,sj;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i = 0; i<n; ++i)
        {
            scanf("%s", g[i]);
            for(int j = 0; j<m; ++j)
                if(g[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
        }
        ans = 0;
        if(bfs(si,sj)) printf("%d\n",ans);
        else puts("bengkala");
    }
    return 0;
}


