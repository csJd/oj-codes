#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 200005;
int goal[N], cmp[N], n, m, s;

bool ok(int k)
{
    int i = cmp[0] = 1, j = 0;
    while(i < n)
    {
        if((k & (1 << i)) ^ (k & (1 << (i - 1))))
        {
            printf("******   %d  %d\n", cmp[j], goal[j]);
            if(cmp[j] != goal[j])
            {
                return false;
            }
            cmp[++j] = 1;
        }
        else ++cmp[j];
        ++i;
    }
    return true;
}

int bfs()
{
    int q[N], vis[N], cur;
    int front = 0, rear = 0;
    memset(vis, 0, sizeof(vis));
    q[rear++] = s;
    vis[s] = 1;
    while(front < rear)
    {
        cur = q[front++];

//        printf("%d\n", vis[cur]);
        if(ok(cur)) return vis[cur] - 1;
        else
        {
            for(int i = 0; i < n; ++i)
                printf("%d ", cur & 1 << i ? 1 : 0);
            puts("");
        }
        for(int i = 0; i < n - 1; ++i)
        {
            if((cur & (1 << i)) ^ (cur & (1 << (i + 1))))
            {
                int k = cur ^ (3 << i);

                if(!vis[k])
                {
//                    for(int i = 0; i < n; ++i)
//                    printf("%d ",k & 1<<i ? 1 : 0);
//                puts("");


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

