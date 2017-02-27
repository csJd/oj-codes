#include<cstdio>
#include<cstring>
using namespace std;
const int M = 1000003;
int e[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int x[4] = { -1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
int dir[M], pre[M], h[M], s[M][9];
char pri[5] = "udlr";

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

void print(int p)
{
    if(pre[p])
    {
        print(pre[p]);
        printf("%c", pri[dir[p]]);
    }
}

int bfs()
{
    memset(h, 0, sizeof(h));
    h[aton(s[1]) % M] = aton(s[1]);
    int fro = 1, rear = 2, r, c, k = 0, nr, nc, nk, p;
    int t[9], tmp, cur;

    while(fro < rear)
    {
        memcpy(t, s[fro], sizeof(t));
        cur = search_hash(t);
        if(memcmp(t, e, sizeof(t)) == 0) return cur;
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
                dir[p] = i;
                pre[p] = cur;
                memcpy(s[rear], t, sizeof(t));
                ++rear;
            }
        }
        ++fro;
    }
    return 0;
}

int main()
{
    char c;
    while(~scanf("%d", &s[1][0]))
    {
        memset(dir, 0, sizeof(dir));
        memset(pre, 0, sizeof(pre));
        for(int i = 1; i < 9; ++i)
        {
            scanf(" %c", &c);
            if(c == 'x') s[1][i] = 0;
            else s[1][i] = c - '0';
        }
        int ans = bfs();
        if(ans) print(ans);
        else  printf("unsolvable");
        printf("\n");
    }
    return 0;
}
/*
2 3 4 1 5 0 7 6 8
*/
