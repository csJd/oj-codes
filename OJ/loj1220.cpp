#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 100005;
int pme[N], m;
bool vis[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void initPrime()
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
    int T, cas = 0;
    ll n;
    scanf("%d", &T);
    while(T--)
    {
        bool flag = 0;  //标记n是否为负数
        scanf("%lld", &n);
        if(n < 0) flag = 1, n = -n;

        int ans = 0, cnt;
        for(int i = 0; i < m; ++i)
        {
            if(ans == 1 || ll(pme[i]) * pme[i] > n) break;
            cnt = 0;
            while(n % pme[i] == 0)
            {
                ++cnt;
                n /= pme[i];
            }
            if(!ans) ans = cnt;
            if(cnt) ans = gcd(ans, cnt);
        }
        if(n > 1 || !ans) ans = 1;

        while(flag && ans % 2 == 0) ans /= 2;
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
//Last modified :  2015-08-07 10:49 CST

