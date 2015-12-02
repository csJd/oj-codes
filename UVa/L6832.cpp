#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int M = 66000, N = 20;
int goal[N], cmp[N], n, m, s;
int vis[M], q[M];

bool ok(int k)
{
    int i = cmp[0] = 1, j = 0;
    while(i < n)
    {
        if(((k >> i) & 1) != ((k >> (i - 1)) & 1))
        {
            //printf("******   %d  %d\n", cmp[j], goal[j]);
            if(cmp[j] != goal[j]) return false;
            cmp[++j] = 1;
        }
        else ++cmp[j];
        ++i;
    }
    return cmp[j] == goal[j];
}

int bfs()
{
    int front = 0, rear = 0, cur;
    memset(vis, 0, sizeof(vis));
    q[rear++] = s;
    vis[s] = 1;
    while(front < rear)
    {
        cur = q[front++];

//        for(int i = 0; i < n; ++i)
//            printf("%d ", cur & 1 << i ? 1 : 0);
//        printf("   dis = %d\n", vis[cur]);

        if(ok(cur)) return vis[cur] - 1;
        for(int i = 0; i < n - 1; ++i)
        {
            //if(((cur & (1 << i) == 0)) ^ ((cur & (1 << (i + 1))) == 0))
            if(((cur >> i) & 1) != ((cur >> (i + 1)) & 1))
            {
                int k = cur ^ (3 << i);

                if(!vis[k])
                {
                    vis[k] = vis[cur] + 1;
                    q[rear++] = k;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int b;
    while(~scanf("%d%d", &n, &m))
    {
        s = 0;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &b);
            if(b) s += (1 << i);
        }
        for(int i = 0; i < m; ++i)
            scanf("%d", &goal[i]);

        printf("%d\n", bfs());
    }
    return 0;
}
//Last modified :  2015-10-15 20:15 CST

