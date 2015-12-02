#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
LL m[N], n, b;

LL getn(LL t)
{
    LL ret = 0;
    for(int i = 0; i < b; ++i)
        ret += t / m[i] + (t % m[i] != 0);
    return ret;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int cas, ans;
    scanf("%d", &cas);
    for(int k = 1; k <= cas; ++k)
    {
        scanf("%lld%lld", &b, &n);
        for(int i = 0; i < b; ++i)
            scanf("%lld", &m[i]);

        LL le = 1, ri = n * 1e5, mid;
        while(le <= ri)
        {
            mid = (le + ri) >> 1;
            if(getn(mid) < n) le = mid + 1;
            else ri = mid - 1;
        }

        le =n - getn(ri++);
        for(ans = 0; ans < b && le; ++ans)
            if(ri % m[ans] == 1 || m[ans] == 1) --le;
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}

