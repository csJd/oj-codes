#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7 + 5;
int pme[N / 10], m;
bool vis[N];

void initPrime() //线性筛
{
    m = 0;
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

int main()
{
    initPrime();
    ll n, ans, c;
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &n);
        ans = 1;
        for(int i = 0; i < m; ++i)
        {
            if(ll(pme[i])*pme[i] > n) break;
            c = 0;
            while( n % pme[i] == 0)
            {
                n /= pme[i];
                ++c;
            }
            if(c) ans *= c * 2 + 1;
        }
        if(n > 1) ans *= 3;

        printf("Case %d: %lld\n", ++cas, ans / 2 + 1);
    }

    return 0;
}
//Last modified :  2015-08-07 08:13 CST

