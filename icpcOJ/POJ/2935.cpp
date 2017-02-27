#include <cstdio>
#include <cstring>
using namespace std;
const int N = 8, M = 50;
int g[2][N][N], vis[N][N];
int sx, sy, ex, ey;
char sdir[] = "NSWE";

struct State
{
    int x, y, dir, pre;
    State() {}
    State(int a, int b, int d, int p)
        : x(a), y(b), dir(d), pre(p) {}
} q[M];

void print(int i)
{
    if(q[i].pre != -1)
    {
        print(q[i].pre);
        putchar(sdir[q[i].dir]);
    }
}

void bfs()
{
    int front = 0, rear = 0, x, y;
    q[rear++] = State(sx, sy, -1, -1);
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;
    while(front < rear)
    {
        x = q[front].x, y = q[front].y;
        if(x == ex && y == ey)
        {
            print(front);
            puts("");
            return;
        }
        if(x > 1 && !g[0][x - 1][y] && !vis[x - 1][y])
            vis[x - 1][y] = 1, q[rear++] = State(x - 1, y, 0, front);
        if(x < 6 && !g[0][x][y] && !vis[x + 1][y])
            vis[x + 1][y] = 1, q[rear++] = State(x + 1, y, 1, front);
        if(y > 1 && !g[1][x][y - 1] && !vis[x][y - 1])
            vis[x][y - 1] = 1, q[rear++] = State(x, y - 1, 2, front);
        if(y < 6 && !g[1][x][y] && ! vis[x][y + 1])
            vis[x][y + 1] = 1, q[rear++] = State(x, y + 1, 3, front);
        ++front;
    }
}

int main()
{
    int x1, y1, x2, y2;
    while(scanf("%d%d", &sy, &sx), sy)
    {
        memset(g, 0, sizeof(g));
        scanf("%d%d", &ey, &ex);
        for(int i = 0; i < 3; ++i)
        {
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            if(x1 == x2)
            {
                for(int j = y2; j > y1; --j)
                    g[0][x1][j] = 1;
            }
            else
            {
                for(int i = x2; i > x1; --i)
                    g[1][i][y1] = 1;
            }
        }
        bfs();
    }
    return 0;
}
//Last modified :  2015-08-19 18:35 CST

