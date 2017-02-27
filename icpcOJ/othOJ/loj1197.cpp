#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int v[N], ans;
ll a, b, p[N];

void initPrime()
{
    int cnt = 0;
    for(int i = 2; i < N; ++i)
    {
        if(!v[i]) p[cnt++] = i;
        for(int j = 0; j < cnt && p[j] * i < N;  ++j)
        {
            v[p[j] * i] = 1;
            if(i % p[j] == 0) break;
        }
    }
}

int main()
{
    initPrime();
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%lld%lld", &a, &b);
        memset(v, 0, sizeof(v));
        if(a < 2) a = 2;
        for(int i = 0; p[i] * p[i] <= b; ++i)
        {
            for(ll j = a / p[i]; j * p[i] <= b; ++j)
                if(j > 1 && j * p[i] >= a) v[j * p[i] - a] = 1;
        }

        for(int i = ans = 0; i <= b - a; ++i) ans += !v[i];
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
//Last modified :   2015-07-10 20:17
