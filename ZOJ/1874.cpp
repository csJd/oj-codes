#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 300;
int mat[N][N], d[N], in[N], link[N][N], n, m, s;
queue<int> q;

void spfa()
{
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    memset(in, 0, sizeof(in));
    q.push(s), in[s] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop(),in[cur]=0;
        for(int k = 1; k <= link[cur][0]; ++k)
        {
            int tmp = link[cur][k];
            if(d[tmp] > d[cur] + mat[cur][tmp])
            {
                d[tmp] = d[cur] + mat[cur][tmp];
                if(!in[tmp]) in[tmp] = 1, q.push(tmp);
            }
        }
    }
}

int main()
{
    int a, b, c, t;
    while(~scanf("%d%d", &n, &m))
    {
        memset(mat, 0x3f, sizeof(mat));
        memset(link, 0, sizeof(link));
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(mat[a][b] > c) mat[a][b] = mat[b][a] = c;
        }
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] < mat[n][n])
                    link[i][++link[i][0]] = j;

        scanf("%d%d", &s, &t);
        spfa();
        if(d[t] == d[n]) d[t] = -1;
        printf("%d\n", d[t]);
    }
    return 0;
}
