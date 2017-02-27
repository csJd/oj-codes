#include <cstdio>
#include <cstring>
using namespace std;
const int N = 205;
int tp[N][N], in[N], ans[N], n, out[N];

int topoSort()
{
    int cnt = n;
    for(int i = n; i >= 1; --i)
    {
        for(int j = n; j >= 1; --j)
        {
            if(in[j] == 0)
            {
                in[j] = -1;
                ans[cnt--] = j;
                for(int k = 1; k <= n; ++k)
                    if(tp[j][k]) --in[k];
                break;
            }
        }
    }
    return cnt;
}

int main()
{
    int T, m, a, b;
    scanf("%d", &T);
    while(T--)
    {
        memset(tp, 0, sizeof(tp));
        memset(in, 0, sizeof(in));

        scanf("%d%d", &n, &m);
        while(m--)
        {
            scanf("%d%d", &a, &b);
            if(!tp[b][a])
            {
                tp[b][a] = 1;
                ++in[a];
            }
        }

        if(topoSort()) puts("-1");
        else
        {
            for(int i = 1; i <= n; ++i)
                out[ans[i]] = i;
            for(int i = 1; i <= n; ++i)
                printf("%d%c", out[i], i < n ? ' ' : '\n');
        }
    }

    return 0;
}
//Last modified :  2015-08-24 19:47 CST

