#include<cstdio>
#include<cstring>
using namespace std;
const int N = 205, M = 1005;
int mat[N][N], v[N], d[N], n, m, s, t;

void dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    for(int i = d[s] = 0; i < n; ++i)
    {
        int cur=n;   //d[n]��INF,curΪ��ǰδ����ҵ�s������С�ĵ�
        for(int j = 0; j < n; ++j)
            if(!v[j] && d[j] < d[cur]) cur = j;

        v[cur] = 1; if(cur == t) return;
        for(int j = 0; j < n; ++j)
        {
            if(d[j] > d[cur] + mat[cur][j])
                d[j] = d[cur] + mat[cur][j];
        }
    }
}

int main()
{
    int a, b, x;
    while(~scanf("%d%d", &n, &m))
    {
        memset(mat, 0x3f, sizeof(mat));
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &a, &b, &x);
            if(mat[a][b]>x)   //ע��·�������ж���
                mat[a][b] = mat[b][a] = x;
        }

        scanf("%d %d", &s, &t);
        dijkstra();
        if(d[t] >= d[n]) printf("-1\n");
        else printf("%d\n", d[t]);
    }
    return 0;
}
