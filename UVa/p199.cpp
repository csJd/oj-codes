#include<cstdio>
#include<cstring>
using namespace std;
const int M = 1000003;
int x[4] = { -1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
int dis[M], h[M], s[M][9], e[9];

int aton(int a[])
{
    int t = 0;
    for(int i = 0; i < 9; ++i)
        t = t * 10 + a[i];
    return t;
}

int search_hash(int a[])
{
    int t = aton(a), p = t % M;
    while(h[p])
    {
        if(h[p] == t) return p;
        ++p;
        if(p >= M) p = 0;
    }
    return p;
}

int bfs()
{
    memset(h, 0, sizeof(h));
    int fro = 1, rear = 2, r, c, k = 0, p;
    int t[9], tmp, cur, nr, nc, nk;

    while(fro < rear)
    {
        memcpy(t, s[fro], sizeof(t));
        cur = search_hash(t);
        if(memcmp(t, e, sizeof(t)) == 0) return dis[cur];
        for(k = 0; t[k];) ++k;
        r = k / 3, c = k % 3;
        for(int i = 0; i < 4; ++i)
        {
            memcpy(t, s[fro], sizeof(t));
            nr = r + x[i], nc = c + y[i], nk = nr * 3 + nc;
            if(nr < 0 || nr > 2 || nc < 0 || nc > 2) continue;
            tmp = t[nk];
            t[nk] = 0;
            t[k] = tmp;
            p = search_hash(t);
            if(h[p] == 0)
            {
                h[p] = aton(t);
                dis[p] = dis[cur] + 1;
                memcpy(s[rear], t, sizeof(t));
                ++rear;
            }
        }
        ++fro;
    }
    return -1;
}

int main()
{
    while(~scanf("%d", &s[1][0]))
    {
        memset(dis, 0, sizeof(dis));
        for(int i = 1; i < 9; ++i)
            scanf("%d", &s[1][i]);
        for(int i = 0; i < 9; ++i)
            scanf("%d", &e[i]);
        h[aton(s[1]) % M] = aton(s[1]);
        int ans = bfs();
        if(ans != -1)
            printf("%d\n", ans);
        else  printf("No solution\n");
    }
    return 0;
}
/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
2 3 4 1 5 0 7 6 8
1 2 3 4 5 6 7 8 0
*/
