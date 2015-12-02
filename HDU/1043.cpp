#include <bits/stdc++.h>
using namespace std;
const int N = 5e5, M = 9;
int x[4] = { -1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int puz[N][M], nex[N], dir[N], vis[N], q[N];

int getCantor(int a[])  //康托展开  将排列转化为整数
{
    int ret = 0;
    for(int i = 0; i < M; ++i)
    {
        for(int j = i + 1; j < M; ++j)
            if(a[j] < a[i]) ret += fac[M - i - 1];
    }
    return ret;
}

void bfs()
{
    int t[M] = {1, 2, 3, 4, 5, 6, 7, 8, 0};
    int id = getCantor(t);
    dir[id] = -1;

    memcpy(puz[id], t, sizeof(t));
    memset(vis, 0, sizeof(vis));

    int r, c, k, nr, nc, nk, nid;
    int front = 0, rear = 0;
    q[rear++] = id;
    vis[id] = 1;

    while(front < rear)
    {
        int id = q[front++];
        memcpy(t, puz[id], sizeof(t));
        for(k = 0; t[k]; ++k);  //找0的位置
        r = k / 3, c = k % 3;  //一维转二维

        for(int i = 0; i < 4; ++i)
        {
            nr = r + x[i], nc = c + y[i], nk = nr * 3 + nc;

            if(nr < 0 || nr > 2 || nc < 0 || nc > 2) continue;
            swap(t[k], t[nk]);
            nid = getCantor(t);
            memcpy(puz[nid], t, sizeof(t));
            swap(t[k], t[nk]);

            if(vis[nid]) continue;
            vis[nid] = 1;
            q[rear++] = nid;
            nex[nid] = id;
            dir[nid] = i;
        }
    }
}

int main()
{
    char t[5], sdir[] = "durl";
    int s[M], id;
    bfs();

    while(~scanf("%s", t))
    {
        s[0] = t[0] == 'x' ? 0 : t[0] - '0';
        for(int i = 1; i < M; ++i)
        {
            scanf("%s", t);
            s[i] = t[0] == 'x' ? 0 : t[0] - '0';
        }

        id = getCantor(s);
        if(!vis[id]) puts("unsolvable");
        else
        {
            while(dir[id] >= 0)
            {
                printf("%c", sdir[dir[id]]);
                id = nex[id];
            }
            puts("");
        }
    }
    return 0;
}
//Last modified :   2015-07-05 11:15
