#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 105, M = 1e6;
int d[N], lh, ls, n;
bool vis[300][N][50];

struct state
{
    int hp, sp, n, t;
    state() {}
    state(int h, int s, int nn, int tt)
        : hp(h), sp(s), n(nn), t(tt) {}
} q[M];

void bfs()
{
    memset(vis, 0, sizeof(vis));
    int front = 0, rear = 0;
    state c(lh, 0, n, 0);
    q[rear++] = c;
    vis[lh][0][n] = 1;
    int hp, sp, t, nh, ns, nn;
    while(front < rear)
    {
        c = q[front++];
        hp = c.hp, sp = c.sp, n = c.n, t = c.t + 1;
        if(n <= 0)
        {
            printf("%d\n", t - 1);
            return;
        }

        if(hp >= n) //打死一个敌人
        {
            nn = n - 1;
            nh = hp - nn;
            ns = min(ls, sp + 1 + nn % 3);
            if(!vis[nh][ns][nn])
            {
                vis[nh][ns][nn] = 1;
                q[rear++] = state(nh, ns, nn, t);
            }
        }

        if(hp < lh) //加血
        {
            nh = min(lh, hp + lh / 5) - n;
            ns = min(ls, sp + n % 3);
            if(nh > 0 && !vis[nh][ns][n])
            {
                vis[nh][ns][n] = 1;
                q[rear++] = state(nh, ns, n, t);
            }
        }

        if(sp > 0) //用魔法
        {
            nn = max(0, n - d[sp]);
            nh = hp - nn;
            ns = min(ls, nn % 3);
            if(nh > 0 && !vis[nh][ns][nn])
            {
                vis[nh][ns][nn] = 1;
                q[rear++] = state(nh, ns, nn, t);
            }
        }
    }

    puts("HELP!");
}

int main()
{
    while(~scanf("%d%d%d", &lh, &ls, &n))
    {
        for(int i = 1; i <= ls; ++i)
            scanf("%d", &d[i]);
        bfs();
    }
    return 0;
}
//Last modified :   2015-07-29 09:46

