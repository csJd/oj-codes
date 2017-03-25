#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll get5(ll n)
{
    ll ret = 0;
    while(n)
    {
        ret += n / 5;
        n /= 5;
    }
    return ret;
}

int main()
{
    int op, cas = 0;
    ll n, ans;
    while(~scanf("%d%I64d", &op, &n))
    {
        printf("Case %d:\n", ++cas);
        if(op == 1)
        {
            ans = get5(n);
            printf("%I64d\n", ans);
        }

        else
        {
            ll le = 0, ri = 1e10, mid;
            while(le <= ri)
            {
                mid = (le + ri) >> 1;
                if(get5(mid) >= n)
                    ri = mid - 1;
                else le = mid + 1;
            }
            if(get5(ri + 1) == n)
                printf("%I64d\n", ri + 1);
            else puts("No solution");
        }
    }
    return 0;
}
//Last modified :  2015-08-11 13:25 CST

