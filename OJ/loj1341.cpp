#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

bool vis[N];
int pme[N / 10];

void initPrime()
{
    int m = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < N; ++i)
    {
        if(!vis[i]) pme[m++] = i;
        for(int j = 0; j < m && pme[j] * i < N; ++j)
        {
            vis[pme[j] * i] = 1;
            if(i % pme[j] == 0) break;
        }
    }
}

ll getFactor(ll n)
{
    ll ret = 1;
    int i = 0, cnt;
    while(n >= ll(pme[i]) * pme[i])
    {
        cnt = 0;
        while(n % pme[i] == 0)
        {
            ++cnt;
            n /= pme[i];
        }
        ret *= (cnt + 1);
        ++i;
    }
    if(n > 1) ret *= 2;
    return ret;
}


int main()
{
    initPrime();
    int T;
    ll a, b, ans;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%lld%lld", &a, &b);
        if(sqrt(a) <= b) ans = 0;
        else
        {
            ans = getFactor(a) / 2;
            for(int i = 1; i < b; ++i)
                if(a % i == 0) --ans;
        }
        printf("Case %d: %lld\n", cas, ans);
    }

    return 0;
}
//Last modified :   2015-08-05 18:59

