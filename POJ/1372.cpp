#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1005;
int c[N];

int main()
{
    int cas, n, s, a, ans;
    scanf("%d", &cas);
    while(cas--)
    {
        ans = 0;
        memset(c, 0, sizeof(c));
        scanf("%d %d", &n, &s);
        for(int i = 1; i < n; ++i)
        {
            scanf("%d", &a);
            if(a != s) ++c[a];
            if(c[a] > 1) ++ans;
        }
        if(ans) printf("%d\n", ans);
        else printf("*^___^*\n");

    }
    return 0;
}
