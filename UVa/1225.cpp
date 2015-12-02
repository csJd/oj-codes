#include <cstdio>
#include <cstring>
using namespace std;
int cnt[10];
int main()
{
    int cas, t, n;
    scanf("%d", &cas);
    while(cas--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            t = i;
            while(t) ++cnt[t % 10], t /= 10;
        }
        for(int i = 0; i < 9; ++i) printf("%d ", cnt[i]);
        printf("%d\n", cnt[9]);
    }
    return 0;
}
