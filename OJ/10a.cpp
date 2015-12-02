#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100005;
int vis[N], ans[N];

int main()
{
    int n, d, x, p;
    while(~scanf("%d%d", &n, &d))
    {
        memset(vis, -1, sizeof(vis));
        char out[N] = {0};
        sprintf(out, "%d.", n / d);
        int k = strlen(out);

        p = 0;
        n = n % d;
        while(n && vis[n] >= 0)
        {
            vis[n] = p;
            ans[p++] = n * 10 / d;
            n = n * 10 % d;
        }

        for(int i = 0; i < p; ++i)
        {
            if(i == vis[n]) out[k++] = '(';
            out[k++] = '0' + ans[i];
        }
        if(n) out[k++] = ')';
        puts(out);
    }
    return 0;
}
//Last modified :  2015-08-11 15:19 CST

