#include<cstdio>
#include<cstring>
using namespace std;
const int N = 10005;
int vis[N];

int main()
{
    int cnt, n, k;
    while(~scanf("%d%d", &n, &k))
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; !vis[i]; i = (i + k) % n) vis[i] = 1;
        for(int i = 0; i < n; ++i)
            if(!vis[i]) ++cnt;
        printf("%d\n", cnt);
    }
    return 0;
}
