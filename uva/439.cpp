#include <bits/stdc++.h>
using namespace std;
int x[] = { -2, -1, -2, -1, 1, 2, 1, 2};
int y[] = { -1, -2, 1, 2, -2, -1, 2, 1};
int d[15][15], sx, sy, ex, ey;
pair<int, int> q[105], t;

int bfs()
{
    int cx, cy, r, c, front = 0, rear = 0;
    memset(d, -1, sizeof(d));
    d[sx][sy] = 0;
    q[rear++] = make_pair(sx, sy);
    while(front < rear)
    {
        t = q[front++];
        cx = t.first, cy = t.second;
        if(cx == ex && cy == ey) return d[cx][cy];
        for(int i = 0; i < 8; ++i)
        {
            r = cx + x[i], c = cy + y[i];
            if(r < 0 || r > 7 || c < 0 || c > 7 || d[r][c] >= 0) continue;
            d[r][c] = d[cx][cy] + 1;
            q[rear++] = make_pair(r, c);
        }
    }
}

int main()
{
    char a[5], b[5];
    while(~scanf("%s%s", a, b))
    {
        sx = a[0] - 'a', sy = a[1] - '1';
        ex = b[0] - 'a', ey = b[1] - '1';
        printf("To get from %s to %s takes %d knight moves.\n", a, b, bfs());
    }
    return 0;
}
