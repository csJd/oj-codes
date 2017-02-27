#include<cstdio>
#include<cstring>
using namespace std;
const int N = 505;
int d[N], v[N], mat[N][N], n, m;

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[1] = 0;
    for(int i =  1; i <= n; ++i)
    {
        int cur = 0;
        for(int j = 1; j <= n; ++j)
            if(!v[j] && d[j] < d[cur]) cur = j;
        v[cur] = 1;
        for(int j = 1; j <= n; ++j)
            if(d[j] > d[cur] + mat[cur][j])
                d[j] = d[cur] + mat[cur][j];
    }
}

int main()
{
    int pi, pj, ans, a, b, c, cas = 0;
    while(scanf("%d%d", &n, &m), n)
    {
        memset(mat, 0x3f, sizeof(mat));
        for(int i = 1; i <= n; ++i) mat[i][i] = 0;
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            mat[a][b] = mat[b][a] = c;
        }
        dijkstra();

        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i; j <= n; ++j)
            {
                if(mat[i][j] >= d[0]) continue;
                if(d[i] + d[j] + mat[i][j] > ans || (i == j && 2 * d[i] >= ans))
                {
                    ans = d[i] + d[j] + mat[i][j];
                    pi = i, pj = j;
                }
            }
        }

        double t = ans / 2.0;
        printf("System #%d\nThe last domino falls after %.1f seconds, ", ++cas, t);
        if(pi == pj)  printf("at key domino %d.\n\n", pi);
        else   printf("between key dominoes %d and %d.\n\n", pi, pj);
    }
    return 0;
}
