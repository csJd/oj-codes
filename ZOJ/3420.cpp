#include <bits/stdc++.h>
using namespace std;
const int N = 6, M = 1e6;
int ma[N][N], mb[N][N], n = 6;
bool vis[N][N][N][N];
char dirt[] = "UDLR";

struct state
{
    int ai, aj, bi, bj, pre, dir;
    state() {}
    state(int ar, int ac, int br, int bc, int p, int d):
        ai(ar), aj(ac), bi(br), bj(bc), pre(p), dir(d) {}
} q[M];

bool check(int ar, int ac, int br, int bc)
{
    if(ar < 0 || ar > 5 || ac < 0 || ac > 5) return false;
    if(br < 0 || br > 5 || bc < 0 || bc > 5) return false;
    if(vis[ar][ac][br][bc]) return false;
    return vis[ar][ac][br][bc] = ma[ar][ac] & mb[br][bc] & 1 << 4;
}

void print(int i)
{
    if(q[i].pre >= 0)
    {
        print(q[i].pre);
        putchar(dirt[q[i].dir]);
    }
}

void bfs(int ar, int ac, int br, int bc)
{
    state cur;
    int front = 0, rear = 0;
    int ai, aj, bi, bj, pre;
    q[rear++] = state(ar, ac, br, bc, -1, -1);
    memset(vis, 0, sizeof(vis));
    vis[ar][ac][br][bc] = true;
    while(front < rear)
    {
        cur = q[front++];
        ai = cur.ai, aj = cur.aj;
        bi = cur.bi, bj = cur.bj;
        pre = front - 1;

        if(ma[ai][aj] & mb[bi][bj] & 1 << 6)  //µ½´ïÖÕµã
        {
            print(pre);
            puts("");
            return;
        }

        if(!(ma[ai][aj] & mb[bi][bj] & 1 << 1)) //down
        {
            ar = ma[ai][aj] & 1 << 1 ? ai : ai + 1;
            br = mb[bi][bj] & 1 << 1 ? bi : bi + 1;
            if(check(ar, aj, br, bj))
                q[rear++] = state(ar, aj, br, bj, pre, 1);
        }

        if(!(ma[ai][aj] & mb[bi][bj] & 1)) //left
        {
            ac = ma[ai][aj] & 1 ? aj : aj - 1;
            bc = mb[bi][bj] & 1 ? bj : bj - 1;
            if(check(ai, ac, bi, bc))
                q[rear++] = state(ai, ac, bi, bc, pre, 2);
        }

        if(!(ma[ai][aj] & mb[bi][bj] & 1 << 2)) //right
        {

            ac = ma[ai][aj] & 1 << 2 ? aj : aj + 1;
            bc = mb[bi][bj] & 1 << 2 ? bj : bj + 1;
            if(check(ai, ac, bi, bc))
                q[rear++] = state(ai, ac, bi, bc, pre, 3);
        }

        if(!(ma[ai][aj] & mb[bi][bj] & 1 << 3)) //up
        {
            ar = ma[ai][aj] & 1 << 3 ? ai : ai - 1;
            br = mb[bi][bj] & 1 << 3 ? bi : bi - 1;
            if(check(ar, aj, br, bj))
                q[rear++] = state(ar, aj, br, bj, pre, 0);
        }
    }
    puts("-1");
}

int main()
{
    int T, ar, ac, br, bc;
    scanf("%d", &T);
    for(int k = 0; k < T; ++k)
    {
        int (&cur)[N][N] = k % 2 ? mb : ma;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &cur[i][j]);
                if(k % 2 == 0 && cur[i][j] & 1 << 5) ar = i, ac = j;
                if(k % 2 && cur[i][j] & 1 << 5) br = i, bc = j;
            }
        }

        if(k) bfs(ar, ac, br, bc);

    }
    return 0;
}
//Last modified :   2015-07-30 08:20

