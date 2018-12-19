#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005, M = 10;
int d[M], vis[N], n, m;

struct data
{
    int num, mod, pre;
    data() {}
    data(int nu, int mo, int p)
        : num(nu), mod(mo), pre(p) {}
} q[N];

void print(int p)
{
    if(q[p].pre != p)
    {
        print(q[p].pre);
        printf("%d", q[p].num);
    }
}

void bfs()
{
    memset(vis, 0, sizeof(vis));
    int front = 0, rear = 0, cm, nm;
    q[rear++] = data(0, 0, 0);
    while(front < rear)
    {
        cm = q[front++].mod;
        if(!cm && front > 1)
        {
            print(front - 1);
            puts("");
            return;
        }

        for(int i = 0; i < m; ++i)
        {
            if(front == 1 && d[i] == 0) continue;
            nm = (cm * 10 + d[i]) % n;
            if(!vis[nm])  //余数判重
            {
                vis[nm] = 1;
                q[rear++] = data(d[i], nm, front - 1);
            }
        }
    }
    puts("0");
}

int main()
{
    while(~scanf("%d", &n))
    {
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
            scanf("%d", &d[i]);
        sort(d, d + m);
        if(n) bfs();
        else puts("0");

    }
    return 0;
}
//Last modified :   2015-08-03 16:56

