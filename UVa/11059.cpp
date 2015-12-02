#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
    ll ans, t;
    int n, a[30], cas = 0;
    while(~scanf("%d", &n))
    {
        //if(cas++) printf("\n");
        ans = 0;
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
            {
                t = 1;
                for(int k = i; k <= j; ++k)
                    t *= a[k];
                if(t > ans) ans = t;
            }
        printf("Case #%d: The maximum product is %lld.\n\n", ++cas, ans);
    }
    return 0;
}
