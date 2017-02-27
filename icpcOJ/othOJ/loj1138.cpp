#include <bits/stdc++.h>
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
    int T, q, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &q);
        ll le = 5, ri = 1e10, mid;
        while(le <= ri)
        {
            mid = (le + ri) / 2;
            if(get5(mid) < q) le = mid + 1;
            else ri = mid - 1;
        }
        printf("Case %d: ", ++cas);
        if(get5(ri + 1) == q) printf("%d\n", ri + 1);
        else puts("impossible");
    }

    return 0;
}
//Last modified :  2015-08-07 16:04 CST

