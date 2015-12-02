#include<cstdio>
#include<cstring>
using namespace std;
const int N = 100;
int a[N], b[N], cas, n, m;
int main()
{
    float sa, sb;
    scanf("%d", &cas);
    while(cas--)
    {
        sa = sb = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i < n; ++i)
            scanf("%d", &a[i]), sa += a[i];
        for(int i = 1; i <= m; ++i)
            scanf("%d", &b[i]), sb += b[i];
        sa/=(n-1),sb/=m;
        for(int i = 1; i <= 100; ++i)
            if(i > sb)
            {
                printf("%d ", i);
                break;
            }
        for(int i = 100; i >= 1; --i)
            if(i < sa)
            {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}
